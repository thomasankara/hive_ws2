// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hive_interface2:msg/FreeZone.idl
// generated code does not contain a copyright notice
#include "hive_interface2/msg/detail/free_zone__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hive_interface2/msg/detail/free_zone__functions.h"
#include "hive_interface2/msg/detail/free_zone__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace hive_interface2
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hive_interface2
cdr_serialize(
  const hive_interface2::msg::FreeZone & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enterprise_full_id_str
  cdr << ros_message.enterprise_full_id_str;

  // Member: deployment_full_id_str
  cdr << ros_message.deployment_full_id_str;

  // Member: slam_session_full_id_str
  cdr << ros_message.slam_session_full_id_str;

  // Member: free_zone_full_id_str
  cdr << ros_message.free_zone_full_id_str;

  // Member: free_zone_id
  cdr << ros_message.free_zone_id;

  // Member: is_parking_available
  cdr << ros_message.is_parking_available;

  // Member: is_offpoi_parking_allowed
  cdr << ros_message.is_offpoi_parking_allowed;

  // Member: is_long_wait_zone
  cdr << ros_message.is_long_wait_zone;

  // Member: zone_polygon_points_json
  cdr << ros_message.zone_polygon_points_json;

  // Member: max_speed
  cdr << ros_message.max_speed;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hive_interface2
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hive_interface2::msg::FreeZone & ros_message)
{
  // Member: enterprise_full_id_str
  cdr >> ros_message.enterprise_full_id_str;

  // Member: deployment_full_id_str
  cdr >> ros_message.deployment_full_id_str;

  // Member: slam_session_full_id_str
  cdr >> ros_message.slam_session_full_id_str;

  // Member: free_zone_full_id_str
  cdr >> ros_message.free_zone_full_id_str;

  // Member: free_zone_id
  cdr >> ros_message.free_zone_id;

  // Member: is_parking_available
  cdr >> ros_message.is_parking_available;

  // Member: is_offpoi_parking_allowed
  cdr >> ros_message.is_offpoi_parking_allowed;

  // Member: is_long_wait_zone
  cdr >> ros_message.is_long_wait_zone;

  // Member: zone_polygon_points_json
  cdr >> ros_message.zone_polygon_points_json;

  // Member: max_speed
  cdr >> ros_message.max_speed;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hive_interface2
get_serialized_size(
  const hive_interface2::msg::FreeZone & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enterprise_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.enterprise_full_id_str.size() + 1);

  // Member: deployment_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.deployment_full_id_str.size() + 1);

  // Member: slam_session_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.slam_session_full_id_str.size() + 1);

  // Member: free_zone_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.free_zone_full_id_str.size() + 1);

  // Member: free_zone_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.free_zone_id.size() + 1);

  // Member: is_parking_available
  {
    size_t item_size = sizeof(ros_message.is_parking_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: is_offpoi_parking_allowed
  {
    size_t item_size = sizeof(ros_message.is_offpoi_parking_allowed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: is_long_wait_zone
  {
    size_t item_size = sizeof(ros_message.is_long_wait_zone);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: zone_polygon_points_json
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.zone_polygon_points_json.size() + 1);

  // Member: max_speed
  {
    size_t item_size = sizeof(ros_message.max_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hive_interface2
max_serialized_size_FreeZone(
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

  // Member: enterprise_full_id_str
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
  // Member: deployment_full_id_str
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
  // Member: slam_session_full_id_str
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
  // Member: free_zone_full_id_str
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
  // Member: free_zone_id
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
  // Member: is_parking_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: is_offpoi_parking_allowed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: is_long_wait_zone
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: zone_polygon_points_json
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
  // Member: max_speed
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
    using DataType = hive_interface2::msg::FreeZone;
    is_plain =
      (
      offsetof(DataType, max_speed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hive_interface2
cdr_serialize_key(
  const hive_interface2::msg::FreeZone & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enterprise_full_id_str
  cdr << ros_message.enterprise_full_id_str;

  // Member: deployment_full_id_str
  cdr << ros_message.deployment_full_id_str;

  // Member: slam_session_full_id_str
  cdr << ros_message.slam_session_full_id_str;

  // Member: free_zone_full_id_str
  cdr << ros_message.free_zone_full_id_str;

  // Member: free_zone_id
  cdr << ros_message.free_zone_id;

  // Member: is_parking_available
  cdr << ros_message.is_parking_available;

  // Member: is_offpoi_parking_allowed
  cdr << ros_message.is_offpoi_parking_allowed;

  // Member: is_long_wait_zone
  cdr << ros_message.is_long_wait_zone;

  // Member: zone_polygon_points_json
  cdr << ros_message.zone_polygon_points_json;

  // Member: max_speed
  cdr << ros_message.max_speed;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hive_interface2
get_serialized_size_key(
  const hive_interface2::msg::FreeZone & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enterprise_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.enterprise_full_id_str.size() + 1);

  // Member: deployment_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.deployment_full_id_str.size() + 1);

  // Member: slam_session_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.slam_session_full_id_str.size() + 1);

  // Member: free_zone_full_id_str
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.free_zone_full_id_str.size() + 1);

  // Member: free_zone_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.free_zone_id.size() + 1);

  // Member: is_parking_available
  {
    size_t item_size = sizeof(ros_message.is_parking_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: is_offpoi_parking_allowed
  {
    size_t item_size = sizeof(ros_message.is_offpoi_parking_allowed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: is_long_wait_zone
  {
    size_t item_size = sizeof(ros_message.is_long_wait_zone);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: zone_polygon_points_json
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.zone_polygon_points_json.size() + 1);

  // Member: max_speed
  {
    size_t item_size = sizeof(ros_message.max_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hive_interface2
max_serialized_size_key_FreeZone(
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

  // Member: enterprise_full_id_str
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

  // Member: deployment_full_id_str
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

  // Member: slam_session_full_id_str
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

  // Member: free_zone_full_id_str
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

  // Member: free_zone_id
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

  // Member: is_parking_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: is_offpoi_parking_allowed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: is_long_wait_zone
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: zone_polygon_points_json
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

  // Member: max_speed
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
    using DataType = hive_interface2::msg::FreeZone;
    is_plain =
      (
      offsetof(DataType, max_speed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _FreeZone__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hive_interface2::msg::FreeZone *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FreeZone__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hive_interface2::msg::FreeZone *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FreeZone__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hive_interface2::msg::FreeZone *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FreeZone__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FreeZone(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FreeZone__callbacks = {
  "hive_interface2::msg",
  "FreeZone",
  _FreeZone__cdr_serialize,
  _FreeZone__cdr_deserialize,
  _FreeZone__get_serialized_size,
  _FreeZone__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _FreeZone__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FreeZone__callbacks,
  get_message_typesupport_handle_function,
  &hive_interface2__msg__FreeZone__get_type_hash,
  &hive_interface2__msg__FreeZone__get_type_description,
  &hive_interface2__msg__FreeZone__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hive_interface2

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hive_interface2
const rosidl_message_type_support_t *
get_message_type_support_handle<hive_interface2::msg::FreeZone>()
{
  return &hive_interface2::msg::typesupport_fastrtps_cpp::_FreeZone__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hive_interface2, msg, FreeZone)() {
  return &hive_interface2::msg::typesupport_fastrtps_cpp::_FreeZone__handle;
}

#ifdef __cplusplus
}
#endif
