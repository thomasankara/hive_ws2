// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hive_interface2:msg/FreeZone.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/free_zone.h"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__STRUCT_H_
#define HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__STRUCT_H_

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
// Member 'free_zone_id'
// Member 'zone_polygon_points_json'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/FreeZone in the package hive_interface2.
/**
  * Zone libre issue de la table SQL `zone_libre`
 */
typedef struct hive_interface2__msg__FreeZone
{
  rosidl_runtime_c__String enterprise_full_id_str;
  rosidl_runtime_c__String deployment_full_id_str;
  rosidl_runtime_c__String slam_session_full_id_str;
  rosidl_runtime_c__String free_zone_full_id_str;
  rosidl_runtime_c__String free_zone_id;
  int32_t is_parking_available;
  int32_t is_offpoi_parking_allowed;
  int32_t is_long_wait_zone;
  /// JSON brut de la DB
  rosidl_runtime_c__String zone_polygon_points_json;
  int32_t max_speed;
} hive_interface2__msg__FreeZone;

// Struct for a sequence of hive_interface2__msg__FreeZone.
typedef struct hive_interface2__msg__FreeZone__Sequence
{
  hive_interface2__msg__FreeZone * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__msg__FreeZone__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__STRUCT_H_
