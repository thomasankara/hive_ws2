// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dwb_msgs:srv/GenerateTwists.idl
// generated code does not contain a copyright notice

#include "dwb_msgs/srv/detail/generate_twists__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dwb_msgs
const rosidl_type_hash_t *
dwb_msgs__srv__GenerateTwists__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x50, 0xd7, 0x59, 0xac, 0x34, 0xf5, 0xc7, 0x50,
      0x9e, 0xdf, 0x89, 0x48, 0x8f, 0x4a, 0x53, 0x65,
      0x36, 0x6e, 0x11, 0xcd, 0x76, 0x0e, 0x78, 0xc0,
      0xb2, 0x06, 0x0a, 0xbc, 0x79, 0xb2, 0x91, 0x7f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_dwb_msgs
const rosidl_type_hash_t *
dwb_msgs__srv__GenerateTwists_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x95, 0xb3, 0x1a, 0x6a, 0x28, 0x7e, 0x1d, 0x68,
      0xad, 0xa4, 0x62, 0x11, 0x24, 0xf9, 0x6d, 0x80,
      0x9e, 0xd4, 0xd5, 0xec, 0x67, 0x22, 0xb0, 0x5b,
      0xfa, 0xec, 0xea, 0x8d, 0x24, 0xb5, 0x68, 0x8c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_dwb_msgs
const rosidl_type_hash_t *
dwb_msgs__srv__GenerateTwists_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x71, 0x63, 0x0d, 0xf7, 0x69, 0x5c, 0x13, 0xe8,
      0xa4, 0x57, 0xdf, 0x1a, 0xf9, 0xb1, 0xdf, 0xf0,
      0xd9, 0xef, 0x87, 0x35, 0xd7, 0xd3, 0xd7, 0x90,
      0x9d, 0x7a, 0x9a, 0x1e, 0xd7, 0x06, 0x55, 0x1d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_dwb_msgs
const rosidl_type_hash_t *
dwb_msgs__srv__GenerateTwists_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x87, 0x7f, 0x0c, 0x2c, 0x80, 0x13, 0x1c, 0x4b,
      0x4c, 0xc6, 0xb5, 0xcc, 0x15, 0xc4, 0xb9, 0x25,
      0xc5, 0xdc, 0xd3, 0x83, 0x22, 0xb6, 0x08, 0xa5,
      0xa8, 0x0b, 0xd5, 0x39, 0x0d, 0xd6, 0x1c, 0x8d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "nav_2d_msgs/msg/detail/twist2_d__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t nav_2d_msgs__msg__Twist2D__EXPECTED_HASH = {1, {
    0x33, 0xa3, 0xa4, 0x7d, 0x7b, 0x3a, 0xaa, 0xd5,
    0x37, 0x6a, 0x48, 0x25, 0x05, 0x97, 0x09, 0x3f,
    0xeb, 0x4b, 0x92, 0xab, 0x87, 0x06, 0xc9, 0x6d,
    0xca, 0x69, 0xf4, 0x7d, 0x9a, 0x98, 0x07, 0xd0,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char dwb_msgs__srv__GenerateTwists__TYPE_NAME[] = "dwb_msgs/srv/GenerateTwists";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char dwb_msgs__srv__GenerateTwists_Event__TYPE_NAME[] = "dwb_msgs/srv/GenerateTwists_Event";
static char dwb_msgs__srv__GenerateTwists_Request__TYPE_NAME[] = "dwb_msgs/srv/GenerateTwists_Request";
static char dwb_msgs__srv__GenerateTwists_Response__TYPE_NAME[] = "dwb_msgs/srv/GenerateTwists_Response";
static char nav_2d_msgs__msg__Twist2D__TYPE_NAME[] = "nav_2d_msgs/msg/Twist2D";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char dwb_msgs__srv__GenerateTwists__FIELD_NAME__request_message[] = "request_message";
static char dwb_msgs__srv__GenerateTwists__FIELD_NAME__response_message[] = "response_message";
static char dwb_msgs__srv__GenerateTwists__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field dwb_msgs__srv__GenerateTwists__FIELDS[] = {
  {
    {dwb_msgs__srv__GenerateTwists__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dwb_msgs__srv__GenerateTwists_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dwb_msgs__srv__GenerateTwists_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dwb_msgs__srv__GenerateTwists_Event__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription dwb_msgs__srv__GenerateTwists__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists_Event__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {nav_2d_msgs__msg__Twist2D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dwb_msgs__srv__GenerateTwists__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dwb_msgs__srv__GenerateTwists__TYPE_NAME, 27, 27},
      {dwb_msgs__srv__GenerateTwists__FIELDS, 3, 3},
    },
    {dwb_msgs__srv__GenerateTwists__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = dwb_msgs__srv__GenerateTwists_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = dwb_msgs__srv__GenerateTwists_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = dwb_msgs__srv__GenerateTwists_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_2d_msgs__msg__Twist2D__EXPECTED_HASH, nav_2d_msgs__msg__Twist2D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = nav_2d_msgs__msg__Twist2D__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char dwb_msgs__srv__GenerateTwists_Request__FIELD_NAME__current_vel[] = "current_vel";

static rosidl_runtime_c__type_description__Field dwb_msgs__srv__GenerateTwists_Request__FIELDS[] = {
  {
    {dwb_msgs__srv__GenerateTwists_Request__FIELD_NAME__current_vel, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_2d_msgs__msg__Twist2D__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription dwb_msgs__srv__GenerateTwists_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {nav_2d_msgs__msg__Twist2D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dwb_msgs__srv__GenerateTwists_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dwb_msgs__srv__GenerateTwists_Request__TYPE_NAME, 35, 35},
      {dwb_msgs__srv__GenerateTwists_Request__FIELDS, 1, 1},
    },
    {dwb_msgs__srv__GenerateTwists_Request__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&nav_2d_msgs__msg__Twist2D__EXPECTED_HASH, nav_2d_msgs__msg__Twist2D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = nav_2d_msgs__msg__Twist2D__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char dwb_msgs__srv__GenerateTwists_Response__FIELD_NAME__twists[] = "twists";

static rosidl_runtime_c__type_description__Field dwb_msgs__srv__GenerateTwists_Response__FIELDS[] = {
  {
    {dwb_msgs__srv__GenerateTwists_Response__FIELD_NAME__twists, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {nav_2d_msgs__msg__Twist2D__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription dwb_msgs__srv__GenerateTwists_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {nav_2d_msgs__msg__Twist2D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dwb_msgs__srv__GenerateTwists_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dwb_msgs__srv__GenerateTwists_Response__TYPE_NAME, 36, 36},
      {dwb_msgs__srv__GenerateTwists_Response__FIELDS, 1, 1},
    },
    {dwb_msgs__srv__GenerateTwists_Response__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&nav_2d_msgs__msg__Twist2D__EXPECTED_HASH, nav_2d_msgs__msg__Twist2D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = nav_2d_msgs__msg__Twist2D__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char dwb_msgs__srv__GenerateTwists_Event__FIELD_NAME__info[] = "info";
static char dwb_msgs__srv__GenerateTwists_Event__FIELD_NAME__request[] = "request";
static char dwb_msgs__srv__GenerateTwists_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field dwb_msgs__srv__GenerateTwists_Event__FIELDS[] = {
  {
    {dwb_msgs__srv__GenerateTwists_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {dwb_msgs__srv__GenerateTwists_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {dwb_msgs__srv__GenerateTwists_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription dwb_msgs__srv__GenerateTwists_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {dwb_msgs__srv__GenerateTwists_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {nav_2d_msgs__msg__Twist2D__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dwb_msgs__srv__GenerateTwists_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dwb_msgs__srv__GenerateTwists_Event__TYPE_NAME, 33, 33},
      {dwb_msgs__srv__GenerateTwists_Event__FIELDS, 3, 3},
    },
    {dwb_msgs__srv__GenerateTwists_Event__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = dwb_msgs__srv__GenerateTwists_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = dwb_msgs__srv__GenerateTwists_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_2d_msgs__msg__Twist2D__EXPECTED_HASH, nav_2d_msgs__msg__Twist2D__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = nav_2d_msgs__msg__Twist2D__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# For a given velocity, generate which twist commands will be evaluated\n"
  "nav_2d_msgs/Twist2D current_vel\n"
  "---\n"
  "nav_2d_msgs/Twist2D[] twists";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dwb_msgs__srv__GenerateTwists__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dwb_msgs__srv__GenerateTwists__TYPE_NAME, 27, 27},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 137, 137},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
dwb_msgs__srv__GenerateTwists_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dwb_msgs__srv__GenerateTwists_Request__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
dwb_msgs__srv__GenerateTwists_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dwb_msgs__srv__GenerateTwists_Response__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
dwb_msgs__srv__GenerateTwists_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dwb_msgs__srv__GenerateTwists_Event__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dwb_msgs__srv__GenerateTwists__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dwb_msgs__srv__GenerateTwists__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *dwb_msgs__srv__GenerateTwists_Event__get_individual_type_description_source(NULL);
    sources[3] = *dwb_msgs__srv__GenerateTwists_Request__get_individual_type_description_source(NULL);
    sources[4] = *dwb_msgs__srv__GenerateTwists_Response__get_individual_type_description_source(NULL);
    sources[5] = *nav_2d_msgs__msg__Twist2D__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dwb_msgs__srv__GenerateTwists_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dwb_msgs__srv__GenerateTwists_Request__get_individual_type_description_source(NULL),
    sources[1] = *nav_2d_msgs__msg__Twist2D__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dwb_msgs__srv__GenerateTwists_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dwb_msgs__srv__GenerateTwists_Response__get_individual_type_description_source(NULL),
    sources[1] = *nav_2d_msgs__msg__Twist2D__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dwb_msgs__srv__GenerateTwists_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dwb_msgs__srv__GenerateTwists_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *dwb_msgs__srv__GenerateTwists_Request__get_individual_type_description_source(NULL);
    sources[3] = *dwb_msgs__srv__GenerateTwists_Response__get_individual_type_description_source(NULL);
    sources[4] = *nav_2d_msgs__msg__Twist2D__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
