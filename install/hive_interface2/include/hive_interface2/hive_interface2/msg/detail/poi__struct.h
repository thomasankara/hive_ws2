// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/poi.h"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__POI__STRUCT_H_
#define HIVE_INTERFACE2__MSG__DETAIL__POI__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'enterprise_full_id_str'
// Member 'deployment_full_id_str'
// Member 'slam_session_full_id_str'
// Member 'free_zone_full_id_str'
// Member 'poi_full_id_str'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Poi in the package hive_interface2.
/**
  * POI issu de la table SQL `poi`
 */
typedef struct hive_interface2__msg__Poi
{
  rosidl_runtime_c__String enterprise_full_id_str;
  rosidl_runtime_c__String deployment_full_id_str;
  rosidl_runtime_c__String slam_session_full_id_str;
  rosidl_runtime_c__String free_zone_full_id_str;
  int32_t is_in_free_zone;
  rosidl_runtime_c__String poi_full_id_str;
  int32_t poi_id;
  float x;
  float y;
  float z;
  float yaw;
  int32_t parking_mode;
  int32_t is_available;
  int32_t charging_mode;
  int32_t is_long_wait_zone;
} hive_interface2__msg__Poi;

// Struct for a sequence of hive_interface2__msg__Poi.
typedef struct hive_interface2__msg__Poi__Sequence
{
  hive_interface2__msg__Poi * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__msg__Poi__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__POI__STRUCT_H_
