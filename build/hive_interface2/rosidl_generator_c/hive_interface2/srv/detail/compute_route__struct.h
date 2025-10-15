// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hive_interface2:srv/ComputeRoute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/srv/compute_route.h"


#ifndef HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__STRUCT_H_
#define HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start_pose'
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/ComputeRoute in the package hive_interface2.
typedef struct hive_interface2__srv__ComputeRoute_Request
{
  /// --- Requête ---
  /// Pose de départ (orientation ignorée ici)
  geometry_msgs__msg__Pose start_pose;
  /// Pose d'arrivée (orientation ignorée ici)
  geometry_msgs__msg__Pose goal_pose;
  /// Mode de coût :
  /// 0 = distance minimale
  /// 1 = temps minimal (utilise max_speed de chaque lanelet)
  int32_t mode;
} hive_interface2__srv__ComputeRoute_Request;

// Struct for a sequence of hive_interface2__srv__ComputeRoute_Request.
typedef struct hive_interface2__srv__ComputeRoute_Request__Sequence
{
  hive_interface2__srv__ComputeRoute_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__srv__ComputeRoute_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'path'
#include "hive_interface2/msg/detail/lanelet_mini2__struct.h"

/// Struct defined in srv/ComputeRoute in the package hive_interface2.
typedef struct hive_interface2__srv__ComputeRoute_Response
{
  /// --- Réponse ---
  /// true si un itinéraire a été trouvé (ou ligne droite < seuil)
  bool success;
  /// infos ou erreur
  rosidl_runtime_c__String message;
  /// suite de lanelets (peut être vide si "ligne droite")
  hive_interface2__msg__LaneletMini2__Sequence path;
  /// distance totale prévue (m)
  double total_distance_m;
  /// temps estimé (s)
  double estimated_time_s;
} hive_interface2__srv__ComputeRoute_Response;

// Struct for a sequence of hive_interface2__srv__ComputeRoute_Response.
typedef struct hive_interface2__srv__ComputeRoute_Response__Sequence
{
  hive_interface2__srv__ComputeRoute_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__srv__ComputeRoute_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  hive_interface2__srv__ComputeRoute_Event__request__MAX_SIZE = 1
};
// response
enum
{
  hive_interface2__srv__ComputeRoute_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ComputeRoute in the package hive_interface2.
typedef struct hive_interface2__srv__ComputeRoute_Event
{
  service_msgs__msg__ServiceEventInfo info;
  hive_interface2__srv__ComputeRoute_Request__Sequence request;
  hive_interface2__srv__ComputeRoute_Response__Sequence response;
} hive_interface2__srv__ComputeRoute_Event;

// Struct for a sequence of hive_interface2__srv__ComputeRoute_Event.
typedef struct hive_interface2__srv__ComputeRoute_Event__Sequence
{
  hive_interface2__srv__ComputeRoute_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__srv__ComputeRoute_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__STRUCT_H_
