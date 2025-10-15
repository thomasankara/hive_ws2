// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hive_interface2:msg/LaneletMini2.idl
// generated code does not contain a copyright notice
#include "hive_interface2/msg/detail/lanelet_mini2__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `enterprise_full_id_str`
// Member `deployment_full_id_str`
// Member `slam_session_full_id_str`
// Member `configuration_group_id_str`
// Member `road_group_id_str`
#include "rosidl_runtime_c/string_functions.h"

bool
hive_interface2__msg__LaneletMini2__init(hive_interface2__msg__LaneletMini2 * msg)
{
  if (!msg) {
    return false;
  }
  // enterprise_full_id_str
  if (!rosidl_runtime_c__String__init(&msg->enterprise_full_id_str)) {
    hive_interface2__msg__LaneletMini2__fini(msg);
    return false;
  }
  // deployment_full_id_str
  if (!rosidl_runtime_c__String__init(&msg->deployment_full_id_str)) {
    hive_interface2__msg__LaneletMini2__fini(msg);
    return false;
  }
  // slam_session_full_id_str
  if (!rosidl_runtime_c__String__init(&msg->slam_session_full_id_str)) {
    hive_interface2__msg__LaneletMini2__fini(msg);
    return false;
  }
  // lanelet_mini_id
  // start_point_x
  // start_point_y
  // start_point_z
  // end_point_x
  // end_point_y
  // end_point_z
  // navigation_direction
  // border_mode
  // u_turn_allowed
  // slope_alert
  // vegetation_alert
  // offroad_alert
  // configuration_group_id_str
  if (!rosidl_runtime_c__String__init(&msg->configuration_group_id_str)) {
    hive_interface2__msg__LaneletMini2__fini(msg);
    return false;
  }
  // road_group_id_str
  if (!rosidl_runtime_c__String__init(&msg->road_group_id_str)) {
    hive_interface2__msg__LaneletMini2__fini(msg);
    return false;
  }
  // max_speed
  // width
  return true;
}

void
hive_interface2__msg__LaneletMini2__fini(hive_interface2__msg__LaneletMini2 * msg)
{
  if (!msg) {
    return;
  }
  // enterprise_full_id_str
  rosidl_runtime_c__String__fini(&msg->enterprise_full_id_str);
  // deployment_full_id_str
  rosidl_runtime_c__String__fini(&msg->deployment_full_id_str);
  // slam_session_full_id_str
  rosidl_runtime_c__String__fini(&msg->slam_session_full_id_str);
  // lanelet_mini_id
  // start_point_x
  // start_point_y
  // start_point_z
  // end_point_x
  // end_point_y
  // end_point_z
  // navigation_direction
  // border_mode
  // u_turn_allowed
  // slope_alert
  // vegetation_alert
  // offroad_alert
  // configuration_group_id_str
  rosidl_runtime_c__String__fini(&msg->configuration_group_id_str);
  // road_group_id_str
  rosidl_runtime_c__String__fini(&msg->road_group_id_str);
  // max_speed
  // width
}

bool
hive_interface2__msg__LaneletMini2__are_equal(const hive_interface2__msg__LaneletMini2 * lhs, const hive_interface2__msg__LaneletMini2 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // enterprise_full_id_str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->enterprise_full_id_str), &(rhs->enterprise_full_id_str)))
  {
    return false;
  }
  // deployment_full_id_str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->deployment_full_id_str), &(rhs->deployment_full_id_str)))
  {
    return false;
  }
  // slam_session_full_id_str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->slam_session_full_id_str), &(rhs->slam_session_full_id_str)))
  {
    return false;
  }
  // lanelet_mini_id
  if (lhs->lanelet_mini_id != rhs->lanelet_mini_id) {
    return false;
  }
  // start_point_x
  if (lhs->start_point_x != rhs->start_point_x) {
    return false;
  }
  // start_point_y
  if (lhs->start_point_y != rhs->start_point_y) {
    return false;
  }
  // start_point_z
  if (lhs->start_point_z != rhs->start_point_z) {
    return false;
  }
  // end_point_x
  if (lhs->end_point_x != rhs->end_point_x) {
    return false;
  }
  // end_point_y
  if (lhs->end_point_y != rhs->end_point_y) {
    return false;
  }
  // end_point_z
  if (lhs->end_point_z != rhs->end_point_z) {
    return false;
  }
  // navigation_direction
  if (lhs->navigation_direction != rhs->navigation_direction) {
    return false;
  }
  // border_mode
  if (lhs->border_mode != rhs->border_mode) {
    return false;
  }
  // u_turn_allowed
  if (lhs->u_turn_allowed != rhs->u_turn_allowed) {
    return false;
  }
  // slope_alert
  if (lhs->slope_alert != rhs->slope_alert) {
    return false;
  }
  // vegetation_alert
  if (lhs->vegetation_alert != rhs->vegetation_alert) {
    return false;
  }
  // offroad_alert
  if (lhs->offroad_alert != rhs->offroad_alert) {
    return false;
  }
  // configuration_group_id_str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->configuration_group_id_str), &(rhs->configuration_group_id_str)))
  {
    return false;
  }
  // road_group_id_str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->road_group_id_str), &(rhs->road_group_id_str)))
  {
    return false;
  }
  // max_speed
  if (lhs->max_speed != rhs->max_speed) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  return true;
}

bool
hive_interface2__msg__LaneletMini2__copy(
  const hive_interface2__msg__LaneletMini2 * input,
  hive_interface2__msg__LaneletMini2 * output)
{
  if (!input || !output) {
    return false;
  }
  // enterprise_full_id_str
  if (!rosidl_runtime_c__String__copy(
      &(input->enterprise_full_id_str), &(output->enterprise_full_id_str)))
  {
    return false;
  }
  // deployment_full_id_str
  if (!rosidl_runtime_c__String__copy(
      &(input->deployment_full_id_str), &(output->deployment_full_id_str)))
  {
    return false;
  }
  // slam_session_full_id_str
  if (!rosidl_runtime_c__String__copy(
      &(input->slam_session_full_id_str), &(output->slam_session_full_id_str)))
  {
    return false;
  }
  // lanelet_mini_id
  output->lanelet_mini_id = input->lanelet_mini_id;
  // start_point_x
  output->start_point_x = input->start_point_x;
  // start_point_y
  output->start_point_y = input->start_point_y;
  // start_point_z
  output->start_point_z = input->start_point_z;
  // end_point_x
  output->end_point_x = input->end_point_x;
  // end_point_y
  output->end_point_y = input->end_point_y;
  // end_point_z
  output->end_point_z = input->end_point_z;
  // navigation_direction
  output->navigation_direction = input->navigation_direction;
  // border_mode
  output->border_mode = input->border_mode;
  // u_turn_allowed
  output->u_turn_allowed = input->u_turn_allowed;
  // slope_alert
  output->slope_alert = input->slope_alert;
  // vegetation_alert
  output->vegetation_alert = input->vegetation_alert;
  // offroad_alert
  output->offroad_alert = input->offroad_alert;
  // configuration_group_id_str
  if (!rosidl_runtime_c__String__copy(
      &(input->configuration_group_id_str), &(output->configuration_group_id_str)))
  {
    return false;
  }
  // road_group_id_str
  if (!rosidl_runtime_c__String__copy(
      &(input->road_group_id_str), &(output->road_group_id_str)))
  {
    return false;
  }
  // max_speed
  output->max_speed = input->max_speed;
  // width
  output->width = input->width;
  return true;
}

hive_interface2__msg__LaneletMini2 *
hive_interface2__msg__LaneletMini2__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__LaneletMini2 * msg = (hive_interface2__msg__LaneletMini2 *)allocator.allocate(sizeof(hive_interface2__msg__LaneletMini2), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hive_interface2__msg__LaneletMini2));
  bool success = hive_interface2__msg__LaneletMini2__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hive_interface2__msg__LaneletMini2__destroy(hive_interface2__msg__LaneletMini2 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hive_interface2__msg__LaneletMini2__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hive_interface2__msg__LaneletMini2__Sequence__init(hive_interface2__msg__LaneletMini2__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__LaneletMini2 * data = NULL;

  if (size) {
    data = (hive_interface2__msg__LaneletMini2 *)allocator.zero_allocate(size, sizeof(hive_interface2__msg__LaneletMini2), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hive_interface2__msg__LaneletMini2__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hive_interface2__msg__LaneletMini2__fini(&data[i - 1]);
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
hive_interface2__msg__LaneletMini2__Sequence__fini(hive_interface2__msg__LaneletMini2__Sequence * array)
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
      hive_interface2__msg__LaneletMini2__fini(&array->data[i]);
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

hive_interface2__msg__LaneletMini2__Sequence *
hive_interface2__msg__LaneletMini2__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__LaneletMini2__Sequence * array = (hive_interface2__msg__LaneletMini2__Sequence *)allocator.allocate(sizeof(hive_interface2__msg__LaneletMini2__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hive_interface2__msg__LaneletMini2__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hive_interface2__msg__LaneletMini2__Sequence__destroy(hive_interface2__msg__LaneletMini2__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hive_interface2__msg__LaneletMini2__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hive_interface2__msg__LaneletMini2__Sequence__are_equal(const hive_interface2__msg__LaneletMini2__Sequence * lhs, const hive_interface2__msg__LaneletMini2__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hive_interface2__msg__LaneletMini2__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hive_interface2__msg__LaneletMini2__Sequence__copy(
  const hive_interface2__msg__LaneletMini2__Sequence * input,
  hive_interface2__msg__LaneletMini2__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hive_interface2__msg__LaneletMini2);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hive_interface2__msg__LaneletMini2 * data =
      (hive_interface2__msg__LaneletMini2 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hive_interface2__msg__LaneletMini2__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hive_interface2__msg__LaneletMini2__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hive_interface2__msg__LaneletMini2__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
