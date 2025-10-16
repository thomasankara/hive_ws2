// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hive_interface2:msg/NavBrainCommand.idl
// generated code does not contain a copyright notice
#include "hive_interface2/msg/detail/nav_brain_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `destination`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
hive_interface2__msg__NavBrainCommand__init(hive_interface2__msg__NavBrainCommand * msg)
{
  if (!msg) {
    return false;
  }
  // free_zone_id
  // poi_id
  // destination
  if (!geometry_msgs__msg__PoseStamped__init(&msg->destination)) {
    hive_interface2__msg__NavBrainCommand__fini(msg);
    return false;
  }
  // object_tracking_id
  // mission_id
  return true;
}

void
hive_interface2__msg__NavBrainCommand__fini(hive_interface2__msg__NavBrainCommand * msg)
{
  if (!msg) {
    return;
  }
  // free_zone_id
  // poi_id
  // destination
  geometry_msgs__msg__PoseStamped__fini(&msg->destination);
  // object_tracking_id
  // mission_id
}

bool
hive_interface2__msg__NavBrainCommand__are_equal(const hive_interface2__msg__NavBrainCommand * lhs, const hive_interface2__msg__NavBrainCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // free_zone_id
  if (lhs->free_zone_id != rhs->free_zone_id) {
    return false;
  }
  // poi_id
  if (lhs->poi_id != rhs->poi_id) {
    return false;
  }
  // destination
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->destination), &(rhs->destination)))
  {
    return false;
  }
  // object_tracking_id
  if (lhs->object_tracking_id != rhs->object_tracking_id) {
    return false;
  }
  // mission_id
  if (lhs->mission_id != rhs->mission_id) {
    return false;
  }
  return true;
}

bool
hive_interface2__msg__NavBrainCommand__copy(
  const hive_interface2__msg__NavBrainCommand * input,
  hive_interface2__msg__NavBrainCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // free_zone_id
  output->free_zone_id = input->free_zone_id;
  // poi_id
  output->poi_id = input->poi_id;
  // destination
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->destination), &(output->destination)))
  {
    return false;
  }
  // object_tracking_id
  output->object_tracking_id = input->object_tracking_id;
  // mission_id
  output->mission_id = input->mission_id;
  return true;
}

hive_interface2__msg__NavBrainCommand *
hive_interface2__msg__NavBrainCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__NavBrainCommand * msg = (hive_interface2__msg__NavBrainCommand *)allocator.allocate(sizeof(hive_interface2__msg__NavBrainCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hive_interface2__msg__NavBrainCommand));
  bool success = hive_interface2__msg__NavBrainCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hive_interface2__msg__NavBrainCommand__destroy(hive_interface2__msg__NavBrainCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hive_interface2__msg__NavBrainCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hive_interface2__msg__NavBrainCommand__Sequence__init(hive_interface2__msg__NavBrainCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__NavBrainCommand * data = NULL;

  if (size) {
    data = (hive_interface2__msg__NavBrainCommand *)allocator.zero_allocate(size, sizeof(hive_interface2__msg__NavBrainCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hive_interface2__msg__NavBrainCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hive_interface2__msg__NavBrainCommand__fini(&data[i - 1]);
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
hive_interface2__msg__NavBrainCommand__Sequence__fini(hive_interface2__msg__NavBrainCommand__Sequence * array)
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
      hive_interface2__msg__NavBrainCommand__fini(&array->data[i]);
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

hive_interface2__msg__NavBrainCommand__Sequence *
hive_interface2__msg__NavBrainCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__NavBrainCommand__Sequence * array = (hive_interface2__msg__NavBrainCommand__Sequence *)allocator.allocate(sizeof(hive_interface2__msg__NavBrainCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hive_interface2__msg__NavBrainCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hive_interface2__msg__NavBrainCommand__Sequence__destroy(hive_interface2__msg__NavBrainCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hive_interface2__msg__NavBrainCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hive_interface2__msg__NavBrainCommand__Sequence__are_equal(const hive_interface2__msg__NavBrainCommand__Sequence * lhs, const hive_interface2__msg__NavBrainCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hive_interface2__msg__NavBrainCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hive_interface2__msg__NavBrainCommand__Sequence__copy(
  const hive_interface2__msg__NavBrainCommand__Sequence * input,
  hive_interface2__msg__NavBrainCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hive_interface2__msg__NavBrainCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hive_interface2__msg__NavBrainCommand * data =
      (hive_interface2__msg__NavBrainCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hive_interface2__msg__NavBrainCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hive_interface2__msg__NavBrainCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hive_interface2__msg__NavBrainCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
