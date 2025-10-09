// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav2_msgs:srv/SaveMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav2_msgs/srv/save_map.h"


#ifndef NAV2_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_
#define NAV2_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'map_topic'
// Member 'map_url'
// Member 'image_format'
// Member 'map_mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SaveMap in the package nav2_msgs.
typedef struct nav2_msgs__srv__SaveMap_Request
{
  rosidl_runtime_c__String map_topic;
  rosidl_runtime_c__String map_url;
  /// Constants for image_format. Supported formats: pgm, png, bmp
  rosidl_runtime_c__String image_format;
  /// Map modes: trinary, scale or raw
  rosidl_runtime_c__String map_mode;
  /// Thresholds. Values in range of
  float free_thresh;
  float occupied_thresh;
} nav2_msgs__srv__SaveMap_Request;

// Struct for a sequence of nav2_msgs__srv__SaveMap_Request.
typedef struct nav2_msgs__srv__SaveMap_Request__Sequence
{
  nav2_msgs__srv__SaveMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_msgs__srv__SaveMap_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/SaveMap in the package nav2_msgs.
typedef struct nav2_msgs__srv__SaveMap_Response
{
  bool result;
} nav2_msgs__srv__SaveMap_Response;

// Struct for a sequence of nav2_msgs__srv__SaveMap_Response.
typedef struct nav2_msgs__srv__SaveMap_Response__Sequence
{
  nav2_msgs__srv__SaveMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_msgs__srv__SaveMap_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  nav2_msgs__srv__SaveMap_Event__request__MAX_SIZE = 1
};
// response
enum
{
  nav2_msgs__srv__SaveMap_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SaveMap in the package nav2_msgs.
typedef struct nav2_msgs__srv__SaveMap_Event
{
  service_msgs__msg__ServiceEventInfo info;
  nav2_msgs__srv__SaveMap_Request__Sequence request;
  nav2_msgs__srv__SaveMap_Response__Sequence response;
} nav2_msgs__srv__SaveMap_Event;

// Struct for a sequence of nav2_msgs__srv__SaveMap_Event.
typedef struct nav2_msgs__srv__SaveMap_Event__Sequence
{
  nav2_msgs__srv__SaveMap_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav2_msgs__srv__SaveMap_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV2_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_
