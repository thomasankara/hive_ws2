// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hive_interface2:msg/NavBrainCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/nav_brain_command.h"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__STRUCT_H_
#define HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'destination'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/NavBrainCommand in the package hive_interface2.
/**
  * Commande haut-niveau pour hive_nav_brain
  * NOTE: free_zone_id ici est un entier logique interne Hive (différent du free_zone_id VARCHAR en DB).
 */
typedef struct hive_interface2__msg__NavBrainCommand
{
  int32_t free_zone_id;
  int32_t poi_id;
  geometry_msgs__msg__PoseStamped destination;
  int32_t object_tracking_id;
  int32_t mission_id;
} hive_interface2__msg__NavBrainCommand;

// Struct for a sequence of hive_interface2__msg__NavBrainCommand.
typedef struct hive_interface2__msg__NavBrainCommand__Sequence
{
  hive_interface2__msg__NavBrainCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__msg__NavBrainCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__STRUCT_H_
