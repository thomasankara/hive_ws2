// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hive_interface2:msg/LaneletMini2Array.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hive_interface2/msg/detail/lanelet_mini2_array__rosidl_typesupport_introspection_c.h"
#include "hive_interface2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hive_interface2/msg/detail/lanelet_mini2_array__functions.h"
#include "hive_interface2/msg/detail/lanelet_mini2_array__struct.h"


// Include directives for member types
// Member `lanelets`
#include "hive_interface2/msg/lanelet_mini2.h"
// Member `lanelets`
#include "hive_interface2/msg/detail/lanelet_mini2__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hive_interface2__msg__LaneletMini2Array__init(message_memory);
}

void hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_fini_function(void * message_memory)
{
  hive_interface2__msg__LaneletMini2Array__fini(message_memory);
}

size_t hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__size_function__LaneletMini2Array__lanelets(
  const void * untyped_member)
{
  const hive_interface2__msg__LaneletMini2__Sequence * member =
    (const hive_interface2__msg__LaneletMini2__Sequence *)(untyped_member);
  return member->size;
}

const void * hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__get_const_function__LaneletMini2Array__lanelets(
  const void * untyped_member, size_t index)
{
  const hive_interface2__msg__LaneletMini2__Sequence * member =
    (const hive_interface2__msg__LaneletMini2__Sequence *)(untyped_member);
  return &member->data[index];
}

void * hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__get_function__LaneletMini2Array__lanelets(
  void * untyped_member, size_t index)
{
  hive_interface2__msg__LaneletMini2__Sequence * member =
    (hive_interface2__msg__LaneletMini2__Sequence *)(untyped_member);
  return &member->data[index];
}

void hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__fetch_function__LaneletMini2Array__lanelets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const hive_interface2__msg__LaneletMini2 * item =
    ((const hive_interface2__msg__LaneletMini2 *)
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__get_const_function__LaneletMini2Array__lanelets(untyped_member, index));
  hive_interface2__msg__LaneletMini2 * value =
    (hive_interface2__msg__LaneletMini2 *)(untyped_value);
  *value = *item;
}

void hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__assign_function__LaneletMini2Array__lanelets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  hive_interface2__msg__LaneletMini2 * item =
    ((hive_interface2__msg__LaneletMini2 *)
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__get_function__LaneletMini2Array__lanelets(untyped_member, index));
  const hive_interface2__msg__LaneletMini2 * value =
    (const hive_interface2__msg__LaneletMini2 *)(untyped_value);
  *item = *value;
}

bool hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__resize_function__LaneletMini2Array__lanelets(
  void * untyped_member, size_t size)
{
  hive_interface2__msg__LaneletMini2__Sequence * member =
    (hive_interface2__msg__LaneletMini2__Sequence *)(untyped_member);
  hive_interface2__msg__LaneletMini2__Sequence__fini(member);
  return hive_interface2__msg__LaneletMini2__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_member_array[1] = {
  {
    "lanelets",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hive_interface2__msg__LaneletMini2Array, lanelets),  // bytes offset in struct
    NULL,  // default value
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__size_function__LaneletMini2Array__lanelets,  // size() function pointer
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__get_const_function__LaneletMini2Array__lanelets,  // get_const(index) function pointer
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__get_function__LaneletMini2Array__lanelets,  // get(index) function pointer
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__fetch_function__LaneletMini2Array__lanelets,  // fetch(index, &value) function pointer
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__assign_function__LaneletMini2Array__lanelets,  // assign(index, value) function pointer
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__resize_function__LaneletMini2Array__lanelets  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_members = {
  "hive_interface2__msg",  // message namespace
  "LaneletMini2Array",  // message name
  1,  // number of fields
  sizeof(hive_interface2__msg__LaneletMini2Array),
  false,  // has_any_key_member_
  hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_member_array,  // message members
  hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_init_function,  // function to initialize message memory (memory has to be allocated)
  hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_type_support_handle = {
  0,
  &hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_members,
  get_message_typesupport_handle_function,
  &hive_interface2__msg__LaneletMini2Array__get_type_hash,
  &hive_interface2__msg__LaneletMini2Array__get_type_description,
  &hive_interface2__msg__LaneletMini2Array__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hive_interface2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, msg, LaneletMini2Array)() {
  hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hive_interface2, msg, LaneletMini2)();
  if (!hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_type_support_handle.typesupport_identifier) {
    hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hive_interface2__msg__LaneletMini2Array__rosidl_typesupport_introspection_c__LaneletMini2Array_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
