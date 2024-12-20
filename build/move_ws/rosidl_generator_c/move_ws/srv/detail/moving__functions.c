// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from move_ws:srv/Moving.idl
// generated code does not contain a copyright notice
#include "move_ws/srv/detail/moving__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `xe1`
// Member `phie1`
#include "move_ws/msg/detail/vector3d__functions.h"
// Member `argv`
#include "rosidl_runtime_c/string_functions.h"

bool
move_ws__srv__Moving_Request__init(move_ws__srv__Moving_Request * msg)
{
  if (!msg) {
    return false;
  }
  // xe1
  if (!move_ws__msg__Vector3d__init(&msg->xe1)) {
    move_ws__srv__Moving_Request__fini(msg);
    return false;
  }
  // phie1
  if (!move_ws__msg__Vector3d__init(&msg->phie1)) {
    move_ws__srv__Moving_Request__fini(msg);
    return false;
  }
  // argc
  // argv
  if (!rosidl_runtime_c__String__Sequence__init(&msg->argv, 0)) {
    move_ws__srv__Moving_Request__fini(msg);
    return false;
  }
  return true;
}

void
move_ws__srv__Moving_Request__fini(move_ws__srv__Moving_Request * msg)
{
  if (!msg) {
    return;
  }
  // xe1
  move_ws__msg__Vector3d__fini(&msg->xe1);
  // phie1
  move_ws__msg__Vector3d__fini(&msg->phie1);
  // argc
  // argv
  rosidl_runtime_c__String__Sequence__fini(&msg->argv);
}

bool
move_ws__srv__Moving_Request__are_equal(const move_ws__srv__Moving_Request * lhs, const move_ws__srv__Moving_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // xe1
  if (!move_ws__msg__Vector3d__are_equal(
      &(lhs->xe1), &(rhs->xe1)))
  {
    return false;
  }
  // phie1
  if (!move_ws__msg__Vector3d__are_equal(
      &(lhs->phie1), &(rhs->phie1)))
  {
    return false;
  }
  // argc
  if (lhs->argc != rhs->argc) {
    return false;
  }
  // argv
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->argv), &(rhs->argv)))
  {
    return false;
  }
  return true;
}

bool
move_ws__srv__Moving_Request__copy(
  const move_ws__srv__Moving_Request * input,
  move_ws__srv__Moving_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // xe1
  if (!move_ws__msg__Vector3d__copy(
      &(input->xe1), &(output->xe1)))
  {
    return false;
  }
  // phie1
  if (!move_ws__msg__Vector3d__copy(
      &(input->phie1), &(output->phie1)))
  {
    return false;
  }
  // argc
  output->argc = input->argc;
  // argv
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->argv), &(output->argv)))
  {
    return false;
  }
  return true;
}

move_ws__srv__Moving_Request *
move_ws__srv__Moving_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Request * msg = (move_ws__srv__Moving_Request *)allocator.allocate(sizeof(move_ws__srv__Moving_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(move_ws__srv__Moving_Request));
  bool success = move_ws__srv__Moving_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
move_ws__srv__Moving_Request__destroy(move_ws__srv__Moving_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    move_ws__srv__Moving_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
move_ws__srv__Moving_Request__Sequence__init(move_ws__srv__Moving_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Request * data = NULL;

  if (size) {
    data = (move_ws__srv__Moving_Request *)allocator.zero_allocate(size, sizeof(move_ws__srv__Moving_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = move_ws__srv__Moving_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        move_ws__srv__Moving_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
move_ws__srv__Moving_Request__Sequence__fini(move_ws__srv__Moving_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      move_ws__srv__Moving_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

move_ws__srv__Moving_Request__Sequence *
move_ws__srv__Moving_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Request__Sequence * array = (move_ws__srv__Moving_Request__Sequence *)allocator.allocate(sizeof(move_ws__srv__Moving_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = move_ws__srv__Moving_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
move_ws__srv__Moving_Request__Sequence__destroy(move_ws__srv__Moving_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    move_ws__srv__Moving_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
move_ws__srv__Moving_Request__Sequence__are_equal(const move_ws__srv__Moving_Request__Sequence * lhs, const move_ws__srv__Moving_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!move_ws__srv__Moving_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
move_ws__srv__Moving_Request__Sequence__copy(
  const move_ws__srv__Moving_Request__Sequence * input,
  move_ws__srv__Moving_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(move_ws__srv__Moving_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    move_ws__srv__Moving_Request * data =
      (move_ws__srv__Moving_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!move_ws__srv__Moving_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          move_ws__srv__Moving_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!move_ws__srv__Moving_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
move_ws__srv__Moving_Response__init(move_ws__srv__Moving_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
move_ws__srv__Moving_Response__fini(move_ws__srv__Moving_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
move_ws__srv__Moving_Response__are_equal(const move_ws__srv__Moving_Response * lhs, const move_ws__srv__Moving_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
move_ws__srv__Moving_Response__copy(
  const move_ws__srv__Moving_Response * input,
  move_ws__srv__Moving_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

move_ws__srv__Moving_Response *
move_ws__srv__Moving_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Response * msg = (move_ws__srv__Moving_Response *)allocator.allocate(sizeof(move_ws__srv__Moving_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(move_ws__srv__Moving_Response));
  bool success = move_ws__srv__Moving_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
move_ws__srv__Moving_Response__destroy(move_ws__srv__Moving_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    move_ws__srv__Moving_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
move_ws__srv__Moving_Response__Sequence__init(move_ws__srv__Moving_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Response * data = NULL;

  if (size) {
    data = (move_ws__srv__Moving_Response *)allocator.zero_allocate(size, sizeof(move_ws__srv__Moving_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = move_ws__srv__Moving_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        move_ws__srv__Moving_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
move_ws__srv__Moving_Response__Sequence__fini(move_ws__srv__Moving_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      move_ws__srv__Moving_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

move_ws__srv__Moving_Response__Sequence *
move_ws__srv__Moving_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Response__Sequence * array = (move_ws__srv__Moving_Response__Sequence *)allocator.allocate(sizeof(move_ws__srv__Moving_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = move_ws__srv__Moving_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
move_ws__srv__Moving_Response__Sequence__destroy(move_ws__srv__Moving_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    move_ws__srv__Moving_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
move_ws__srv__Moving_Response__Sequence__are_equal(const move_ws__srv__Moving_Response__Sequence * lhs, const move_ws__srv__Moving_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!move_ws__srv__Moving_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
move_ws__srv__Moving_Response__Sequence__copy(
  const move_ws__srv__Moving_Response__Sequence * input,
  move_ws__srv__Moving_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(move_ws__srv__Moving_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    move_ws__srv__Moving_Response * data =
      (move_ws__srv__Moving_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!move_ws__srv__Moving_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          move_ws__srv__Moving_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!move_ws__srv__Moving_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "move_ws/srv/detail/moving__functions.h"

bool
move_ws__srv__Moving_Event__init(move_ws__srv__Moving_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    move_ws__srv__Moving_Event__fini(msg);
    return false;
  }
  // request
  if (!move_ws__srv__Moving_Request__Sequence__init(&msg->request, 0)) {
    move_ws__srv__Moving_Event__fini(msg);
    return false;
  }
  // response
  if (!move_ws__srv__Moving_Response__Sequence__init(&msg->response, 0)) {
    move_ws__srv__Moving_Event__fini(msg);
    return false;
  }
  return true;
}

void
move_ws__srv__Moving_Event__fini(move_ws__srv__Moving_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  move_ws__srv__Moving_Request__Sequence__fini(&msg->request);
  // response
  move_ws__srv__Moving_Response__Sequence__fini(&msg->response);
}

bool
move_ws__srv__Moving_Event__are_equal(const move_ws__srv__Moving_Event * lhs, const move_ws__srv__Moving_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!move_ws__srv__Moving_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!move_ws__srv__Moving_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
move_ws__srv__Moving_Event__copy(
  const move_ws__srv__Moving_Event * input,
  move_ws__srv__Moving_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!move_ws__srv__Moving_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!move_ws__srv__Moving_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

move_ws__srv__Moving_Event *
move_ws__srv__Moving_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Event * msg = (move_ws__srv__Moving_Event *)allocator.allocate(sizeof(move_ws__srv__Moving_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(move_ws__srv__Moving_Event));
  bool success = move_ws__srv__Moving_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
move_ws__srv__Moving_Event__destroy(move_ws__srv__Moving_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    move_ws__srv__Moving_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
move_ws__srv__Moving_Event__Sequence__init(move_ws__srv__Moving_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Event * data = NULL;

  if (size) {
    data = (move_ws__srv__Moving_Event *)allocator.zero_allocate(size, sizeof(move_ws__srv__Moving_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = move_ws__srv__Moving_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        move_ws__srv__Moving_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
move_ws__srv__Moving_Event__Sequence__fini(move_ws__srv__Moving_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      move_ws__srv__Moving_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

move_ws__srv__Moving_Event__Sequence *
move_ws__srv__Moving_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_ws__srv__Moving_Event__Sequence * array = (move_ws__srv__Moving_Event__Sequence *)allocator.allocate(sizeof(move_ws__srv__Moving_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = move_ws__srv__Moving_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
move_ws__srv__Moving_Event__Sequence__destroy(move_ws__srv__Moving_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    move_ws__srv__Moving_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
move_ws__srv__Moving_Event__Sequence__are_equal(const move_ws__srv__Moving_Event__Sequence * lhs, const move_ws__srv__Moving_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!move_ws__srv__Moving_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
move_ws__srv__Moving_Event__Sequence__copy(
  const move_ws__srv__Moving_Event__Sequence * input,
  move_ws__srv__Moving_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(move_ws__srv__Moving_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    move_ws__srv__Moving_Event * data =
      (move_ws__srv__Moving_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!move_ws__srv__Moving_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          move_ws__srv__Moving_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!move_ws__srv__Moving_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
