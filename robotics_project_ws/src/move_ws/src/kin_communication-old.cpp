//
//  kin_communication.cpp
//  Kinematics
//
//  Created by Matteo Gottardelli on 04/12/24.
//

#include "kin_communication.h"
#include "complete_job.h"

TrajectoryActionClient::TrajectoryActionClient(MatrixD6 th, std::shared_ptr<rclcpp::Node> node) : Node("trajectory_publisher")
{
    // Create a publisher for the scaled joint trajectory controller
    origin_node=node;
    action_client_ = rclcpp_action::create_client<FollowJointTrajectory>(
        this, "/scaled_joint_trajectory_controller/follow_joint_trajectory");
    // Wait for the action server to be available
    while(!action_client_->wait_for_action_server(10s))
    {
        RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
    }
    publish_iter(th);
}

void TrajectoryActionClient::publish_iter(MatrixD6 Th)
{
    trajectory_msgs::msg::JointTrajectory traj_msg;
    init_Trajectory(&traj_msg);
    naming_Points(&traj_msg);
    int rows=Th.rows();
    for (int i=0; i<rows; i++) {
        trajectory_msgs::msg::JointTrajectoryPoint point;
        for (int j=0; j<NUM_JOINTS; j++) {
            point.positions.push_back(Th(i, j));
        }
        double t=i*DELTAT;
        point.time_from_start=rclcpp::Duration::from_seconds(t);
        add_point(&traj_msg, point);
    }
    trajectory_msgs::msg::JointTrajectoryPoint point;
    point.time_from_start=rclcpp::Duration::from_seconds(4.0);
    publish_trajectory(traj_msg);
}
void TrajectoryActionClient::init_Trajectory(trajectory_msgs::msg::JointTrajectory* traj_msg) {
    traj_msg->header.stamp=this->now();
    traj_msg->header.frame_id = "base_link";
    
}
string TrajectoryActionClient::chooseName(int index) {
    string tmp;
    switch(index) {
        case 0: tmp=SHOULDER_PAN; break;
        case 1: tmp=SHOULDER_LIFT; break;
        case 2: tmp=ELBOW; break;
        case 3: tmp=WRIST_1; break;
        case 4: tmp=WRIST_2; break;
        case 5: tmp=WRIST_3; break;
        default: exit(1);
    }
    return tmp;
}
void TrajectoryActionClient::naming_Points(trajectory_msgs::msg::JointTrajectory* traj_msg){
    for (int i=0; i<NUM_JOINTS; i++) {
        traj_msg->joint_names.push_back(chooseName(i));
     }
}
void TrajectoryActionClient::add_point(trajectory_msgs::msg::JointTrajectory* traj_msg, trajectory_msgs::msg::JointTrajectoryPoint p) {
    traj_msg->points.push_back(p);
}

std::string uuid_to_string(const std::array<uint8_t, 16>& uuid) {
    std::stringstream ss;
    for (size_t i = 0; i < uuid.size(); ++i) {
        if (i > 0) {
            ss << "-";
        }
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(uuid[i]);
    }
    return ss.str();
}

void TrajectoryActionClient::publish_trajectory(trajectory_msgs::msg::JointTrajectory traj_msg) {
    // Create a goal message for the action
    auto goal_msg = FollowJointTrajectory::Goal();
    goal_msg.trajectory = traj_msg;
    goal_msg.goal_time_tolerance.nanosec = 500000000;
    
    RCLCPP_INFO(this->get_logger(), "Sending trajectory with %zu points", goal_msg.trajectory.points.size());
    for (const auto &point : goal_msg.trajectory.points) {
        RCLCPP_INFO(this->get_logger(), "Point at time %d %d: %f %f %f %f %f %f",
                    point.time_from_start.sec, point.time_from_start.nanosec,
                    point.positions[0], point.positions[1],
                    point.positions[2], point.positions[3],
                    point.positions[4], point.positions[5]);
    }
    
    RCLCPP_INFO(this->get_logger(), "Sending trajectory goal");
    
    // Variable to store goal handle
    //GoalHandleFollowJointTrajectory::SharedPtr goal_handle = nullptr;
    
    // Send the goal to the action server
    auto send_goal_options = rclcpp_action::Client<FollowJointTrajectory>::SendGoalOptions();
    
    send_goal_options.goal_response_callback =
    [this](const GoalHandleFollowJointTrajectory::SharedPtr& goal_handle_response) {
        auto goal_handle=goal_handle_response;
        if (!goal_handle_response) {
            RCLCPP_ERROR(this->get_logger(), "Goal was rejected by the server");
        } else {
            RCLCPP_INFO(this->get_logger(), "Goal accepted by the server");
            // Get the Goal ID
            const auto& goal_id = goal_handle_response->get_goal_id();
            // Convert Goal ID to string
            try {
                std::string goal_id_str = uuid_to_string(goal_id);
                RCLCPP_INFO(this->get_logger(), "Goal ID: %s", goal_id_str.c_str());
            } catch (const std::exception& e) {
                RCLCPP_ERROR(this->get_logger(), "Failed to convert Goal ID to string: %s", e.what());
            }
        }
    };
    
    send_goal_options.result_callback =
    [this](const GoalHandleFollowJointTrajectory::WrappedResult &result) {
        switch (result.code)
        {
            case rclcpp_action::ResultCode::SUCCEEDED:
                RCLCPP_INFO(this->get_logger(), "Goal succeeded");
                oneIteration(this->origin_node);
                break;
            case rclcpp_action::ResultCode::ABORTED:
                RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
                break;
            case rclcpp_action::ResultCode::CANCELED:
                RCLCPP_WARN(this->get_logger(), "Goal was canceled");
                break;
            default:
                RCLCPP_ERROR(this->get_logger(), "Unknown result code");
                break;
        }
        cout << "End Sending trajectory" << endl;
    };
    action_client_->async_send_goal(goal_msg);//, send_goal_options);
    RCLCPP_INFO(this->get_logger(), "Waiting");
}


JointReceiver::JointReceiver() : Node("arm_receiver") {
        joint_receiver_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/joint_states", 10, [this](std::shared_ptr<sensor_msgs::msg::JointState> msg) {
                joint_state_ = const_pointer_cast<const sensor_msgs::msg::JointState>(msg);
                RCLCPP_INFO(this->get_logger(), "Received Joint State message");
                cout << "Received Joint State message" << endl;
            });
    while (rclcpp::ok() && !joint_state_) {
        rclcpp::spin_some(this->get_node_base_interface());
    }
    if(joint_state_) {
        RCLCPP_INFO(this->get_logger(), "Successfully Received Joint State");
        cout << "Successfully Received Joint State" << endl;
    }
}

shared_ptr<const sensor_msgs::msg::JointState> JointReceiver::get_joint_state() const {
    return joint_state_;
}

void send_trajectory(MatrixD6 th, std::shared_ptr<rclcpp::Node> node) {
    cout << "Sending trajectory..." << endl;
    rclcpp::spin(std::make_shared<TrajectoryActionClient>(th, node));
    cout << "End Sending trajectory" << endl;
}

void setupCommunication(int argc, const char* argv[]) {
    cout << "Communications Setup Start" << endl;
    rclcpp::init(argc, argv);
    cout << "Communications Setup Complete" << endl;
}
Matrix16 receive_joint_state() {
    cout << "Requesting Actual Joint States" << endl;
    auto node= std::make_shared<JointReceiver>();
    auto joint_result=node->get_joint_state();
    Matrix16 ret;
    if (joint_result!=NULL) {
        for (int i=0; i<NUM_JOINTS; i++) {
            RCLCPP_INFO(rclcpp::get_logger("main"), "JointState received:Position[%d]: %f", i,
                        joint_result->position.empty() ? 0.0 :
                            joint_result->position[i]);
            int j=i+1;
            if (j<NUM_JOINTS) {
                ret(j)=joint_result->position[i];
            }
            else {
                ret(0)=joint_result->position[i];
            }
        }
    }else {
        RCLCPP_WARN(rclcpp::get_logger("main"), "No JointState received.");
    }
    cout << "End Joint State Receiving" << endl;
    return ret;
}
