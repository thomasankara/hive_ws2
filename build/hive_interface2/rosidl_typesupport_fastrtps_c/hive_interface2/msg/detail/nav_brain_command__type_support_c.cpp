// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hive_interface2:msg/NavBrainCommand.idl
// generated code does not contain a copyright notice
#include "hive_interface2/msg/detail/nav_brain_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hive_interface2/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hive_interface2/msg/detail/nav_brain_command__struct.h"
#include "hive_interface2/msg/detail/nav_brain_command__functions.h"
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

#include "geometry_msgs/msg/detail/pose_stamped__functions.h"  // destination

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hive_interface2
bool cdr_serialize_geometry_msgs__msg__PoseStamped(
  const geometry_msgs__msg__PoseStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hive_interface2
bool cdr_deserialize_geometry_msgs__msg__PoseStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PoseStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hive_interface2
size_t get_serialized_size_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hive_interface2
size_t max_serialized_size_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hive_interface2
bool cdr_serialize_key_geometry_msgs__msg__PoseStamped(
  const geometry_msgs__msg__PoseStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hive_interface2
size_t get_serialized_size_key_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hive_interface2
size_t max_serialized_size_key_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hive_interface2
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PoseStamped)();


using _NavBrainCommand__ros_msg_type = hive_interface2__msg__NavBrainCommand;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_serialize_hive_interface2__msg__NavBrainCommand(
  const hive_interface2__msg__NavBrainCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: free_zone_id
  {
    cdr << ros_message->free_zone_id;
  }

  // Field name: poi_id
  {
    cdr << ros_message->poi_id;
  }

  // Field name: destination
  {
    cdr_serialize_geometry_msgs__msg__PoseStamped(
      &ros_message->destination, cdr);
  }

  // Field name: object_tracking_id
  {
    cdr << ros_message->object_tracking_id;
  }

  // Field name: mission_id
  {
    cdr << ros_message->mission_id;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_deserialize_hive_interface2__msg__NavBrainCommand(
  eprosima::fastcdr::Cdr & cdr,
  hive_interface2__msg__NavBrainCommand * ros_message)
{
  // Field name: free_zone_id
  {
    cdr >> ros_message->free_zone_id;
  }

  // Field name: poi_id
  {
    cdr >> ros_message->poi_id;
  }

  // Field name: destination
  {
    cdr_deserialize_geometry_msgs__msg__PoseStamped(cdr, &ros_message->destination);
  }

  // Field name: object_tracking_id
  {
    cdr >> ros_message->object_tracking_id;
  }

  // Field name: mission_id
  {
    cdr >> ros_message->mission_id;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t get_serialized_size_hive_interface2__msg__NavBrainCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavBrainCommand__ros_msg_type * ros_message = static_cast<const _NavBrainCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: free_zone_id
  {
    size_t item_size = sizeof(ros_message->free_zone_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: poi_id
  {
    size_t item_size = sizeof(ros_message->poi_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: destination
  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->destination), current_alignment);

  // Field name: object_tracking_id
  {
    size_t item_size = sizeof(ros_message->object_tracking_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mission_id
  {
    size_t item_size = sizeof(ros_message->mission_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t max_serialized_size_hive_interface2__msg__NavBrainCommand(
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

  // Field name: free_zone_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: poi_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: destination
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: object_tracking_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mission_id
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
    using DataType = hive_interface2__msg__NavBrainCommand;
    is_plain =
      (
      offsetof(DataType, mission_id) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
bool cdr_serialize_key_hive_interface2__msg__NavBrainCommand(
  const hive_interface2__msg__NavBrainCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: free_zone_id
  {
    cdr << ros_message->free_zone_id;
  }

  // Field name: poi_id
  {
    cdr << ros_message->poi_id;
  }

  // Field name: destination
  {
    cdr_serialize_key_geometry_msgs__msg__PoseStamped(
      &ros_message->destination, cdr);
  }

  // Field name: object_tracking_id
  {
    cdr << ros_message->object_tracking_id;
  }

  // Field name: mission_id
  {
    cdr << ros_message->mission_id;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t get_serialized_size_key_hive_interface2__msg__NavBrainCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavBrainCommand__ros_msg_type * ros_message = static_cast<const _NavBrainCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: free_zone_id
  {
    size_t item_size = sizeof(ros_message->free_zone_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: poi_id
  {
    size_t item_size = sizeof(ros_message->poi_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: destination
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PoseStamped(
    &(ros_message->destination), current_alignment);

  // Field name: object_tracking_id
  {
    size_t item_size = sizeof(ros_message->object_tracking_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mission_id
  {
    size_t item_size = sizeof(ros_message->mission_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hive_interface2
size_t max_serialized_size_key_hive_interface2__msg__NavBrainCommand(
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
  // Field name: free_zone_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: poi_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: destination
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: object_tracking_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mission_id
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
    using DataType = hive_interface2__msg__NavBrainCommand;
    is_plain =
      (
      offsetof(DataType, mission_id) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _NavBrainCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const hive_interface2__msg__NavBrainCommand * ros_message = static_cast<const hive_interface2__msg__NavBrainCommand *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_hive_interface2__msg__NavBrainCommand(ros_message, cdr);
}

static bool _NavBrainCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  hive_interface2__msg__NavBrainCommand * ros_message = static_cast<hive_interface2__msg__NavBrainCommand *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_hive_interface2__msg__NavBrainCommand(cdr, ros_message);
}

static uint32_t _NavBrainCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hive_interface2__msg__NavBrainCommand(
      untyped_ros_message, 0));
}

static size_t _NavBrainCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_hive_interface2__msg__NavBrainCommand(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NavBrainCommand = {
  "hive_interface2::msg",
  "NavBrainCommand",
  _NavBrainCommand__cdr_serialize,
  _NavBrainCommand__cdr_deserialize,
  _NavBrainCommand__get_serialized_size,
  _NavBrainCommand__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _NavBrainCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavBrainCommand,
  get_message_typesupport_handle_function,
  &hive_interface2__msg__NavBrainCommand__get_type_hash,
  &hive_interface2__msg__NavBrainCommand__get_type_description,
  &hive_interface2__msg__NavBrainCommand__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hive_interface2, msg, NavBrainCommand)() {
  return &_NavBrainCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
