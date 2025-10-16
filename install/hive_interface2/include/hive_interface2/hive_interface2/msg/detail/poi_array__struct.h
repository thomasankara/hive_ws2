// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hive_interface2:msg/PoiArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/poi_array.h"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__POI_ARRAY__STRUCT_H_
#define HIVE_INTERFACE2__MSG__DETAIL__POI_ARRAY__STRUCT_H_

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
#include "hive_interface2/msg/detail/poi__struct.h"

/// Struct defined in msg/PoiArray in the package hive_interface2.
typedef struct hive_interface2__msg__PoiArray
{
  hive_interface2__msg__Poi__Sequence items;
} hive_interface2__msg__PoiArray;

// Struct for a sequence of hive_interface2__msg__PoiArray.
typedef struct hive_interface2__msg__PoiArray__Sequence
{
  hive_interface2__msg__PoiArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__msg__PoiArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__POI_ARRAY__STRUCT_H_
