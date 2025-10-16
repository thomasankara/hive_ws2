// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice
#include "hive_interface2/msg/detail/poi__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `enterprise_full_id_str`
// Member `deployment_full_id_str`
// Member `slam_session_full_id_str`
// Member `free_zone_full_id_str`
// Member `poi_full_id_str`
#include "rosidl_runtime_c/string_functions.h"

bool
hive_interface2__msg__Poi__init(hive_interface2__msg__Poi * msg)
{
  if (!msg) {
    return false;
  }
  // enterprise_full_id_str
  if (!rosidl_runtime_c__String__init(&msg->enterprise_full_id_str)) {
    hive_interface2__msg__Poi__fini(msg);
    return false;
  }
  // deployment_full_id_str
  if (!rosidl_runtime_c__String__init(&msg->deployment_full_id_str)) {
    hive_interface2__msg__Poi__fini(msg);
    return false;
  }
  // slam_session_full_id_str
  if (!rosidl_runtime_c__String__init(&msg->slam_session_full_id_str)) {
    hive_interface2__msg__Poi__fini(msg);
    return false;
  }
  // free_zone_full_id_str
  if (!rosidl_runtime_c__String__init(&msg->free_zone_full_id_str)) {
    hive_interface2__msg__Poi__fini(msg);
    return false;
  }
  // is_in_free_zone
  // poi_full_id_str
  if (!rosidl_runtime_c__String__init(&msg->poi_full_id_str)) {
    hive_interface2__msg__Poi__fini(msg);
    return false;
  }
  // poi_id
  // x
  // y
  // z
  // yaw
  // parking_mode
  // is_available
  // charging_mode
  // is_long_wait_zone
  return true;
}

void
hive_interface2__msg__Poi__fini(hive_interface2__msg__Poi * msg)
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
  // free_zone_full_id_str
  rosidl_runtime_c__String__fini(&msg->free_zone_full_id_str);
  // is_in_free_zone
  // poi_full_id_str
  rosidl_runtime_c__String__fini(&msg->poi_full_id_str);
  // poi_id
  // x
  // y
  // z
  // yaw
  // parking_mode
  // is_available
  // charging_mode
  // is_long_wait_zone
}

bool
hive_interface2__msg__Poi__are_equal(const hive_interface2__msg__Poi * lhs, const hive_interface2__msg__Poi * rhs)
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
  // free_zone_full_id_str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->free_zone_full_id_str), &(rhs->free_zone_full_id_str)))
  {
    return false;
  }
  // is_in_free_zone
  if (lhs->is_in_free_zone != rhs->is_in_free_zone) {
    return false;
  }
  // poi_full_id_str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->poi_full_id_str), &(rhs->poi_full_id_str)))
  {
    return false;
  }
  // poi_id
  if (lhs->poi_id != rhs->poi_id) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // parking_mode
  if (lhs->parking_mode != rhs->parking_mode) {
    return false;
  }
  // is_available
  if (lhs->is_available != rhs->is_available) {
    return false;
  }
  // charging_mode
  if (lhs->charging_mode != rhs->charging_mode) {
    return false;
  }
  // is_long_wait_zone
  if (lhs->is_long_wait_zone != rhs->is_long_wait_zone) {
    return false;
  }
  return true;
}

bool
hive_interface2__msg__Poi__copy(
  const hive_interface2__msg__Poi * input,
  hive_interface2__msg__Poi * output)
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
  // free_zone_full_id_str
  if (!rosidl_runtime_c__String__copy(
      &(input->free_zone_full_id_str), &(output->free_zone_full_id_str)))
  {
    return false;
  }
  // is_in_free_zone
  output->is_in_free_zone = input->is_in_free_zone;
  // poi_full_id_str
  if (!rosidl_runtime_c__String__copy(
      &(input->poi_full_id_str), &(output->poi_full_id_str)))
  {
    return false;
  }
  // poi_id
  output->poi_id = input->poi_id;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // yaw
  output->yaw = input->yaw;
  // parking_mode
  output->parking_mode = input->parking_mode;
  // is_available
  output->is_available = input->is_available;
  // charging_mode
  output->charging_mode = input->charging_mode;
  // is_long_wait_zone
  output->is_long_wait_zone = input->is_long_wait_zone;
  return true;
}

hive_interface2__msg__Poi *
hive_interface2__msg__Poi__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__Poi * msg = (hive_interface2__msg__Poi *)allocator.allocate(sizeof(hive_interface2__msg__Poi), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hive_interface2__msg__Poi));
  bool success = hive_interface2__msg__Poi__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hive_interface2__msg__Poi__destroy(hive_interface2__msg__Poi * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hive_interface2__msg__Poi__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hive_interface2__msg__Poi__Sequence__init(hive_interface2__msg__Poi__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__Poi * data = NULL;

  if (size) {
    data = (hive_interface2__msg__Poi *)allocator.zero_allocate(size, sizeof(hive_interface2__msg__Poi), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hive_interface2__msg__Poi__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hive_interface2__msg__Poi__fini(&data[i - 1]);
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
hive_interface2__msg__Poi__Sequence__fini(hive_interface2__msg__Poi__Sequence * array)
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
      hive_interface2__msg__Poi__fini(&array->data[i]);
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

hive_interface2__msg__Poi__Sequence *
hive_interface2__msg__Poi__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__Poi__Sequence * array = (hive_interface2__msg__Poi__Sequence *)allocator.allocate(sizeof(hive_interface2__msg__Poi__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hive_interface2__msg__Poi__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hive_interface2__msg__Poi__Sequence__destroy(hive_interface2__msg__Poi__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hive_interface2__msg__Poi__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hive_interface2__msg__Poi__Sequence__are_equal(const hive_interface2__msg__Poi__Sequence * lhs, const hive_interface2__msg__Poi__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hive_interface2__msg__Poi__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hive_interface2__msg__Poi__Sequence__copy(
  const hive_interface2__msg__Poi__Sequence * input,
  hive_interface2__msg__Poi__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hive_interface2__msg__Poi);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hive_interface2__msg__Poi * data =
      (hive_interface2__msg__Poi *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hive_interface2__msg__Poi__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hive_interface2__msg__Poi__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hive_interface2__msg__Poi__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
