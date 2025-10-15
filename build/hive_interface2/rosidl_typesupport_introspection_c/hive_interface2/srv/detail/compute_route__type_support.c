// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hive_interface2:srv/ComputeRoute.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hive_interface2/srv/detail/compute_route__rosidl_typesupport_introspection_c.h"
#include "hive_interface2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hive_interface2/srv/detail/compute_route__functions.h"
#include "hive_interface2/srv/detail/compute_route__struct.h"


// Include directives for member types
// Member `start_pose`
// Member `goal_pose`
#include "geometry_msgs/msg/pose.h"
// Member `start_pose`
// Member `goal_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hive_interface2__srv__ComputeRoute_Request__init(message_memory);
}

void hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_fini_function(void * message_memory)
{
  hive_interface2__srv__ComputeRoute_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_member_array[3] = {
  {
    "start_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Request, start_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Request, goal_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Request, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_members = {
  "hive_interface2__srv",  // message namespace
  "ComputeRoute_Request",  // message name
  3,  // number of fields
  sizeof(hive_interface2__srv__ComputeRoute_Request),
  false,  // has_any_key_member_
  hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_member_array,  // message members
  hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_type_support_handle = {
  0,
  &hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_members,
  get_message_typesupport_handle_function,
  &hive_interface2__srv__ComputeRoute_Request__get_type_hash,
  &hive_interface2__srv__ComputeRoute_Request__get_type_description,
  &hive_interface2__srv__ComputeRoute_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hive_interface2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Request)() {
  hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_type_support_handle.typesupport_identifier) {
    hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hive_interface2/srv/detail/compute_route__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hive_interface2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hive_interface2/srv/detail/compute_route__functions.h"
// already included above
// #include "hive_interface2/srv/detail/compute_route__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `path`
#include "hive_interface2/msg/lanelet_mini2.h"
// Member `path`
#include "hive_interface2/msg/detail/lanelet_mini2__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hive_interface2__srv__ComputeRoute_Response__init(message_memory);
}

void hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_fini_function(void * message_memory)
{
  hive_interface2__srv__ComputeRoute_Response__fini(message_memory);
}

size_t hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__size_function__ComputeRoute_Response__path(
  const void * untyped_member)
{
  const hive_interface2__msg__LaneletMini2__Sequence * member =
    (const hive_interface2__msg__LaneletMini2__Sequence *)(untyped_member);
  return member->size;
}

const void * hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Response__path(
  const void * untyped_member, size_t index)
{
  const hive_interface2__msg__LaneletMini2__Sequence * member =
    (const hive_interface2__msg__LaneletMini2__Sequence *)(untyped_member);
  return &member->data[index];
}

void * hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Response__path(
  void * untyped_member, size_t index)
{
  hive_interface2__msg__LaneletMini2__Sequence * member =
    (hive_interface2__msg__LaneletMini2__Sequence *)(untyped_member);
  return &member->data[index];
}

void hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__fetch_function__ComputeRoute_Response__path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const hive_interface2__msg__LaneletMini2 * item =
    ((const hive_interface2__msg__LaneletMini2 *)
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Response__path(untyped_member, index));
  hive_interface2__msg__LaneletMini2 * value =
    (hive_interface2__msg__LaneletMini2 *)(untyped_value);
  *value = *item;
}

void hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__assign_function__ComputeRoute_Response__path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  hive_interface2__msg__LaneletMini2 * item =
    ((hive_interface2__msg__LaneletMini2 *)
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Response__path(untyped_member, index));
  const hive_interface2__msg__LaneletMini2 * value =
    (const hive_interface2__msg__LaneletMini2 *)(untyped_value);
  *item = *value;
}

bool hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__resize_function__ComputeRoute_Response__path(
  void * untyped_member, size_t size)
{
  hive_interface2__msg__LaneletMini2__Sequence * member =
    (hive_interface2__msg__LaneletMini2__Sequence *)(untyped_member);
  hive_interface2__msg__LaneletMini2__Sequence__fini(member);
  return hive_interface2__msg__LaneletMini2__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_member_array[5] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Response, path),  // bytes offset in struct
    NULL,  // default value
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__size_function__ComputeRoute_Response__path,  // size() function pointer
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Response__path,  // get_const(index) function pointer
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Response__path,  // get(index) function pointer
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__fetch_function__ComputeRoute_Response__path,  // fetch(index, &value) function pointer
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__assign_function__ComputeRoute_Response__path,  // assign(index, value) function pointer
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__resize_function__ComputeRoute_Response__path  // resize(index) function pointer
  },
  {
    "total_distance_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Response, total_distance_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "estimated_time_s",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Response, estimated_time_s),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_members = {
  "hive_interface2__srv",  // message namespace
  "ComputeRoute_Response",  // message name
  5,  // number of fields
  sizeof(hive_interface2__srv__ComputeRoute_Response),
  false,  // has_any_key_member_
  hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_member_array,  // message members
  hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_type_support_handle = {
  0,
  &hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_members,
  get_message_typesupport_handle_function,
  &hive_interface2__srv__ComputeRoute_Response__get_type_hash,
  &hive_interface2__srv__ComputeRoute_Response__get_type_description,
  &hive_interface2__srv__ComputeRoute_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hive_interface2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Response)() {
  hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, msg, LaneletMini2)();
  if (!hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_type_support_handle.typesupport_identifier) {
    hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hive_interface2/srv/detail/compute_route__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hive_interface2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hive_interface2/srv/detail/compute_route__functions.h"
// already included above
// #include "hive_interface2/srv/detail/compute_route__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "hive_interface2/srv/compute_route.h"
// Member `request`
// Member `response`
// already included above
// #include "hive_interface2/srv/detail/compute_route__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hive_interface2__srv__ComputeRoute_Event__init(message_memory);
}

void hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_fini_function(void * message_memory)
{
  hive_interface2__srv__ComputeRoute_Event__fini(message_memory);
}

size_t hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__size_function__ComputeRoute_Event__request(
  const void * untyped_member)
{
  const hive_interface2__srv__ComputeRoute_Request__Sequence * member =
    (const hive_interface2__srv__ComputeRoute_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Event__request(
  const void * untyped_member, size_t index)
{
  const hive_interface2__srv__ComputeRoute_Request__Sequence * member =
    (const hive_interface2__srv__ComputeRoute_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Event__request(
  void * untyped_member, size_t index)
{
  hive_interface2__srv__ComputeRoute_Request__Sequence * member =
    (hive_interface2__srv__ComputeRoute_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__fetch_function__ComputeRoute_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const hive_interface2__srv__ComputeRoute_Request * item =
    ((const hive_interface2__srv__ComputeRoute_Request *)
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Event__request(untyped_member, index));
  hive_interface2__srv__ComputeRoute_Request * value =
    (hive_interface2__srv__ComputeRoute_Request *)(untyped_value);
  *value = *item;
}

void hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__assign_function__ComputeRoute_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  hive_interface2__srv__ComputeRoute_Request * item =
    ((hive_interface2__srv__ComputeRoute_Request *)
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Event__request(untyped_member, index));
  const hive_interface2__srv__ComputeRoute_Request * value =
    (const hive_interface2__srv__ComputeRoute_Request *)(untyped_value);
  *item = *value;
}

bool hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__resize_function__ComputeRoute_Event__request(
  void * untyped_member, size_t size)
{
  hive_interface2__srv__ComputeRoute_Request__Sequence * member =
    (hive_interface2__srv__ComputeRoute_Request__Sequence *)(untyped_member);
  hive_interface2__srv__ComputeRoute_Request__Sequence__fini(member);
  return hive_interface2__srv__ComputeRoute_Request__Sequence__init(member, size);
}

size_t hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__size_function__ComputeRoute_Event__response(
  const void * untyped_member)
{
  const hive_interface2__srv__ComputeRoute_Response__Sequence * member =
    (const hive_interface2__srv__ComputeRoute_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Event__response(
  const void * untyped_member, size_t index)
{
  const hive_interface2__srv__ComputeRoute_Response__Sequence * member =
    (const hive_interface2__srv__ComputeRoute_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Event__response(
  void * untyped_member, size_t index)
{
  hive_interface2__srv__ComputeRoute_Response__Sequence * member =
    (hive_interface2__srv__ComputeRoute_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__fetch_function__ComputeRoute_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const hive_interface2__srv__ComputeRoute_Response * item =
    ((const hive_interface2__srv__ComputeRoute_Response *)
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Event__response(untyped_member, index));
  hive_interface2__srv__ComputeRoute_Response * value =
    (hive_interface2__srv__ComputeRoute_Response *)(untyped_value);
  *value = *item;
}

void hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__assign_function__ComputeRoute_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  hive_interface2__srv__ComputeRoute_Response * item =
    ((hive_interface2__srv__ComputeRoute_Response *)
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Event__response(untyped_member, index));
  const hive_interface2__srv__ComputeRoute_Response * value =
    (const hive_interface2__srv__ComputeRoute_Response *)(untyped_value);
  *item = *value;
}

bool hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__resize_function__ComputeRoute_Event__response(
  void * untyped_member, size_t size)
{
  hive_interface2__srv__ComputeRoute_Response__Sequence * member =
    (hive_interface2__srv__ComputeRoute_Response__Sequence *)(untyped_member);
  hive_interface2__srv__ComputeRoute_Response__Sequence__fini(member);
  return hive_interface2__srv__ComputeRoute_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Event, request),  // bytes offset in struct
    NULL,  // default value
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__size_function__ComputeRoute_Event__request,  // size() function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Event__request,  // get_const(index) function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Event__request,  // get(index) function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__fetch_function__ComputeRoute_Event__request,  // fetch(index, &value) function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__assign_function__ComputeRoute_Event__request,  // assign(index, value) function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__resize_function__ComputeRoute_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(hive_interface2__srv__ComputeRoute_Event, response),  // bytes offset in struct
    NULL,  // default value
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__size_function__ComputeRoute_Event__response,  // size() function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_const_function__ComputeRoute_Event__response,  // get_const(index) function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__get_function__ComputeRoute_Event__response,  // get(index) function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__fetch_function__ComputeRoute_Event__response,  // fetch(index, &value) function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__assign_function__ComputeRoute_Event__response,  // assign(index, value) function pointer
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__resize_function__ComputeRoute_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_members = {
  "hive_interface2__srv",  // message namespace
  "ComputeRoute_Event",  // message name
  3,  // number of fields
  sizeof(hive_interface2__srv__ComputeRoute_Event),
  false,  // has_any_key_member_
  hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_member_array,  // message members
  hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_type_support_handle = {
  0,
  &hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_members,
  get_message_typesupport_handle_function,
  &hive_interface2__srv__ComputeRoute_Event__get_type_hash,
  &hive_interface2__srv__ComputeRoute_Event__get_type_description,
  &hive_interface2__srv__ComputeRoute_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hive_interface2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Event)() {
  hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Request)();
  hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Response)();
  if (!hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_type_support_handle.typesupport_identifier) {
    hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hive_interface2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hive_interface2/srv/detail/compute_route__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_service_members = {
  "hive_interface2__srv",  // service namespace
  "ComputeRoute",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_type_support_handle,
  NULL,  // response message
  // hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_type_support_handle
  NULL  // event_message
  // hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_type_support_handle
};


static rosidl_service_type_support_t hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_service_type_support_handle = {
  0,
  &hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_service_members,
  get_service_typesupport_handle_function,
  &hive_interface2__srv__ComputeRoute_Request__rosidl_typesupport_introspection_c__ComputeRoute_Request_message_type_support_handle,
  &hive_interface2__srv__ComputeRoute_Response__rosidl_typesupport_introspection_c__ComputeRoute_Response_message_type_support_handle,
  &hive_interface2__srv__ComputeRoute_Event__rosidl_typesupport_introspection_c__ComputeRoute_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    hive_interface2,
    srv,
    ComputeRoute
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    hive_interface2,
    srv,
    ComputeRoute
  ),
  &hive_interface2__srv__ComputeRoute__get_type_hash,
  &hive_interface2__srv__ComputeRoute__get_type_description,
  &hive_interface2__srv__ComputeRoute__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hive_interface2
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute)(void) {
  if (!hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_service_type_support_handle.typesupport_identifier) {
    hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, srv, ComputeRoute_Event)()->data;
  }

  return &hive_interface2__srv__detail__compute_route__rosidl_typesupport_introspection_c__ComputeRoute_service_type_support_handle;
}
