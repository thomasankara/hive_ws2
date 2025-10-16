// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hive_interface2:msg/PoiArray.idl
// generated code does not contain a copyright notice

#include "hive_interface2/msg/detail/poi_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__msg__PoiArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe2, 0xf0, 0xb5, 0x9a, 0xfd, 0x03, 0xbc, 0x1d,
      0x13, 0x6b, 0x8e, 0x70, 0xd8, 0xbd, 0x46, 0x02,
      0xbd, 0x67, 0x40, 0x29, 0xb7, 0xa4, 0x86, 0x16,
      0x7a, 0x8d, 0x38, 0x3d, 0xca, 0x2e, 0x7e, 0x0d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "hive_interface2/msg/detail/poi__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t hive_interface2__msg__Poi__EXPECTED_HASH = {1, {
    0xfd, 0xaf, 0xa0, 0xdb, 0x28, 0x22, 0xee, 0x37,
    0x36, 0xbd, 0x94, 0x89, 0xa8, 0xfb, 0x40, 0x58,
    0xcb, 0x44, 0x56, 0x5f, 0xd7, 0x1d, 0x03, 0x5b,
    0xba, 0x1c, 0xb7, 0x47, 0x94, 0xe5, 0xc8, 0x17,
  }};
#endif

static char hive_interface2__msg__PoiArray__TYPE_NAME[] = "hive_interface2/msg/PoiArray";
static char hive_interface2__msg__Poi__TYPE_NAME[] = "hive_interface2/msg/Poi";

// Define type names, field names, and default values
static char hive_interface2__msg__PoiArray__FIELD_NAME__items[] = "items";

static rosidl_runtime_c__type_description__Field hive_interface2__msg__PoiArray__FIELDS[] = {
  {
    {hive_interface2__msg__PoiArray__FIELD_NAME__items, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {hive_interface2__msg__Poi__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hive_interface2__msg__PoiArray__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {hive_interface2__msg__Poi__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__msg__PoiArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__msg__PoiArray__TYPE_NAME, 28, 28},
      {hive_interface2__msg__PoiArray__FIELDS, 1, 1},
    },
    {hive_interface2__msg__PoiArray__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&hive_interface2__msg__Poi__EXPECTED_HASH, hive_interface2__msg__Poi__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = hive_interface2__msg__Poi__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "hive_interface2/Poi[] items";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__msg__PoiArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__msg__PoiArray__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 28, 28},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__msg__PoiArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__msg__PoiArray__get_individual_type_description_source(NULL),
    sources[1] = *hive_interface2__msg__Poi__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
