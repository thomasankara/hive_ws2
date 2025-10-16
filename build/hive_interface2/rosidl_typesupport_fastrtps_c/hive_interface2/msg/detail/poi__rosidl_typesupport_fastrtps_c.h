// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice
#ifndef HIVE_INTERFACE2__MSG__DETAIL__POI__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define HIVE_INTERFACE2__MSG__DETAIL__POI__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "hive_interface2/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hive_interface2/msg/detail/poi__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_serialize_hive_interface2__msg__Poi(
  const hive_interface2__msg__Poi * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_deserialize_hive_interface2__msg__Poi(
  eprosima::fastcdr::Cdr &,
  hive_interface2__msg__Poi * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t get_serialized_size_hive_interface2__msg__Poi(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t max_serialized_size_hive_interface2__msg__Poi(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_serialize_key_hive_interface2__msg__Poi(
  const hive_interface2__msg__Poi * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t get_serialized_size_key_hive_interface2__msg__Poi(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t max_serialized_size_key_hive_interface2__msg__Poi(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hive_interface2, msg, Poi)();

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__POI__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
