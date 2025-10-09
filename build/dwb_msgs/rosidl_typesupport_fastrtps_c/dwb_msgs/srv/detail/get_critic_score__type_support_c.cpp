// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dwb_msgs:srv/GetCriticScore.idl
// generated code does not contain a copyright notice
#include "dwb_msgs/srv/detail/get_critic_score__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dwb_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dwb_msgs/srv/detail/get_critic_score__struct.h"
#include "dwb_msgs/srv/detail/get_critic_score__functions.h"
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

#include "dwb_msgs/msg/detail/trajectory2_d__functions.h"  // traj
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"  // pose
#include "nav_2d_msgs/msg/detail/twist2_d__functions.h"  // velocity
#include "nav_msgs/msg/detail/path__functions.h"  // global_plan
#include "rosidl_runtime_c/string.h"  // critic_name
#include "rosidl_runtime_c/string_functions.h"  // critic_name

// forward declare type support functions

bool cdr_serialize_dwb_msgs__msg__Trajectory2D(
  const dwb_msgs__msg__Trajectory2D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_dwb_msgs__msg__Trajectory2D(
  eprosima::fastcdr::Cdr & cdr,
  dwb_msgs__msg__Trajectory2D * ros_message);

size_t get_serialized_size_dwb_msgs__msg__Trajectory2D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__Trajectory2D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_dwb_msgs__msg__Trajectory2D(
  const dwb_msgs__msg__Trajectory2D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_dwb_msgs__msg__Trajectory2D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_dwb_msgs__msg__Trajectory2D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, msg, Trajectory2D)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_serialize_geometry_msgs__msg__PoseStamped(
  const geometry_msgs__msg__PoseStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_deserialize_geometry_msgs__msg__PoseStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PoseStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t get_serialized_size_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t max_serialized_size_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_serialize_key_geometry_msgs__msg__PoseStamped(
  const geometry_msgs__msg__PoseStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t get_serialized_size_key_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t max_serialized_size_key_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PoseStamped)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_serialize_nav_2d_msgs__msg__Twist2D(
  const nav_2d_msgs__msg__Twist2D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_deserialize_nav_2d_msgs__msg__Twist2D(
  eprosima::fastcdr::Cdr & cdr,
  nav_2d_msgs__msg__Twist2D * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t get_serialized_size_nav_2d_msgs__msg__Twist2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t max_serialized_size_nav_2d_msgs__msg__Twist2D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_serialize_key_nav_2d_msgs__msg__Twist2D(
  const nav_2d_msgs__msg__Twist2D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t get_serialized_size_key_nav_2d_msgs__msg__Twist2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t max_serialized_size_key_nav_2d_msgs__msg__Twist2D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_2d_msgs, msg, Twist2D)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_serialize_nav_msgs__msg__Path(
  const nav_msgs__msg__Path * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_deserialize_nav_msgs__msg__Path(
  eprosima::fastcdr::Cdr & cdr,
  nav_msgs__msg__Path * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t get_serialized_size_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t max_serialized_size_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_serialize_key_nav_msgs__msg__Path(
  const nav_msgs__msg__Path * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t get_serialized_size_key_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t max_serialized_size_key_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path)();


using _GetCriticScore_Request__ros_msg_type = dwb_msgs__srv__GetCriticScore_Request;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_serialize_dwb_msgs__srv__GetCriticScore_Request(
  const dwb_msgs__srv__GetCriticScore_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: pose
  {
    cdr_serialize_geometry_msgs__msg__PoseStamped(
      &ros_message->pose, cdr);
  }

  // Field name: velocity
  {
    cdr_serialize_nav_2d_msgs__msg__Twist2D(
      &ros_message->velocity, cdr);
  }

  // Field name: global_plan
  {
    cdr_serialize_nav_msgs__msg__Path(
      &ros_message->global_plan, cdr);
  }

  // Field name: traj
  {
    cdr_serialize_dwb_msgs__msg__Trajectory2D(
      &ros_message->traj, cdr);
  }

  // Field name: critic_name
  {
    const rosidl_runtime_c__String * str = &ros_message->critic_name;
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

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_deserialize_dwb_msgs__srv__GetCriticScore_Request(
  eprosima::fastcdr::Cdr & cdr,
  dwb_msgs__srv__GetCriticScore_Request * ros_message)
{
  // Field name: pose
  {
    cdr_deserialize_geometry_msgs__msg__PoseStamped(cdr, &ros_message->pose);
  }

  // Field name: velocity
  {
    cdr_deserialize_nav_2d_msgs__msg__Twist2D(cdr, &ros_message->velocity);
  }

  // Field name: global_plan
  {
    cdr_deserialize_nav_msgs__msg__Path(cdr, &ros_message->global_plan);
  }

  // Field name: traj
  {
    cdr_deserialize_dwb_msgs__msg__Trajectory2D(cdr, &ros_message->traj);
  }

  // Field name: critic_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->critic_name.data) {
      rosidl_runtime_c__String__init(&ros_message->critic_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->critic_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'critic_name'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetCriticScore_Request__ros_msg_type * ros_message = static_cast<const _GetCriticScore_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: pose
  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->pose), current_alignment);

  // Field name: velocity
  current_alignment += get_serialized_size_nav_2d_msgs__msg__Twist2D(
    &(ros_message->velocity), current_alignment);

  // Field name: global_plan
  current_alignment += get_serialized_size_nav_msgs__msg__Path(
    &(ros_message->global_plan), current_alignment);

  // Field name: traj
  current_alignment += get_serialized_size_dwb_msgs__msg__Trajectory2D(
    &(ros_message->traj), current_alignment);

  // Field name: critic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->critic_name.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
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

  // Field name: pose
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

  // Field name: velocity
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_2d_msgs__msg__Twist2D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: global_plan
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: traj
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_dwb_msgs__msg__Trajectory2D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: critic_name
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


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dwb_msgs__srv__GetCriticScore_Request;
    is_plain =
      (
      offsetof(DataType, critic_name) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_serialize_key_dwb_msgs__srv__GetCriticScore_Request(
  const dwb_msgs__srv__GetCriticScore_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: pose
  {
    cdr_serialize_key_geometry_msgs__msg__PoseStamped(
      &ros_message->pose, cdr);
  }

  // Field name: velocity
  {
    cdr_serialize_key_nav_2d_msgs__msg__Twist2D(
      &ros_message->velocity, cdr);
  }

  // Field name: global_plan
  {
    cdr_serialize_key_nav_msgs__msg__Path(
      &ros_message->global_plan, cdr);
  }

  // Field name: traj
  {
    cdr_serialize_key_dwb_msgs__msg__Trajectory2D(
      &ros_message->traj, cdr);
  }

  // Field name: critic_name
  {
    const rosidl_runtime_c__String * str = &ros_message->critic_name;
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

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_key_dwb_msgs__srv__GetCriticScore_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetCriticScore_Request__ros_msg_type * ros_message = static_cast<const _GetCriticScore_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: pose
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PoseStamped(
    &(ros_message->pose), current_alignment);

  // Field name: velocity
  current_alignment += get_serialized_size_key_nav_2d_msgs__msg__Twist2D(
    &(ros_message->velocity), current_alignment);

  // Field name: global_plan
  current_alignment += get_serialized_size_key_nav_msgs__msg__Path(
    &(ros_message->global_plan), current_alignment);

  // Field name: traj
  current_alignment += get_serialized_size_key_dwb_msgs__msg__Trajectory2D(
    &(ros_message->traj), current_alignment);

  // Field name: critic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->critic_name.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_key_dwb_msgs__srv__GetCriticScore_Request(
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
  // Field name: pose
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

  // Field name: velocity
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_2d_msgs__msg__Twist2D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: global_plan
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: traj
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_dwb_msgs__msg__Trajectory2D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: critic_name
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dwb_msgs__srv__GetCriticScore_Request;
    is_plain =
      (
      offsetof(DataType, critic_name) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GetCriticScore_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const dwb_msgs__srv__GetCriticScore_Request * ros_message = static_cast<const dwb_msgs__srv__GetCriticScore_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_dwb_msgs__srv__GetCriticScore_Request(ros_message, cdr);
}

static bool _GetCriticScore_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  dwb_msgs__srv__GetCriticScore_Request * ros_message = static_cast<dwb_msgs__srv__GetCriticScore_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_dwb_msgs__srv__GetCriticScore_Request(cdr, ros_message);
}

static uint32_t _GetCriticScore_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
      untyped_ros_message, 0));
}

static size_t _GetCriticScore_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GetCriticScore_Request = {
  "dwb_msgs::srv",
  "GetCriticScore_Request",
  _GetCriticScore_Request__cdr_serialize,
  _GetCriticScore_Request__cdr_deserialize,
  _GetCriticScore_Request__get_serialized_size,
  _GetCriticScore_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GetCriticScore_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetCriticScore_Request,
  get_message_typesupport_handle_function,
  &dwb_msgs__srv__GetCriticScore_Request__get_type_hash,
  &dwb_msgs__srv__GetCriticScore_Request__get_type_description,
  &dwb_msgs__srv__GetCriticScore_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, srv, GetCriticScore_Request)() {
  return &_GetCriticScore_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "dwb_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "dwb_msgs/srv/detail/get_critic_score__struct.h"
// already included above
// #include "dwb_msgs/srv/detail/get_critic_score__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "dwb_msgs/msg/detail/critic_score__functions.h"  // score

// forward declare type support functions

bool cdr_serialize_dwb_msgs__msg__CriticScore(
  const dwb_msgs__msg__CriticScore * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_dwb_msgs__msg__CriticScore(
  eprosima::fastcdr::Cdr & cdr,
  dwb_msgs__msg__CriticScore * ros_message);

size_t get_serialized_size_dwb_msgs__msg__CriticScore(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__msg__CriticScore(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_dwb_msgs__msg__CriticScore(
  const dwb_msgs__msg__CriticScore * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_dwb_msgs__msg__CriticScore(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_dwb_msgs__msg__CriticScore(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, msg, CriticScore)();


using _GetCriticScore_Response__ros_msg_type = dwb_msgs__srv__GetCriticScore_Response;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_serialize_dwb_msgs__srv__GetCriticScore_Response(
  const dwb_msgs__srv__GetCriticScore_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: score
  {
    cdr_serialize_dwb_msgs__msg__CriticScore(
      &ros_message->score, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_deserialize_dwb_msgs__srv__GetCriticScore_Response(
  eprosima::fastcdr::Cdr & cdr,
  dwb_msgs__srv__GetCriticScore_Response * ros_message)
{
  // Field name: score
  {
    cdr_deserialize_dwb_msgs__msg__CriticScore(cdr, &ros_message->score);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetCriticScore_Response__ros_msg_type * ros_message = static_cast<const _GetCriticScore_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: score
  current_alignment += get_serialized_size_dwb_msgs__msg__CriticScore(
    &(ros_message->score), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
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

  // Field name: score
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_dwb_msgs__msg__CriticScore(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dwb_msgs__srv__GetCriticScore_Response;
    is_plain =
      (
      offsetof(DataType, score) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_serialize_key_dwb_msgs__srv__GetCriticScore_Response(
  const dwb_msgs__srv__GetCriticScore_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: score
  {
    cdr_serialize_key_dwb_msgs__msg__CriticScore(
      &ros_message->score, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_key_dwb_msgs__srv__GetCriticScore_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetCriticScore_Response__ros_msg_type * ros_message = static_cast<const _GetCriticScore_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: score
  current_alignment += get_serialized_size_key_dwb_msgs__msg__CriticScore(
    &(ros_message->score), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_key_dwb_msgs__srv__GetCriticScore_Response(
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
  // Field name: score
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_dwb_msgs__msg__CriticScore(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dwb_msgs__srv__GetCriticScore_Response;
    is_plain =
      (
      offsetof(DataType, score) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GetCriticScore_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const dwb_msgs__srv__GetCriticScore_Response * ros_message = static_cast<const dwb_msgs__srv__GetCriticScore_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_dwb_msgs__srv__GetCriticScore_Response(ros_message, cdr);
}

static bool _GetCriticScore_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  dwb_msgs__srv__GetCriticScore_Response * ros_message = static_cast<dwb_msgs__srv__GetCriticScore_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_dwb_msgs__srv__GetCriticScore_Response(cdr, ros_message);
}

static uint32_t _GetCriticScore_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
      untyped_ros_message, 0));
}

static size_t _GetCriticScore_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GetCriticScore_Response = {
  "dwb_msgs::srv",
  "GetCriticScore_Response",
  _GetCriticScore_Response__cdr_serialize,
  _GetCriticScore_Response__cdr_deserialize,
  _GetCriticScore_Response__get_serialized_size,
  _GetCriticScore_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GetCriticScore_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetCriticScore_Response,
  get_message_typesupport_handle_function,
  &dwb_msgs__srv__GetCriticScore_Response__get_type_hash,
  &dwb_msgs__srv__GetCriticScore_Response__get_type_description,
  &dwb_msgs__srv__GetCriticScore_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, srv, GetCriticScore_Response)() {
  return &_GetCriticScore_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "dwb_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "dwb_msgs/srv/detail/get_critic_score__struct.h"
// already included above
// #include "dwb_msgs/srv/detail/get_critic_score__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions

bool cdr_serialize_dwb_msgs__srv__GetCriticScore_Request(
  const dwb_msgs__srv__GetCriticScore_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_dwb_msgs__srv__GetCriticScore_Request(
  eprosima::fastcdr::Cdr & cdr,
  dwb_msgs__srv__GetCriticScore_Request * ros_message);

size_t get_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_dwb_msgs__srv__GetCriticScore_Request(
  const dwb_msgs__srv__GetCriticScore_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_dwb_msgs__srv__GetCriticScore_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_dwb_msgs__srv__GetCriticScore_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, srv, GetCriticScore_Request)();

bool cdr_serialize_dwb_msgs__srv__GetCriticScore_Response(
  const dwb_msgs__srv__GetCriticScore_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_dwb_msgs__srv__GetCriticScore_Response(
  eprosima::fastcdr::Cdr & cdr,
  dwb_msgs__srv__GetCriticScore_Response * ros_message);

size_t get_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_dwb_msgs__srv__GetCriticScore_Response(
  const dwb_msgs__srv__GetCriticScore_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_dwb_msgs__srv__GetCriticScore_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_dwb_msgs__srv__GetCriticScore_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, srv, GetCriticScore_Response)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_serialize_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_deserialize_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
bool cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
size_t max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dwb_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();


using _GetCriticScore_Event__ros_msg_type = dwb_msgs__srv__GetCriticScore_Event;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_serialize_dwb_msgs__srv__GetCriticScore_Event(
  const dwb_msgs__srv__GetCriticScore_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_dwb_msgs__srv__GetCriticScore_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_dwb_msgs__srv__GetCriticScore_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_deserialize_dwb_msgs__srv__GetCriticScore_Event(
  eprosima::fastcdr::Cdr & cdr,
  dwb_msgs__srv__GetCriticScore_Event * ros_message)
{
  // Field name: info
  {
    cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->request.data) {
      dwb_msgs__srv__GetCriticScore_Request__Sequence__fini(&ros_message->request);
    }
    if (!dwb_msgs__srv__GetCriticScore_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_dwb_msgs__srv__GetCriticScore_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->response.data) {
      dwb_msgs__srv__GetCriticScore_Response__Sequence__fini(&ros_message->response);
    }
    if (!dwb_msgs__srv__GetCriticScore_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_dwb_msgs__srv__GetCriticScore_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_dwb_msgs__srv__GetCriticScore_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetCriticScore_Event__ros_msg_type * ros_message = static_cast<const _GetCriticScore_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_dwb_msgs__srv__GetCriticScore_Event(
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

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_dwb_msgs__srv__GetCriticScore_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_dwb_msgs__srv__GetCriticScore_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dwb_msgs__srv__GetCriticScore_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
bool cdr_serialize_key_dwb_msgs__srv__GetCriticScore_Event(
  const dwb_msgs__srv__GetCriticScore_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_dwb_msgs__srv__GetCriticScore_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_dwb_msgs__srv__GetCriticScore_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t get_serialized_size_key_dwb_msgs__srv__GetCriticScore_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetCriticScore_Event__ros_msg_type * ros_message = static_cast<const _GetCriticScore_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_dwb_msgs__srv__GetCriticScore_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_dwb_msgs__srv__GetCriticScore_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dwb_msgs
size_t max_serialized_size_key_dwb_msgs__srv__GetCriticScore_Event(
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
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_dwb_msgs__srv__GetCriticScore_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_dwb_msgs__srv__GetCriticScore_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dwb_msgs__srv__GetCriticScore_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GetCriticScore_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const dwb_msgs__srv__GetCriticScore_Event * ros_message = static_cast<const dwb_msgs__srv__GetCriticScore_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_dwb_msgs__srv__GetCriticScore_Event(ros_message, cdr);
}

static bool _GetCriticScore_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  dwb_msgs__srv__GetCriticScore_Event * ros_message = static_cast<dwb_msgs__srv__GetCriticScore_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_dwb_msgs__srv__GetCriticScore_Event(cdr, ros_message);
}

static uint32_t _GetCriticScore_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dwb_msgs__srv__GetCriticScore_Event(
      untyped_ros_message, 0));
}

static size_t _GetCriticScore_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dwb_msgs__srv__GetCriticScore_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GetCriticScore_Event = {
  "dwb_msgs::srv",
  "GetCriticScore_Event",
  _GetCriticScore_Event__cdr_serialize,
  _GetCriticScore_Event__cdr_deserialize,
  _GetCriticScore_Event__get_serialized_size,
  _GetCriticScore_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GetCriticScore_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetCriticScore_Event,
  get_message_typesupport_handle_function,
  &dwb_msgs__srv__GetCriticScore_Event__get_type_hash,
  &dwb_msgs__srv__GetCriticScore_Event__get_type_description,
  &dwb_msgs__srv__GetCriticScore_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, srv, GetCriticScore_Event)() {
  return &_GetCriticScore_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "dwb_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dwb_msgs/srv/get_critic_score.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetCriticScore__callbacks = {
  "dwb_msgs::srv",
  "GetCriticScore",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, srv, GetCriticScore_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, srv, GetCriticScore_Response)(),
};

static rosidl_service_type_support_t GetCriticScore__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &GetCriticScore__callbacks,
  get_service_typesupport_handle_function,
  &_GetCriticScore_Request__type_support,
  &_GetCriticScore_Response__type_support,
  &_GetCriticScore_Event__type_support,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    dwb_msgs,
    srv,
    GetCriticScore
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    dwb_msgs,
    srv,
    GetCriticScore
  ),
  &dwb_msgs__srv__GetCriticScore__get_type_hash,
  &dwb_msgs__srv__GetCriticScore__get_type_description,
  &dwb_msgs__srv__GetCriticScore__get_type_description_sources,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dwb_msgs, srv, GetCriticScore)() {
  return &GetCriticScore__handle;
}

#if defined(__cplusplus)
}
#endif
