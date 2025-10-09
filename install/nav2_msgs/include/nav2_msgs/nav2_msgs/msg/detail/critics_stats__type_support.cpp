// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from nav2_msgs:msg/CriticsStats.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "nav2_msgs/msg/detail/critics_stats__functions.h"
#include "nav2_msgs/msg/detail/critics_stats__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace nav2_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CriticsStats_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nav2_msgs::msg::CriticsStats(_init);
}

void CriticsStats_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nav2_msgs::msg::CriticsStats *>(message_memory);
  typed_message->~CriticsStats();
}

size_t size_function__CriticsStats__critics(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CriticsStats__critics(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__CriticsStats__critics(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__CriticsStats__critics(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__CriticsStats__critics(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__CriticsStats__critics(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__CriticsStats__critics(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__CriticsStats__critics(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CriticsStats__changed(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<bool> *>(untyped_member);
  return member->size();
}

void fetch_function__CriticsStats__changed(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & member = *reinterpret_cast<const std::vector<bool> *>(untyped_member);
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = member[index];
}

void assign_function__CriticsStats__changed(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & member = *reinterpret_cast<std::vector<bool> *>(untyped_member);
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  member[index] = value;
}

void resize_function__CriticsStats__changed(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<bool> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CriticsStats__costs_sum(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CriticsStats__costs_sum(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__CriticsStats__costs_sum(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__CriticsStats__costs_sum(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__CriticsStats__costs_sum(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__CriticsStats__costs_sum(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__CriticsStats__costs_sum(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__CriticsStats__costs_sum(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CriticsStats_message_member_array[4] = {
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav2_msgs::msg::CriticsStats, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "critics",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav2_msgs::msg::CriticsStats, critics),  // bytes offset in struct
    nullptr,  // default value
    size_function__CriticsStats__critics,  // size() function pointer
    get_const_function__CriticsStats__critics,  // get_const(index) function pointer
    get_function__CriticsStats__critics,  // get(index) function pointer
    fetch_function__CriticsStats__critics,  // fetch(index, &value) function pointer
    assign_function__CriticsStats__critics,  // assign(index, value) function pointer
    resize_function__CriticsStats__critics  // resize(index) function pointer
  },
  {
    "changed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav2_msgs::msg::CriticsStats, changed),  // bytes offset in struct
    nullptr,  // default value
    size_function__CriticsStats__changed,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    fetch_function__CriticsStats__changed,  // fetch(index, &value) function pointer
    assign_function__CriticsStats__changed,  // assign(index, value) function pointer
    resize_function__CriticsStats__changed  // resize(index) function pointer
  },
  {
    "costs_sum",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav2_msgs::msg::CriticsStats, costs_sum),  // bytes offset in struct
    nullptr,  // default value
    size_function__CriticsStats__costs_sum,  // size() function pointer
    get_const_function__CriticsStats__costs_sum,  // get_const(index) function pointer
    get_function__CriticsStats__costs_sum,  // get(index) function pointer
    fetch_function__CriticsStats__costs_sum,  // fetch(index, &value) function pointer
    assign_function__CriticsStats__costs_sum,  // assign(index, value) function pointer
    resize_function__CriticsStats__costs_sum  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CriticsStats_message_members = {
  "nav2_msgs::msg",  // message namespace
  "CriticsStats",  // message name
  4,  // number of fields
  sizeof(nav2_msgs::msg::CriticsStats),
  false,  // has_any_key_member_
  CriticsStats_message_member_array,  // message members
  CriticsStats_init_function,  // function to initialize message memory (memory has to be allocated)
  CriticsStats_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CriticsStats_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CriticsStats_message_members,
  get_message_typesupport_handle_function,
  &nav2_msgs__msg__CriticsStats__get_type_hash,
  &nav2_msgs__msg__CriticsStats__get_type_description,
  &nav2_msgs__msg__CriticsStats__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace nav2_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::msg::CriticsStats>()
{
  return &::nav2_msgs::msg::rosidl_typesupport_introspection_cpp::CriticsStats_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav2_msgs, msg, CriticsStats)() {
  return &::nav2_msgs::msg::rosidl_typesupport_introspection_cpp::CriticsStats_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
