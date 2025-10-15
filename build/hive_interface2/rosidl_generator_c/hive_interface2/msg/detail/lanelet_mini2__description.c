// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hive_interface2:msg/LaneletMini2.idl
// generated code does not contain a copyright notice

#include "hive_interface2/msg/detail/lanelet_mini2__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__msg__LaneletMini2__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xff, 0xee, 0xac, 0x92, 0x17, 0x9b, 0xe1, 0xd2,
      0x53, 0xdb, 0xba, 0xcc, 0xf2, 0xe5, 0x36, 0xbd,
      0x33, 0x10, 0x8c, 0x8b, 0x5d, 0x14, 0xcf, 0x43,
      0xc4, 0xab, 0xfb, 0xa6, 0x3b, 0x83, 0xaa, 0x1a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char hive_interface2__msg__LaneletMini2__TYPE_NAME[] = "hive_interface2/msg/LaneletMini2";

// Define type names, field names, and default values
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__enterprise_full_id_str[] = "enterprise_full_id_str";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__deployment_full_id_str[] = "deployment_full_id_str";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__slam_session_full_id_str[] = "slam_session_full_id_str";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__lanelet_mini_id[] = "lanelet_mini_id";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__start_point_x[] = "start_point_x";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__start_point_y[] = "start_point_y";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__start_point_z[] = "start_point_z";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__end_point_x[] = "end_point_x";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__end_point_y[] = "end_point_y";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__end_point_z[] = "end_point_z";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__navigation_direction[] = "navigation_direction";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__border_mode[] = "border_mode";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__u_turn_allowed[] = "u_turn_allowed";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__slope_alert[] = "slope_alert";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__vegetation_alert[] = "vegetation_alert";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__offroad_alert[] = "offroad_alert";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__configuration_group_id_str[] = "configuration_group_id_str";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__road_group_id_str[] = "road_group_id_str";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__max_speed[] = "max_speed";
static char hive_interface2__msg__LaneletMini2__FIELD_NAME__width[] = "width";

static rosidl_runtime_c__type_description__Field hive_interface2__msg__LaneletMini2__FIELDS[] = {
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__enterprise_full_id_str, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__deployment_full_id_str, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__slam_session_full_id_str, 24, 24},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__lanelet_mini_id, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__start_point_x, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__start_point_y, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__start_point_z, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__end_point_x, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__end_point_y, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__end_point_z, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__navigation_direction, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__border_mode, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__u_turn_allowed, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__slope_alert, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__vegetation_alert, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__offroad_alert, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__configuration_group_id_str, 26, 26},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__road_group_id_str, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__max_speed, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__msg__LaneletMini2__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__msg__LaneletMini2__TYPE_NAME, 32, 32},
      {hive_interface2__msg__LaneletMini2__FIELDS, 20, 20},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ============================================================\n"
  "# Hive Robotics - LaneletMini2.msg\n"
  "# ============================================================\n"
  "# Repr\\xc3\\xa9sente une portion de voie simplifi\\xc3\\xa9e issue de la base SQL lanelet_mini2\n"
  "# Utilis\\xc3\\xa9e pour la navigation autonome dans Hive Robotics.\n"
  "# Chaque champ correspond directement \\xc3\\xa0 une colonne SQL.\n"
  "# ============================================================\n"
  "\n"
  "# --- Identifiants hi\\xc3\\xa9rarchiques ---\n"
  "string enterprise_full_id_str           # Entreprise associ\\xc3\\xa9e (nom complet)\n"
  "string deployment_full_id_str           # D\\xc3\\xa9ploiement associ\\xc3\\xa9 (nom complet)\n"
  "string slam_session_full_id_str         # Session SLAM associ\\xc3\\xa9e (nom complet)\n"
  "\n"
  "# --- Identifiant principal du lanelet ---\n"
  "int32 lanelet_mini_id                   # ID unique du lanelet_mini\n"
  "\n"
  "# --- Coordonn\\xc3\\xa9es du point de d\\xc3\\xa9part (r\\xc3\\xa9f\\xc3\\xa9rentiel 'map') ---\n"
  "float32 start_point_x\n"
  "float32 start_point_y\n"
  "float32 start_point_z\n"
  "\n"
  "# --- Coordonn\\xc3\\xa9es du point d'arriv\\xc3\\xa9e (r\\xc3\\xa9f\\xc3\\xa9rentiel 'map') ---\n"
  "float32 end_point_x\n"
  "float32 end_point_y\n"
  "float32 end_point_z\n"
  "\n"
  "# --- Propri\\xc3\\xa9t\\xc3\\xa9s de navigation ---\n"
  "int32 navigation_direction              # 0=ferm\\xc3\\xa9 | 1=start->end | 2=end->start | 3=bidirectionnel\n"
  "int32 border_mode                       # 0=aucun | 1=gauche | 2=droite | 3=deux c\\xc3\\xb4t\\xc3\\xa9s\n"
  "bool u_turn_allowed                     # true = demi-tour autoris\\xc3\\xa9\n"
  "bool slope_alert                        # true = pente significative (pr\\xc3\\xa9caution requise)\n"
  "bool vegetation_alert                   # true = forte v\\xc3\\xa9g\\xc3\\xa9tation (ralentir)\n"
  "bool offroad_alert                      # true = zone non-bitum\\xc3\\xa9e (terre, gravier, etc.)\n"
  "\n"
  "# --- Groupes logiques ---\n"
  "string configuration_group_id_str       # Sous-groupe de configuration (ex: avenues)\n"
  "string road_group_id_str                # Groupe routier (ex: grande route)\n"
  "\n"
  "# --- Propri\\xc3\\xa9t\\xc3\\xa9s physiques ---\n"
  "int32 max_speed                         # Vitesse max (en km/h)\n"
  "float32 width                           # Largeur de la route (en m\\xc3\\xa8tres)";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__msg__LaneletMini2__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__msg__LaneletMini2__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1954, 1954},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__msg__LaneletMini2__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__msg__LaneletMini2__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
