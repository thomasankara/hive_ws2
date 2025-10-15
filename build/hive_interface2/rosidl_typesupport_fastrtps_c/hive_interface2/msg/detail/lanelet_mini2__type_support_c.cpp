// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hive_interface2:msg/LaneletMini2.idl
// generated code does not contain a copyright notice
#include "hive_interface2/msg/detail/lanelet_mini2__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hive_interface2/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hive_interface2/msg/detail/lanelet_mini2__struct.h"
#include "hive_interface2/msg/detail/lanelet_mini2__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // configuration_group_id_str, deployment_full_id_str, enterprise_full_id_str, road_group_id_str, slam_session_full_id_str
#include "rosidl_runtime_c/string_functions.h"  // configuration_group_id_str, deployment_full_id_str, enterprise_full_id_str, road_group_id_str, slam_session_full_id_str

// forward declare type support functions


using _LaneletMini2__ros_msg_type = hive_interface2__msg__LaneletMini2;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_serialize_hive_interface2__msg__LaneletMini2(
  const hive_interface2__msg__LaneletMini2 * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: enterprise_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->enterprise_full_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: deployment_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->deployment_full_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: slam_session_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->slam_session_full_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: lanelet_mini_id
  {
    cdr << ros_message->lanelet_mini_id;
  }

  // Field name: start_point_x
  {
    cdr << ros_message->start_point_x;
  }

  // Field name: start_point_y
  {
    cdr << ros_message->start_point_y;
  }

  // Field name: start_point_z
  {
    cdr << ros_message->start_point_z;
  }

  // Field name: end_point_x
  {
    cdr << ros_message->end_point_x;
  }

  // Field name: end_point_y
  {
    cdr << ros_message->end_point_y;
  }

  // Field name: end_point_z
  {
    cdr << ros_message->end_point_z;
  }

  // Field name: navigation_direction
  {
    cdr << ros_message->navigation_direction;
  }

  // Field name: border_mode
  {
    cdr << ros_message->border_mode;
  }

  // Field name: u_turn_allowed
  {
    cdr << (ros_message->u_turn_allowed ? true : false);
  }

  // Field name: slope_alert
  {
    cdr << (ros_message->slope_alert ? true : false);
  }

  // Field name: vegetation_alert
  {
    cdr << (ros_message->vegetation_alert ? true : false);
  }

  // Field name: offroad_alert
  {
    cdr << (ros_message->offroad_alert ? true : false);
  }

  // Field name: configuration_group_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->configuration_group_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: road_group_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->road_group_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: max_speed
  {
    cdr << ros_message->max_speed;
  }

  // Field name: width
  {
    cdr << ros_message->width;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_deserialize_hive_interface2__msg__LaneletMini2(
  eprosima::fastcdr::Cdr & cdr,
  hive_interface2__msg__LaneletMini2 * ros_message)
{
  // Field name: enterprise_full_id_str
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->enterprise_full_id_str.data) {
      rosidl_runtime_c__String__init(&ros_message->enterprise_full_id_str);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->enterprise_full_id_str,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'enterprise_full_id_str'\n");
      return false;
    }
  }

  // Field name: deployment_full_id_str
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->deployment_full_id_str.data) {
      rosidl_runtime_c__String__init(&ros_message->deployment_full_id_str);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->deployment_full_id_str,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'deployment_full_id_str'\n");
      return false;
    }
  }

  // Field name: slam_session_full_id_str
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->slam_session_full_id_str.data) {
      rosidl_runtime_c__String__init(&ros_message->slam_session_full_id_str);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->slam_session_full_id_str,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'slam_session_full_id_str'\n");
      return false;
    }
  }

  // Field name: lanelet_mini_id
  {
    cdr >> ros_message->lanelet_mini_id;
  }

  // Field name: start_point_x
  {
    cdr >> ros_message->start_point_x;
  }

  // Field name: start_point_y
  {
    cdr >> ros_message->start_point_y;
  }

  // Field name: start_point_z
  {
    cdr >> ros_message->start_point_z;
  }

  // Field name: end_point_x
  {
    cdr >> ros_message->end_point_x;
  }

  // Field name: end_point_y
  {
    cdr >> ros_message->end_point_y;
  }

  // Field name: end_point_z
  {
    cdr >> ros_message->end_point_z;
  }

  // Field name: navigation_direction
  {
    cdr >> ros_message->navigation_direction;
  }

  // Field name: border_mode
  {
    cdr >> ros_message->border_mode;
  }

  // Field name: u_turn_allowed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->u_turn_allowed = tmp ? true : false;
  }

  // Field name: slope_alert
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->slope_alert = tmp ? true : false;
  }

  // Field name: vegetation_alert
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->vegetation_alert = tmp ? true : false;
  }

  // Field name: offroad_alert
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->offroad_alert = tmp ? true : false;
  }

  // Field name: configuration_group_id_str
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->configuration_group_id_str.data) {
      rosidl_runtime_c__String__init(&ros_message->configuration_group_id_str);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->configuration_group_id_str,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'configuration_group_id_str'\n");
      return false;
    }
  }

  // Field name: road_group_id_str
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->road_group_id_str.data) {
      rosidl_runtime_c__String__init(&ros_message->road_group_id_str);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->road_group_id_str,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'road_group_id_str'\n");
      return false;
    }
  }

  // Field name: max_speed
  {
    cdr >> ros_message->max_speed;
  }

  // Field name: width
  {
    cdr >> ros_message->width;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t get_serialized_size_hive_interface2__msg__LaneletMini2(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LaneletMini2__ros_msg_type * ros_message = static_cast<const _LaneletMini2__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: enterprise_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->enterprise_full_id_str.size + 1);

  // Field name: deployment_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->deployment_full_id_str.size + 1);

  // Field name: slam_session_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->slam_session_full_id_str.size + 1);

  // Field name: lanelet_mini_id
  {
    size_t item_size = sizeof(ros_message->lanelet_mini_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_point_x
  {
    size_t item_size = sizeof(ros_message->start_point_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_point_y
  {
    size_t item_size = sizeof(ros_message->start_point_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_point_z
  {
    size_t item_size = sizeof(ros_message->start_point_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_point_x
  {
    size_t item_size = sizeof(ros_message->end_point_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_point_y
  {
    size_t item_size = sizeof(ros_message->end_point_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_point_z
  {
    size_t item_size = sizeof(ros_message->end_point_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: navigation_direction
  {
    size_t item_size = sizeof(ros_message->navigation_direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: border_mode
  {
    size_t item_size = sizeof(ros_message->border_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: u_turn_allowed
  {
    size_t item_size = sizeof(ros_message->u_turn_allowed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: slope_alert
  {
    size_t item_size = sizeof(ros_message->slope_alert);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vegetation_alert
  {
    size_t item_size = sizeof(ros_message->vegetation_alert);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: offroad_alert
  {
    size_t item_size = sizeof(ros_message->offroad_alert);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: configuration_group_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->configuration_group_id_str.size + 1);

  // Field name: road_group_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->road_group_id_str.size + 1);

  // Field name: max_speed
  {
    size_t item_size = sizeof(ros_message->max_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: width
  {
    size_t item_size = sizeof(ros_message->width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t max_serialized_size_hive_interface2__msg__LaneletMini2(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: enterprise_full_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: deployment_full_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: slam_session_full_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: lanelet_mini_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_point_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_point_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_point_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_point_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_point_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_point_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: navigation_direction
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: border_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: u_turn_allowed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: slope_alert
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: vegetation_alert
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: offroad_alert
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: configuration_group_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: road_group_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: max_speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = hive_interface2__msg__LaneletMini2;
    is_plain =
      (
      offsetof(DataType, width) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_serialize_key_hive_interface2__msg__LaneletMini2(
  const hive_interface2__msg__LaneletMini2 * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: enterprise_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->enterprise_full_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: deployment_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->deployment_full_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: slam_session_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->slam_session_full_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: lanelet_mini_id
  {
    cdr << ros_message->lanelet_mini_id;
  }

  // Field name: start_point_x
  {
    cdr << ros_message->start_point_x;
  }

  // Field name: start_point_y
  {
    cdr << ros_message->start_point_y;
  }

  // Field name: start_point_z
  {
    cdr << ros_message->start_point_z;
  }

  // Field name: end_point_x
  {
    cdr << ros_message->end_point_x;
  }

  // Field name: end_point_y
  {
    cdr << ros_message->end_point_y;
  }

  // Field name: end_point_z
  {
    cdr << ros_message->end_point_z;
  }

  // Field name: navigation_direction
  {
    cdr << ros_message->navigation_direction;
  }

  // Field name: border_mode
  {
    cdr << ros_message->border_mode;
  }

  // Field name: u_turn_allowed
  {
    cdr << (ros_message->u_turn_allowed ? true : false);
  }

  // Field name: slope_alert
  {
    cdr << (ros_message->slope_alert ? true : false);
  }

  // Field name: vegetation_alert
  {
    cdr << (ros_message->vegetation_alert ? true : false);
  }

  // Field name: offroad_alert
  {
    cdr << (ros_message->offroad_alert ? true : false);
  }

  // Field name: configuration_group_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->configuration_group_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: road_group_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->road_group_id_str;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: max_speed
  {
    cdr << ros_message->max_speed;
  }

  // Field name: width
  {
    cdr << ros_message->width;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t get_serialized_size_key_hive_interface2__msg__LaneletMini2(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LaneletMini2__ros_msg_type * ros_message = static_cast<const _LaneletMini2__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: enterprise_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->enterprise_full_id_str.size + 1);

  // Field name: deployment_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->deployment_full_id_str.size + 1);

  // Field name: slam_session_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->slam_session_full_id_str.size + 1);

  // Field name: lanelet_mini_id
  {
    size_t item_size = sizeof(ros_message->lanelet_mini_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_point_x
  {
    size_t item_size = sizeof(ros_message->start_point_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_point_y
  {
    size_t item_size = sizeof(ros_message->start_point_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: start_point_z
  {
    size_t item_size = sizeof(ros_message->start_point_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_point_x
  {
    size_t item_size = sizeof(ros_message->end_point_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_point_y
  {
    size_t item_size = sizeof(ros_message->end_point_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: end_point_z
  {
    size_t item_size = sizeof(ros_message->end_point_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: navigation_direction
  {
    size_t item_size = sizeof(ros_message->navigation_direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: border_mode
  {
    size_t item_size = sizeof(ros_message->border_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: u_turn_allowed
  {
    size_t item_size = sizeof(ros_message->u_turn_allowed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: slope_alert
  {
    size_t item_size = sizeof(ros_message->slope_alert);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vegetation_alert
  {
    size_t item_size = sizeof(ros_message->vegetation_alert);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: offroad_alert
  {
    size_t item_size = sizeof(ros_message->offroad_alert);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: configuration_group_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->configuration_group_id_str.size + 1);

  // Field name: road_group_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->road_group_id_str.size + 1);

  // Field name: max_speed
  {
    size_t item_size = sizeof(ros_message->max_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: width
  {
    size_t item_size = sizeof(ros_message->width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t max_serialized_size_key_hive_interface2__msg__LaneletMini2(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: enterprise_full_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: deployment_full_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: slam_session_full_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: lanelet_mini_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_point_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_point_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: start_point_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_point_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_point_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: end_point_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: navigation_direction
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: border_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: u_turn_allowed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: slope_alert
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: vegetation_alert
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: offroad_alert
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: configuration_group_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: road_group_id_str
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: max_speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = hive_interface2__msg__LaneletMini2;
    is_plain =
      (
      offsetof(DataType, width) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _LaneletMini2__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const hive_interface2__msg__LaneletMini2 * ros_message = static_cast<const hive_interface2__msg__LaneletMini2 *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_hive_interface2__msg__LaneletMini2(ros_message, cdr);
}

static bool _LaneletMini2__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  hive_interface2__msg__LaneletMini2 * ros_message = static_cast<hive_interface2__msg__LaneletMini2 *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_hive_interface2__msg__LaneletMini2(cdr, ros_message);
}

static uint32_t _LaneletMini2__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hive_interface2__msg__LaneletMini2(
      untyped_ros_message, 0));
}

static size_t _LaneletMini2__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_hive_interface2__msg__LaneletMini2(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LaneletMini2 = {
  "hive_interface2::msg",
  "LaneletMini2",
  _LaneletMini2__cdr_serialize,
  _LaneletMini2__cdr_deserialize,
  _LaneletMini2__get_serialized_size,
  _LaneletMini2__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _LaneletMini2__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LaneletMini2,
  get_message_typesupport_handle_function,
  &hive_interface2__msg__LaneletMini2__get_type_hash,
  &hive_interface2__msg__LaneletMini2__get_type_description,
  &hive_interface2__msg__LaneletMini2__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hive_interface2, msg, LaneletMini2)() {
  return &_LaneletMini2__type_support;
}

#if defined(__cplusplus)
}
#endif
