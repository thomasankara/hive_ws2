// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from nav2_msgs:msg/RouteNode.idl
// generated code does not contain a copyright notice
#ifndef NAV2_MSGS__MSG__DETAIL__ROUTE_NODE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define NAV2_MSGS__MSG__DETAIL__ROUTE_NODE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "nav2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nav2_msgs/msg/detail/route_node__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav2_msgs
bool cdr_serialize_nav2_msgs__msg__RouteNode(
  const nav2_msgs__msg__RouteNode * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav2_msgs
bool cdr_deserialize_nav2_msgs__msg__RouteNode(
  eprosima::fastcdr::Cdr &,
  nav2_msgs__msg__RouteNode * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_nav2_msgs__msg__RouteNode(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_nav2_msgs__msg__RouteNode(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav2_msgs
bool cdr_serialize_key_nav2_msgs__msg__RouteNode(
  const nav2_msgs__msg__RouteNode * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav2_msgs
size_t get_serialized_size_key_nav2_msgs__msg__RouteNode(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav2_msgs
size_t max_serialized_size_key_nav2_msgs__msg__RouteNode(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav2_msgs, msg, RouteNode)();

#ifdef __cplusplus
}
#endif

#endif  // NAV2_MSGS__MSG__DETAIL__ROUTE_NODE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
