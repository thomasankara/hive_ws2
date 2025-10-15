// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hive_interface2:msg/LaneletMini2Array.idl
// generated code does not contain a copyright notice
#include "hive_interface2/msg/detail/lanelet_mini2_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `lanelets`
#include "hive_interface2/msg/detail/lanelet_mini2__functions.h"

bool
hive_interface2__msg__LaneletMini2Array__init(hive_interface2__msg__LaneletMini2Array * msg)
{
  if (!msg) {
    return false;
  }
  // lanelets
  if (!hive_interface2__msg__LaneletMini2__Sequence__init(&msg->lanelets, 0)) {
    hive_interface2__msg__LaneletMini2Array__fini(msg);
    return false;
  }
  return true;
}

void
hive_interface2__msg__LaneletMini2Array__fini(hive_interface2__msg__LaneletMini2Array * msg)
{
  if (!msg) {
    return;
  }
  // lanelets
  hive_interface2__msg__LaneletMini2__Sequence__fini(&msg->lanelets);
}

bool
hive_interface2__msg__LaneletMini2Array__are_equal(const hive_interface2__msg__LaneletMini2Array * lhs, const hive_interface2__msg__LaneletMini2Array * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lanelets
  if (!hive_interface2__msg__LaneletMini2__Sequence__are_equal(
      &(lhs->lanelets), &(rhs->lanelets)))
  {
    return false;
  }
  return true;
}

bool
hive_interface2__msg__LaneletMini2Array__copy(
  const hive_interface2__msg__LaneletMini2Array * input,
  hive_interface2__msg__LaneletMini2Array * output)
{
  if (!input || !output) {
    return false;
  }
  // lanelets
  if (!hive_interface2__msg__LaneletMini2__Sequence__copy(
      &(input->lanelets), &(output->lanelets)))
  {
    return false;
  }
  return true;
}

hive_interface2__msg__LaneletMini2Array *
hive_interface2__msg__LaneletMini2Array__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__LaneletMini2Array * msg = (hive_interface2__msg__LaneletMini2Array *)allocator.allocate(sizeof(hive_interface2__msg__LaneletMini2Array), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hive_interface2__msg__LaneletMini2Array));
  bool success = hive_interface2__msg__LaneletMini2Array__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hive_interface2__msg__LaneletMini2Array__destroy(hive_interface2__msg__LaneletMini2Array * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hive_interface2__msg__LaneletMini2Array__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hive_interface2__msg__LaneletMini2Array__Sequence__init(hive_interface2__msg__LaneletMini2Array__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__LaneletMini2Array * data = NULL;

  if (size) {
    data = (hive_interface2__msg__LaneletMini2Array *)allocator.zero_allocate(size, sizeof(hive_interface2__msg__LaneletMini2Array), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hive_interface2__msg__LaneletMini2Array__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hive_interface2__msg__LaneletMini2Array__fini(&data[i - 1]);
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
hive_interface2__msg__LaneletMini2Array__Sequence__fini(hive_interface2__msg__LaneletMini2Array__Sequence * array)
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
      hive_interface2__msg__LaneletMini2Array__fini(&array->data[i]);
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

hive_interface2__msg__LaneletMini2Array__Sequence *
hive_interface2__msg__LaneletMini2Array__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hive_interface2__msg__LaneletMini2Array__Sequence * array = (hive_interface2__msg__LaneletMini2Array__Sequence *)allocator.allocate(sizeof(hive_interface2__msg__LaneletMini2Array__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hive_interface2__msg__LaneletMini2Array__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hive_interface2__msg__LaneletMini2Array__Sequence__destroy(hive_interface2__msg__LaneletMini2Array__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hive_interface2__msg__LaneletMini2Array__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hive_interface2__msg__LaneletMini2Array__Sequence__are_equal(const hive_interface2__msg__LaneletMini2Array__Sequence * lhs, const hive_interface2__msg__LaneletMini2Array__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hive_interface2__msg__LaneletMini2Array__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hive_interface2__msg__LaneletMini2Array__Sequence__copy(
  const hive_interface2__msg__LaneletMini2Array__Sequence * input,
  hive_interface2__msg__LaneletMini2Array__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hive_interface2__msg__LaneletMini2Array);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hive_interface2__msg__LaneletMini2Array * data =
      (hive_interface2__msg__LaneletMini2Array *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hive_interface2__msg__LaneletMini2Array__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hive_interface2__msg__LaneletMini2Array__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hive_interface2__msg__LaneletMini2Array__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
