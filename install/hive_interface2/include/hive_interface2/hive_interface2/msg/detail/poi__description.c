// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice

#include "hive_interface2/msg/detail/poi__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__msg__Poi__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfd, 0xaf, 0xa0, 0xdb, 0x28, 0x22, 0xee, 0x37,
      0x36, 0xbd, 0x94, 0x89, 0xa8, 0xfb, 0x40, 0x58,
      0xcb, 0x44, 0x56, 0x5f, 0xd7, 0x1d, 0x03, 0x5b,
      0xba, 0x1c, 0xb7, 0x47, 0x94, 0xe5, 0xc8, 0x17,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char hive_interface2__msg__Poi__TYPE_NAME[] = "hive_interface2/msg/Poi";

// Define type names, field names, and default values
static char hive_interface2__msg__Poi__FIELD_NAME__enterprise_full_id_str[] = "enterprise_full_id_str";
static char hive_interface2__msg__Poi__FIELD_NAME__deployment_full_id_str[] = "deployment_full_id_str";
static char hive_interface2__msg__Poi__FIELD_NAME__slam_session_full_id_str[] = "slam_session_full_id_str";
static char hive_interface2__msg__Poi__FIELD_NAME__free_zone_full_id_str[] = "free_zone_full_id_str";
static char hive_interface2__msg__Poi__FIELD_NAME__is_in_free_zone[] = "is_in_free_zone";
static char hive_interface2__msg__Poi__FIELD_NAME__poi_full_id_str[] = "poi_full_id_str";
static char hive_interface2__msg__Poi__FIELD_NAME__poi_id[] = "poi_id";
static char hive_interface2__msg__Poi__FIELD_NAME__x[] = "x";
static char hive_interface2__msg__Poi__FIELD_NAME__y[] = "y";
static char hive_interface2__msg__Poi__FIELD_NAME__z[] = "z";
static char hive_interface2__msg__Poi__FIELD_NAME__yaw[] = "yaw";
static char hive_interface2__msg__Poi__FIELD_NAME__parking_mode[] = "parking_mode";
static char hive_interface2__msg__Poi__FIELD_NAME__is_available[] = "is_available";
static char hive_interface2__msg__Poi__FIELD_NAME__charging_mode[] = "charging_mode";
static char hive_interface2__msg__Poi__FIELD_NAME__is_long_wait_zone[] = "is_long_wait_zone";

static rosidl_runtime_c__type_description__Field hive_interface2__msg__Poi__FIELDS[] = {
  {
    {hive_interface2__msg__Poi__FIELD_NAME__enterprise_full_id_str, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__deployment_full_id_str, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__slam_session_full_id_str, 24, 24},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__free_zone_full_id_str, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__is_in_free_zone, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__poi_full_id_str, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__poi_id, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__parking_mode, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__is_available, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__charging_mode, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__Poi__FIELD_NAME__is_long_wait_zone, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__msg__Poi__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__msg__Poi__TYPE_NAME, 23, 23},
      {hive_interface2__msg__Poi__FIELDS, 15, 15},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# POI issu de la table SQL `poi`\n"
  "string enterprise_full_id_str\n"
  "string deployment_full_id_str\n"
  "string slam_session_full_id_str\n"
  "\n"
  "string free_zone_full_id_str\n"
  "int32  is_in_free_zone\n"
  "\n"
  "string poi_full_id_str\n"
  "int32  poi_id\n"
  "\n"
  "float32 x\n"
  "float32 y\n"
  "float32 z\n"
  "float32 yaw\n"
  "\n"
  "int32  parking_mode\n"
  "int32  is_available\n"
  "int32  charging_mode\n"
  "int32  is_long_wait_zone";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__msg__Poi__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__msg__Poi__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 346, 346},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__msg__Poi__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__msg__Poi__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
