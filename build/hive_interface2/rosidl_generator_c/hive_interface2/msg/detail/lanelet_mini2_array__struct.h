// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hive_interface2:msg/LaneletMini2Array.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/lanelet_mini2_array.h"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__STRUCT_H_
#define HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'lanelets'
#include "hive_interface2/msg/detail/lanelet_mini2__struct.h"

/// Struct defined in msg/LaneletMini2Array in the package hive_interface2.
/**
  * ============================================================
  * Hive Robotics - LaneletMini2Array.msg
  * ============================================================
  * Représente un ensemble de LaneletMini2, utilisé pour transférer
  * toute la base ou une sélection de lanelets.
  * ============================================================
 */
typedef struct hive_interface2__msg__LaneletMini2Array
{
  hive_interface2__msg__LaneletMini2__Sequence lanelets;
} hive_interface2__msg__LaneletMini2Array;

// Struct for a sequence of hive_interface2__msg__LaneletMini2Array.
typedef struct hive_interface2__msg__LaneletMini2Array__Sequence
{
  hive_interface2__msg__LaneletMini2Array * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__msg__LaneletMini2Array__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__STRUCT_H_
