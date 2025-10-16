// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hive_interface2:msg/FreeZoneArray.idl
// generated code does not contain a copyright notice

#include "hive_interface2/msg/detail/free_zone_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__msg__FreeZoneArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa5, 0x9b, 0x78, 0x4c, 0xb5, 0x55, 0xcd, 0x87,
      0xfa, 0xa5, 0x2c, 0x62, 0xd2, 0x3c, 0x70, 0x30,
      0x49, 0xd0, 0x90, 0x42, 0xcd, 0x53, 0xe7, 0x51,
      0x41, 0x30, 0x3b, 0xcf, 0x2b, 0x60, 0x15, 0x72,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "hive_interface2/msg/detail/free_zone__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t hive_interface2__msg__FreeZone__EXPECTED_HASH = {1, {
    0xad, 0xcf, 0xa7, 0xff, 0xa6, 0xa1, 0x9a, 0xa8,
    0xed, 0x99, 0xaf, 0x23, 0xb1, 0x8d, 0x04, 0xe5,
    0x13, 0xf7, 0x6f, 0x65, 0x86, 0x07, 0x66, 0x4e,
    0xf6, 0xc7, 0xd6, 0xe3, 0xc2, 0x99, 0x91, 0xba,
  }};
#endif

static char hive_interface2__msg__FreeZoneArray__TYPE_NAME[] = "hive_interface2/msg/FreeZoneArray";
static char hive_interface2__msg__FreeZone__TYPE_NAME[] = "hive_interface2/msg/FreeZone";

// Define type names, field names, and default values
static char hive_interface2__msg__FreeZoneArray__FIELD_NAME__items[] = "items";

static rosidl_runtime_c__type_description__Field hive_interface2__msg__FreeZoneArray__FIELDS[] = {
  {
    {hive_interface2__msg__FreeZoneArray__FIELD_NAME__items, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {hive_interface2__msg__FreeZone__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hive_interface2__msg__FreeZoneArray__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {hive_interface2__msg__FreeZone__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__msg__FreeZoneArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__msg__FreeZoneArray__TYPE_NAME, 33, 33},
      {hive_interface2__msg__FreeZoneArray__FIELDS, 1, 1},
    },
    {hive_interface2__msg__FreeZoneArray__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&hive_interface2__msg__FreeZone__EXPECTED_HASH, hive_interface2__msg__FreeZone__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = hive_interface2__msg__FreeZone__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "hive_interface2/FreeZone[] items";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__msg__FreeZoneArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__msg__FreeZoneArray__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 33, 33},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__msg__FreeZoneArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__msg__FreeZoneArray__get_individual_type_description_source(NULL),
    sources[1] = *hive_interface2__msg__FreeZone__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
