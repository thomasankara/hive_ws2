// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from hive_interface2:msg/LaneletMini2Array.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "hive_interface2/msg/detail/lanelet_mini2_array__functions.h"
#include "hive_interface2/msg/detail/lanelet_mini2_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hive_interface2
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void LaneletMini2Array_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hive_interface2::msg::LaneletMini2Array(_init);
}

void LaneletMini2Array_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hive_interface2::msg::LaneletMini2Array *>(message_memory);
  typed_message->~LaneletMini2Array();
}

size_t size_function__LaneletMini2Array__lanelets(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<hive_interface2::msg::LaneletMini2> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LaneletMini2Array__lanelets(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<hive_interface2::msg::LaneletMini2> *>(untyped_member);
  return &member[index];
}

void * get_function__LaneletMini2Array__lanelets(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<hive_interface2::msg::LaneletMini2> *>(untyped_member);
  return &member[index];
}

void fetch_function__LaneletMini2Array__lanelets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const hive_interface2::msg::LaneletMini2 *>(
    get_const_function__LaneletMini2Array__lanelets(untyped_member, index));
  auto & value = *reinterpret_cast<hive_interface2::msg::LaneletMini2 *>(untyped_value);
  value = item;
}

void assign_function__LaneletMini2Array__lanelets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<hive_interface2::msg::LaneletMini2 *>(
    get_function__LaneletMini2Array__lanelets(untyped_member, index));
  const auto & value = *reinterpret_cast<const hive_interface2::msg::LaneletMini2 *>(untyped_value);
  item = value;
}

void resize_function__LaneletMini2Array__lanelets(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<hive_interface2::msg::LaneletMini2> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LaneletMini2Array_message_member_array[1] = {
  {
    "lanelets",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<hive_interface2::msg::LaneletMini2>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2::msg::LaneletMini2Array, lanelets),  // bytes offset in struct
    nullptr,  // default value
    size_function__LaneletMini2Array__lanelets,  // size() function pointer
    get_const_function__LaneletMini2Array__lanelets,  // get_const(index) function pointer
    get_function__LaneletMini2Array__lanelets,  // get(index) function pointer
    fetch_function__LaneletMini2Array__lanelets,  // fetch(index, &value) function pointer
    assign_function__LaneletMini2Array__lanelets,  // assign(index, value) function pointer
    resize_function__LaneletMini2Array__lanelets  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LaneletMini2Array_message_members = {
  "hive_interface2::msg",  // message namespace
  "LaneletMini2Array",  // message name
  1,  // number of fields
  sizeof(hive_interface2::msg::LaneletMini2Array),
  false,  // has_any_key_member_
  LaneletMini2Array_message_member_array,  // message members
  LaneletMini2Array_init_function,  // function to initialize message memory (memory has to be allocated)
  LaneletMini2Array_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LaneletMini2Array_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LaneletMini2Array_message_members,
  get_message_typesupport_handle_function,
  &hive_interface2__msg__LaneletMini2Array__get_type_hash,
  &hive_interface2__msg__LaneletMini2Array__get_type_description,
  &hive_interface2__msg__LaneletMini2Array__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace hive_interface2


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hive_interface2::msg::LaneletMini2Array>()
{
  return &::hive_interface2::msg::rosidl_typesupport_introspection_cpp::LaneletMini2Array_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hive_interface2, msg, LaneletMini2Array)() {
  return &::hive_interface2::msg::rosidl_typesupport_introspection_cpp::LaneletMini2Array_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
