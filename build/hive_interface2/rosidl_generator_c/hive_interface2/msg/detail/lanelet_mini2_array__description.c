// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hive_interface2:msg/LaneletMini2Array.idl
// generated code does not contain a copyright notice

#include "hive_interface2/msg/detail/lanelet_mini2_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__msg__LaneletMini2Array__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa9, 0xb5, 0x5e, 0x31, 0x22, 0xf1, 0x72, 0xa8,
      0x42, 0xff, 0x2f, 0x65, 0x1f, 0x4a, 0xa0, 0x47,
      0xd1, 0x45, 0x2e, 0x94, 0xbf, 0x05, 0xb3, 0x5f,
      0x92, 0xbd, 0xc9, 0x8a, 0xe8, 0xdc, 0x4c, 0xad,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "hive_interface2/msg/detail/lanelet_mini2__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t hive_interface2__msg__LaneletMini2__EXPECTED_HASH = {1, {
    0xff, 0xee, 0xac, 0x92, 0x17, 0x9b, 0xe1, 0xd2,
    0x53, 0xdb, 0xba, 0xcc, 0xf2, 0xe5, 0x36, 0xbd,
    0x33, 0x10, 0x8c, 0x8b, 0x5d, 0x14, 0xcf, 0x43,
    0xc4, 0xab, 0xfb, 0xa6, 0x3b, 0x83, 0xaa, 0x1a,
  }};
#endif

static char hive_interface2__msg__LaneletMini2Array__TYPE_NAME[] = "hive_interface2/msg/LaneletMini2Array";
static char hive_interface2__msg__LaneletMini2__TYPE_NAME[] = "hive_interface2/msg/LaneletMini2";

// Define type names, field names, and default values
static char hive_interface2__msg__LaneletMini2Array__FIELD_NAME__lanelets[] = "lanelets";

static rosidl_runtime_c__type_description__Field hive_interface2__msg__LaneletMini2Array__FIELDS[] = {
  {
    {hive_interface2__msg__LaneletMini2Array__FIELD_NAME__lanelets, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {hive_interface2__msg__LaneletMini2__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hive_interface2__msg__LaneletMini2Array__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {hive_interface2__msg__LaneletMini2__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__msg__LaneletMini2Array__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__msg__LaneletMini2Array__TYPE_NAME, 37, 37},
      {hive_interface2__msg__LaneletMini2Array__FIELDS, 1, 1},
    },
    {hive_interface2__msg__LaneletMini2Array__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&hive_interface2__msg__LaneletMini2__EXPECTED_HASH, hive_interface2__msg__LaneletMini2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = hive_interface2__msg__LaneletMini2__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ============================================================\n"
  "# Hive Robotics - LaneletMini2Array.msg\n"
  "# ============================================================\n"
  "# Repr\\xc3\\xa9sente un ensemble de LaneletMini2, utilis\\xc3\\xa9 pour transf\\xc3\\xa9rer\n"
  "# toute la base ou une s\\xc3\\xa9lection de lanelets.\n"
  "# ============================================================\n"
  "\n"
  "hive_interface2/LaneletMini2[] lanelets";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__msg__LaneletMini2Array__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__msg__LaneletMini2Array__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 382, 382},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__msg__LaneletMini2Array__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__msg__LaneletMini2Array__get_individual_type_description_source(NULL),
    sources[1] = *hive_interface2__msg__LaneletMini2__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
