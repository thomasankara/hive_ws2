// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hive_interface2:srv/ComputeRoute.idl
// generated code does not contain a copyright notice
#include "hive_interface2/srv/detail/compute_route__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `start_pose`
// Member `goal_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
hive_interface2__srv__ComputeRoute_Request__init(hive_interface2__srv__ComputeRoute_Request * msg)
{
  if (!msg) {
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__Pose__init(&msg->start_pose)) {
    hive_interface2__srv__ComputeRoute_Request__fini(msg);
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__Pose__init(&msg->goal_pose)) {
    hive_interface2__srv__ComputeRoute_Request__fini(msg);
    return false;
  }
  // mode
  return true;
}

void
hive_interface2__srv__ComputeRoute_Request__fini(hive_interface2__srv__ComputeRoute_Request * msg)
{
  if (!msg) {
    return;
  }
  // start_pose
  geometry_msgs__msg__Pose__fini(&msg->start_pose);
  // goal_pose
  geometry_msgs__msg__Pose__fini(&msg->goal_pose);
  // mode
}

bool
hive_interface2__srv__ComputeRoute_Request__are_equal(const hive_interface2__srv__ComputeRoute_Request * lhs, const hive_interface2__srv__ComputeRoute_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->start_pose), &(rhs->start_pose)))
  {
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->goal_pose), &(rhs->goal_pose)))
  {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  return true;
}

bool
hive_interface2__srv__ComputeRoute_Request__copy(
  const hive_interface2__srv__ComputeRoute_Request * input,
  hive_interface2__srv__ComputeRoute_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->start_pose), &(output->start_pose)))
  {
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->goal_pose), &(output->goal_pose)))
  {
    return false;
  }
  // mode
  output->mode = input->mode;
  return true;
}

hive_interface2__srv__ComputeRoute_Request *
hive_interface2__srv__ComputeRoute_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Request * msg = (hive_interface2__srv__ComputeRoute_Request *)allocator.allocate(sizeof(hive_interface2__srv__ComputeRoute_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hive_interface2__srv__ComputeRoute_Request));
  bool success = hive_interface2__srv__ComputeRoute_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hive_interface2__srv__ComputeRoute_Request__destroy(hive_interface2__srv__ComputeRoute_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hive_interface2__srv__ComputeRoute_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hive_interface2__srv__ComputeRoute_Request__Sequence__init(hive_interface2__srv__ComputeRoute_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Request * data = NULL;

  if (size) {
    data = (hive_interface2__srv__ComputeRoute_Request *)allocator.zero_allocate(size, sizeof(hive_interface2__srv__ComputeRoute_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hive_interface2__srv__ComputeRoute_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hive_interface2__srv__ComputeRoute_Request__fini(&data[i - 1]);
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
hive_interface2__srv__ComputeRoute_Request__Sequence__fini(hive_interface2__srv__ComputeRoute_Request__Sequence * array)
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
      hive_interface2__srv__ComputeRoute_Request__fini(&array->data[i]);
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

hive_interface2__srv__ComputeRoute_Request__Sequence *
hive_interface2__srv__ComputeRoute_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Request__Sequence * array = (hive_interface2__srv__ComputeRoute_Request__Sequence *)allocator.allocate(sizeof(hive_interface2__srv__ComputeRoute_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hive_interface2__srv__ComputeRoute_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hive_interface2__srv__ComputeRoute_Request__Sequence__destroy(hive_interface2__srv__ComputeRoute_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hive_interface2__srv__ComputeRoute_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hive_interface2__srv__ComputeRoute_Request__Sequence__are_equal(const hive_interface2__srv__ComputeRoute_Request__Sequence * lhs, const hive_interface2__srv__ComputeRoute_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hive_interface2__srv__ComputeRoute_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hive_interface2__srv__ComputeRoute_Request__Sequence__copy(
  const hive_interface2__srv__ComputeRoute_Request__Sequence * input,
  hive_interface2__srv__ComputeRoute_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hive_interface2__srv__ComputeRoute_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hive_interface2__srv__ComputeRoute_Request * data =
      (hive_interface2__srv__ComputeRoute_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hive_interface2__srv__ComputeRoute_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hive_interface2__srv__ComputeRoute_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hive_interface2__srv__ComputeRoute_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `path`
#include "hive_interface2/msg/detail/lanelet_mini2__functions.h"

bool
hive_interface2__srv__ComputeRoute_Response__init(hive_interface2__srv__ComputeRoute_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    hive_interface2__srv__ComputeRoute_Response__fini(msg);
    return false;
  }
  // path
  if (!hive_interface2__msg__LaneletMini2__Sequence__init(&msg->path, 0)) {
    hive_interface2__srv__ComputeRoute_Response__fini(msg);
    return false;
  }
  // total_distance_m
  // estimated_time_s
  return true;
}

void
hive_interface2__srv__ComputeRoute_Response__fini(hive_interface2__srv__ComputeRoute_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // path
  hive_interface2__msg__LaneletMini2__Sequence__fini(&msg->path);
  // total_distance_m
  // estimated_time_s
}

bool
hive_interface2__srv__ComputeRoute_Response__are_equal(const hive_interface2__srv__ComputeRoute_Response * lhs, const hive_interface2__srv__ComputeRoute_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // path
  if (!hive_interface2__msg__LaneletMini2__Sequence__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  // total_distance_m
  if (lhs->total_distance_m != rhs->total_distance_m) {
    return false;
  }
  // estimated_time_s
  if (lhs->estimated_time_s != rhs->estimated_time_s) {
    return false;
  }
  return true;
}

bool
hive_interface2__srv__ComputeRoute_Response__copy(
  const hive_interface2__srv__ComputeRoute_Response * input,
  hive_interface2__srv__ComputeRoute_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // path
  if (!hive_interface2__msg__LaneletMini2__Sequence__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  // total_distance_m
  output->total_distance_m = input->total_distance_m;
  // estimated_time_s
  output->estimated_time_s = input->estimated_time_s;
  return true;
}

hive_interface2__srv__ComputeRoute_Response *
hive_interface2__srv__ComputeRoute_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Response * msg = (hive_interface2__srv__ComputeRoute_Response *)allocator.allocate(sizeof(hive_interface2__srv__ComputeRoute_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hive_interface2__srv__ComputeRoute_Response));
  bool success = hive_interface2__srv__ComputeRoute_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hive_interface2__srv__ComputeRoute_Response__destroy(hive_interface2__srv__ComputeRoute_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hive_interface2__srv__ComputeRoute_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hive_interface2__srv__ComputeRoute_Response__Sequence__init(hive_interface2__srv__ComputeRoute_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Response * data = NULL;

  if (size) {
    data = (hive_interface2__srv__ComputeRoute_Response *)allocator.zero_allocate(size, sizeof(hive_interface2__srv__ComputeRoute_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hive_interface2__srv__ComputeRoute_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hive_interface2__srv__ComputeRoute_Response__fini(&data[i - 1]);
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
hive_interface2__srv__ComputeRoute_Response__Sequence__fini(hive_interface2__srv__ComputeRoute_Response__Sequence * array)
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
      hive_interface2__srv__ComputeRoute_Response__fini(&array->data[i]);
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

hive_interface2__srv__ComputeRoute_Response__Sequence *
hive_interface2__srv__ComputeRoute_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Response__Sequence * array = (hive_interface2__srv__ComputeRoute_Response__Sequence *)allocator.allocate(sizeof(hive_interface2__srv__ComputeRoute_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hive_interface2__srv__ComputeRoute_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hive_interface2__srv__ComputeRoute_Response__Sequence__destroy(hive_interface2__srv__ComputeRoute_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hive_interface2__srv__ComputeRoute_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hive_interface2__srv__ComputeRoute_Response__Sequence__are_equal(const hive_interface2__srv__ComputeRoute_Response__Sequence * lhs, const hive_interface2__srv__ComputeRoute_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hive_interface2__srv__ComputeRoute_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hive_interface2__srv__ComputeRoute_Response__Sequence__copy(
  const hive_interface2__srv__ComputeRoute_Response__Sequence * input,
  hive_interface2__srv__ComputeRoute_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hive_interface2__srv__ComputeRoute_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hive_interface2__srv__ComputeRoute_Response * data =
      (hive_interface2__srv__ComputeRoute_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hive_interface2__srv__ComputeRoute_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hive_interface2__srv__ComputeRoute_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hive_interface2__srv__ComputeRoute_Response__copy(
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
// #include "hive_interface2/srv/detail/compute_route__functions.h"

bool
hive_interface2__srv__ComputeRoute_Event__init(hive_interface2__srv__ComputeRoute_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    hive_interface2__srv__ComputeRoute_Event__fini(msg);
    return false;
  }
  // request
  if (!hive_interface2__srv__ComputeRoute_Request__Sequence__init(&msg->request, 0)) {
    hive_interface2__srv__ComputeRoute_Event__fini(msg);
    return false;
  }
  // response
  if (!hive_interface2__srv__ComputeRoute_Response__Sequence__init(&msg->response, 0)) {
    hive_interface2__srv__ComputeRoute_Event__fini(msg);
    return false;
  }
  return true;
}

void
hive_interface2__srv__ComputeRoute_Event__fini(hive_interface2__srv__ComputeRoute_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  hive_interface2__srv__ComputeRoute_Request__Sequence__fini(&msg->request);
  // response
  hive_interface2__srv__ComputeRoute_Response__Sequence__fini(&msg->response);
}

bool
hive_interface2__srv__ComputeRoute_Event__are_equal(const hive_interface2__srv__ComputeRoute_Event * lhs, const hive_interface2__srv__ComputeRoute_Event * rhs)
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
  if (!hive_interface2__srv__ComputeRoute_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!hive_interface2__srv__ComputeRoute_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
hive_interface2__srv__ComputeRoute_Event__copy(
  const hive_interface2__srv__ComputeRoute_Event * input,
  hive_interface2__srv__ComputeRoute_Event * output)
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
  if (!hive_interface2__srv__ComputeRoute_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!hive_interface2__srv__ComputeRoute_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

hive_interface2__srv__ComputeRoute_Event *
hive_interface2__srv__ComputeRoute_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Event * msg = (hive_interface2__srv__ComputeRoute_Event *)allocator.allocate(sizeof(hive_interface2__srv__ComputeRoute_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hive_interface2__srv__ComputeRoute_Event));
  bool success = hive_interface2__srv__ComputeRoute_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hive_interface2__srv__ComputeRoute_Event__destroy(hive_interface2__srv__ComputeRoute_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hive_interface2__srv__ComputeRoute_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hive_interface2__srv__ComputeRoute_Event__Sequence__init(hive_interface2__srv__ComputeRoute_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Event * data = NULL;

  if (size) {
    data = (hive_interface2__srv__ComputeRoute_Event *)allocator.zero_allocate(size, sizeof(hive_interface2__srv__ComputeRoute_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hive_interface2__srv__ComputeRoute_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hive_interface2__srv__ComputeRoute_Event__fini(&data[i - 1]);
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
hive_interface2__srv__ComputeRoute_Event__Sequence__fini(hive_interface2__srv__ComputeRoute_Event__Sequence * array)
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
      hive_interface2__srv__ComputeRoute_Event__fini(&array->data[i]);
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

hive_interface2__srv__ComputeRoute_Event__Sequence *
hive_interface2__srv__ComputeRoute_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__srv__ComputeRoute_Event__Sequence * array = (hive_interface2__srv__ComputeRoute_Event__Sequence *)allocator.allocate(sizeof(hive_interface2__srv__ComputeRoute_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hive_interface2__srv__ComputeRoute_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hive_interface2__srv__ComputeRoute_Event__Sequence__destroy(hive_interface2__srv__ComputeRoute_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hive_interface2__srv__ComputeRoute_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hive_interface2__srv__ComputeRoute_Event__Sequence__are_equal(const hive_interface2__srv__ComputeRoute_Event__Sequence * lhs, const hive_interface2__srv__ComputeRoute_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hive_interface2__srv__ComputeRoute_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hive_interface2__srv__ComputeRoute_Event__Sequence__copy(
  const hive_interface2__srv__ComputeRoute_Event__Sequence * input,
  hive_interface2__srv__ComputeRoute_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hive_interface2__srv__ComputeRoute_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hive_interface2__srv__ComputeRoute_Event * data =
      (hive_interface2__srv__ComputeRoute_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hive_interface2__srv__ComputeRoute_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hive_interface2__srv__ComputeRoute_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hive_interface2__srv__ComputeRoute_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
