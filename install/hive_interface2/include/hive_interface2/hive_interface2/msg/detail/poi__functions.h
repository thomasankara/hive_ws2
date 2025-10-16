// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/poi.h"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__POI__FUNCTIONS_H_
#define HIVE_INTERFACE2__MSG__DETAIL__POI__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "hive_interface2/msg/rosidl_generator_c__visibility_control.h"

#include "hive_interface2/msg/detail/poi__struct.h"

/// Initialize msg/Poi message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hive_interface2__msg__Poi
 * )) before or use
 * hive_interface2__msg__Poi__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
bool
hive_interface2__msg__Poi__init(hive_interface2__msg__Poi * msg);

/// Finalize msg/Poi message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
void
hive_interface2__msg__Poi__fini(hive_interface2__msg__Poi * msg);

/// Create msg/Poi message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hive_interface2__msg__Poi__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
hive_interface2__msg__Poi *
hive_interface2__msg__Poi__create(void);

/// Destroy msg/Poi message.
/**
 * It calls
 * hive_interface2__msg__Poi__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
void
hive_interface2__msg__Poi__destroy(hive_interface2__msg__Poi * msg);

/// Check for msg/Poi message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
bool
hive_interface2__msg__Poi__are_equal(const hive_interface2__msg__Poi * lhs, const hive_interface2__msg__Poi * rhs);

/// Copy a msg/Poi message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
bool
hive_interface2__msg__Poi__copy(
  const hive_interface2__msg__Poi * input,
  hive_interface2__msg__Poi * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__msg__Poi__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__msg__Poi__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__msg__Poi__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__msg__Poi__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/Poi messages.
/**
 * It allocates the memory for the number of elements and calls
 * hive_interface2__msg__Poi__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
bool
hive_interface2__msg__Poi__Sequence__init(hive_interface2__msg__Poi__Sequence * array, size_t size);

/// Finalize array of msg/Poi messages.
/**
 * It calls
 * hive_interface2__msg__Poi__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
void
hive_interface2__msg__Poi__Sequence__fini(hive_interface2__msg__Poi__Sequence * array);

/// Create array of msg/Poi messages.
/**
 * It allocates the memory for the array and calls
 * hive_interface2__msg__Poi__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
hive_interface2__msg__Poi__Sequence *
hive_interface2__msg__Poi__Sequence__create(size_t size);

/// Destroy array of msg/Poi messages.
/**
 * It calls
 * hive_interface2__msg__Poi__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
void
hive_interface2__msg__Poi__Sequence__destroy(hive_interface2__msg__Poi__Sequence * array);

/// Check for msg/Poi message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
bool
hive_interface2__msg__Poi__Sequence__are_equal(const hive_interface2__msg__Poi__Sequence * lhs, const hive_interface2__msg__Poi__Sequence * rhs);

/// Copy an array of msg/Poi messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
bool
hive_interface2__msg__Poi__Sequence__copy(
  const hive_interface2__msg__Poi__Sequence * input,
  hive_interface2__msg__Poi__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__POI__FUNCTIONS_H_
