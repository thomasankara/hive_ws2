// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hive_interface2:msg/FreeZoneArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/free_zone_array.h"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE_ARRAY__STRUCT_H_
#define HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'items'
#include "hive_interface2/msg/detail/free_zone__struct.h"

/// Struct defined in msg/FreeZoneArray in the package hive_interface2.
typedef struct hive_interface2__msg__FreeZoneArray
{
  hive_interface2__msg__FreeZone__Sequence items;
} hive_interface2__msg__FreeZoneArray;

// Struct for a sequence of hive_interface2__msg__FreeZoneArray.
typedef struct hive_interface2__msg__FreeZoneArray__Sequence
{
  hive_interface2__msg__FreeZoneArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__msg__FreeZoneArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE_ARRAY__STRUCT_H_
