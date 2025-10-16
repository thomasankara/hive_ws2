// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice
#include "hive_interface2/msg/detail/poi__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hive_interface2/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hive_interface2/msg/detail/poi__struct.h"
#include "hive_interface2/msg/detail/poi__functions.h"
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

#include "rosidl_runtime_c/string.h"  // deployment_full_id_str, enterprise_full_id_str, free_zone_full_id_str, poi_full_id_str, slam_session_full_id_str
#include "rosidl_runtime_c/string_functions.h"  // deployment_full_id_str, enterprise_full_id_str, free_zone_full_id_str, poi_full_id_str, slam_session_full_id_str

// forward declare type support functions


using _Poi__ros_msg_type = hive_interface2__msg__Poi;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_serialize_hive_interface2__msg__Poi(
  const hive_interface2__msg__Poi * ros_message,
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

  // Field name: free_zone_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->free_zone_full_id_str;
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

  // Field name: is_in_free_zone
  {
    cdr << ros_message->is_in_free_zone;
  }

  // Field name: poi_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->poi_full_id_str;
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

  // Field name: poi_id
  {
    cdr << ros_message->poi_id;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  // Field name: parking_mode
  {
    cdr << ros_message->parking_mode;
  }

  // Field name: is_available
  {
    cdr << ros_message->is_available;
  }

  // Field name: charging_mode
  {
    cdr << ros_message->charging_mode;
  }

  // Field name: is_long_wait_zone
  {
    cdr << ros_message->is_long_wait_zone;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_deserialize_hive_interface2__msg__Poi(
  eprosima::fastcdr::Cdr & cdr,
  hive_interface2__msg__Poi * ros_message)
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

  // Field name: free_zone_full_id_str
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->free_zone_full_id_str.data) {
      rosidl_runtime_c__String__init(&ros_message->free_zone_full_id_str);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->free_zone_full_id_str,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'free_zone_full_id_str'\n");
      return false;
    }
  }

  // Field name: is_in_free_zone
  {
    cdr >> ros_message->is_in_free_zone;
  }

  // Field name: poi_full_id_str
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->poi_full_id_str.data) {
      rosidl_runtime_c__String__init(&ros_message->poi_full_id_str);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->poi_full_id_str,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'poi_full_id_str'\n");
      return false;
    }
  }

  // Field name: poi_id
  {
    cdr >> ros_message->poi_id;
  }

  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: z
  {
    cdr >> ros_message->z;
  }

  // Field name: yaw
  {
    cdr >> ros_message->yaw;
  }

  // Field name: parking_mode
  {
    cdr >> ros_message->parking_mode;
  }

  // Field name: is_available
  {
    cdr >> ros_message->is_available;
  }

  // Field name: charging_mode
  {
    cdr >> ros_message->charging_mode;
  }

  // Field name: is_long_wait_zone
  {
    cdr >> ros_message->is_long_wait_zone;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t get_serialized_size_hive_interface2__msg__Poi(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Poi__ros_msg_type * ros_message = static_cast<const _Poi__ros_msg_type *>(untyped_ros_message);
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

  // Field name: free_zone_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->free_zone_full_id_str.size + 1);

  // Field name: is_in_free_zone
  {
    size_t item_size = sizeof(ros_message->is_in_free_zone);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: poi_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->poi_full_id_str.size + 1);

  // Field name: poi_id
  {
    size_t item_size = sizeof(ros_message->poi_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: parking_mode
  {
    size_t item_size = sizeof(ros_message->parking_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: is_available
  {
    size_t item_size = sizeof(ros_message->is_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: charging_mode
  {
    size_t item_size = sizeof(ros_message->charging_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: is_long_wait_zone
  {
    size_t item_size = sizeof(ros_message->is_long_wait_zone);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t max_serialized_size_hive_interface2__msg__Poi(
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

  // Field name: free_zone_full_id_str
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

  // Field name: is_in_free_zone
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: poi_full_id_str
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

  // Field name: poi_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: parking_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: is_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: charging_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: is_long_wait_zone
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
    using DataType = hive_interface2__msg__Poi;
    is_plain =
      (
      offsetof(DataType, is_long_wait_zone) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_serialize_key_hive_interface2__msg__Poi(
  const hive_interface2__msg__Poi * ros_message,
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

  // Field name: free_zone_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->free_zone_full_id_str;
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

  // Field name: is_in_free_zone
  {
    cdr << ros_message->is_in_free_zone;
  }

  // Field name: poi_full_id_str
  {
    const rosidl_runtime_c__String * str = &ros_message->poi_full_id_str;
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

  // Field name: poi_id
  {
    cdr << ros_message->poi_id;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  // Field name: parking_mode
  {
    cdr << ros_message->parking_mode;
  }

  // Field name: is_available
  {
    cdr << ros_message->is_available;
  }

  // Field name: charging_mode
  {
    cdr << ros_message->charging_mode;
  }

  // Field name: is_long_wait_zone
  {
    cdr << ros_message->is_long_wait_zone;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t get_serialized_size_key_hive_interface2__msg__Poi(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Poi__ros_msg_type * ros_message = static_cast<const _Poi__ros_msg_type *>(untyped_ros_message);
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

  // Field name: free_zone_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->free_zone_full_id_str.size + 1);

  // Field name: is_in_free_zone
  {
    size_t item_size = sizeof(ros_message->is_in_free_zone);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: poi_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->poi_full_id_str.size + 1);

  // Field name: poi_id
  {
    size_t item_size = sizeof(ros_message->poi_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: parking_mode
  {
    size_t item_size = sizeof(ros_message->parking_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: is_available
  {
    size_t item_size = sizeof(ros_message->is_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: charging_mode
  {
    size_t item_size = sizeof(ros_message->charging_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: is_long_wait_zone
  {
    size_t item_size = sizeof(ros_message->is_long_wait_zone);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t max_serialized_size_key_hive_interface2__msg__Poi(
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

  // Field name: free_zone_full_id_str
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

  // Field name: is_in_free_zone
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: poi_full_id_str
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

  // Field name: poi_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: parking_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: is_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: charging_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: is_long_wait_zone
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
    using DataType = hive_interface2__msg__Poi;
    is_plain =
      (
      offsetof(DataType, is_long_wait_zone) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Poi__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const hive_interface2__msg__Poi * ros_message = static_cast<const hive_interface2__msg__Poi *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_hive_interface2__msg__Poi(ros_message, cdr);
}

static bool _Poi__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  hive_interface2__msg__Poi * ros_message = static_cast<hive_interface2__msg__Poi *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_hive_interface2__msg__Poi(cdr, ros_message);
}

static uint32_t _Poi__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hive_interface2__msg__Poi(
      untyped_ros_message, 0));
}

static size_t _Poi__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_hive_interface2__msg__Poi(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Poi = {
  "hive_interface2::msg",
  "Poi",
  _Poi__cdr_serialize,
  _Poi__cdr_deserialize,
  _Poi__get_serialized_size,
  _Poi__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Poi__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Poi,
  get_message_typesupport_handle_function,
  &hive_interface2__msg__Poi__get_type_hash,
  &hive_interface2__msg__Poi__get_type_description,
  &hive_interface2__msg__Poi__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hive_interface2, msg, Poi)() {
  return &_Poi__type_support;
}

#if defined(__cplusplus)
}
#endif
