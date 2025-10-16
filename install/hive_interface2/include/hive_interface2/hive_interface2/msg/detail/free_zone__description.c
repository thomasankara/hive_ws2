// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hive_interface2:msg/FreeZone.idl
// generated code does not contain a copyright notice

#include "hive_interface2/msg/detail/free_zone__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__msg__FreeZone__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xad, 0xcf, 0xa7, 0xff, 0xa6, 0xa1, 0x9a, 0xa8,
      0xed, 0x99, 0xaf, 0x23, 0xb1, 0x8d, 0x04, 0xe5,
      0x13, 0xf7, 0x6f, 0x65, 0x86, 0x07, 0x66, 0x4e,
      0xf6, 0xc7, 0xd6, 0xe3, 0xc2, 0x99, 0x91, 0xba,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char hive_interface2__msg__FreeZone__TYPE_NAME[] = "hive_interface2/msg/FreeZone";

// Define type names, field names, and default values
static char hive_interface2__msg__FreeZone__FIELD_NAME__enterprise_full_id_str[] = "enterprise_full_id_str";
static char hive_interface2__msg__FreeZone__FIELD_NAME__deployment_full_id_str[] = "deployment_full_id_str";
static char hive_interface2__msg__FreeZone__FIELD_NAME__slam_session_full_id_str[] = "slam_session_full_id_str";
static char hive_interface2__msg__FreeZone__FIELD_NAME__free_zone_full_id_str[] = "free_zone_full_id_str";
static char hive_interface2__msg__FreeZone__FIELD_NAME__free_zone_id[] = "free_zone_id";
static char hive_interface2__msg__FreeZone__FIELD_NAME__is_parking_available[] = "is_parking_available";
static char hive_interface2__msg__FreeZone__FIELD_NAME__is_offpoi_parking_allowed[] = "is_offpoi_parking_allowed";
static char hive_interface2__msg__FreeZone__FIELD_NAME__is_long_wait_zone[] = "is_long_wait_zone";
static char hive_interface2__msg__FreeZone__FIELD_NAME__zone_polygon_points_json[] = "zone_polygon_points_json";
static char hive_interface2__msg__FreeZone__FIELD_NAME__max_speed[] = "max_speed";

static rosidl_runtime_c__type_description__Field hive_interface2__msg__FreeZone__FIELDS[] = {
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__enterprise_full_id_str, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__deployment_full_id_str, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__slam_session_full_id_str, 24, 24},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__free_zone_full_id_str, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__free_zone_id, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__is_parking_available, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__is_offpoi_parking_allowed, 25, 25},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__is_long_wait_zone, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__zone_polygon_points_json, 24, 24},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__FreeZone__FIELD_NAME__max_speed, 9, 9},
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
hive_interface2__msg__FreeZone__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__msg__FreeZone__TYPE_NAME, 28, 28},
      {hive_interface2__msg__FreeZone__FIELDS, 10, 10},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Zone libre issue de la table SQL `zone_libre`\n"
  "string enterprise_full_id_str\n"
  "string deployment_full_id_str\n"
  "string slam_session_full_id_str\n"
  "\n"
  "string free_zone_full_id_str\n"
  "string free_zone_id\n"
  "\n"
  "int32  is_parking_available\n"
  "int32  is_offpoi_parking_allowed\n"
  "int32  is_long_wait_zone\n"
  "\n"
  "string zone_polygon_points_json  # JSON brut de la DB\n"
  "\n"
  "int32  max_speed";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__msg__FreeZone__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__msg__FreeZone__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 350, 350},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__msg__FreeZone__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__msg__FreeZone__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
