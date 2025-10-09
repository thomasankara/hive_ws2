// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav2_msgs:srv/Toggle.idl
// generated code does not contain a copyright notice

#include "nav2_msgs/srv/detail/toggle__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
const rosidl_type_hash_t *
nav2_msgs__srv__Toggle__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb2, 0xbd, 0xc6, 0x85, 0xd2, 0x42, 0x1a, 0x1d,
      0x01, 0x51, 0x24, 0x7d, 0xe7, 0xcd, 0xfd, 0xe3,
      0x58, 0xae, 0x2b, 0x5f, 0x48, 0x26, 0xa6, 0xf4,
      0xb5, 0x71, 0x28, 0xc1, 0xd0, 0xc3, 0xf1, 0x3c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
const rosidl_type_hash_t *
nav2_msgs__srv__Toggle_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcf, 0xab, 0x1b, 0x7d, 0x17, 0x8e, 0x14, 0x13,
      0x28, 0xaa, 0xc9, 0xd8, 0x2d, 0xd0, 0x23, 0x97,
      0xed, 0xff, 0x33, 0x77, 0x76, 0x26, 0x5d, 0x19,
      0xa2, 0x3f, 0x2c, 0x2d, 0x0e, 0xe1, 0x13, 0x4d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
const rosidl_type_hash_t *
nav2_msgs__srv__Toggle_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x05, 0x92, 0xb1, 0x55, 0x05, 0xfa, 0x71, 0x65,
      0xad, 0x55, 0x6e, 0x51, 0x07, 0x00, 0x21, 0x0a,
      0x34, 0x1d, 0x1a, 0x9b, 0xab, 0x87, 0x20, 0x12,
      0xfa, 0x7f, 0x3c, 0x86, 0x1c, 0x77, 0x8e, 0x26,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
const rosidl_type_hash_t *
nav2_msgs__srv__Toggle_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x90, 0x32, 0x75, 0xe1, 0x35, 0x3b, 0x24, 0x26,
      0x1c, 0x21, 0xb1, 0xa7, 0x0c, 0xbf, 0x2d, 0xf3,
      0x8f, 0x32, 0x2c, 0xb8, 0x1d, 0x42, 0xa2, 0x93,
      0x41, 0x6d, 0xf5, 0x59, 0xc6, 0xd2, 0x3e, 0xbd,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
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
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char nav2_msgs__srv__Toggle__TYPE_NAME[] = "nav2_msgs/srv/Toggle";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char nav2_msgs__srv__Toggle_Event__TYPE_NAME[] = "nav2_msgs/srv/Toggle_Event";
static char nav2_msgs__srv__Toggle_Request__TYPE_NAME[] = "nav2_msgs/srv/Toggle_Request";
static char nav2_msgs__srv__Toggle_Response__TYPE_NAME[] = "nav2_msgs/srv/Toggle_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char nav2_msgs__srv__Toggle__FIELD_NAME__request_message[] = "request_message";
static char nav2_msgs__srv__Toggle__FIELD_NAME__response_message[] = "response_message";
static char nav2_msgs__srv__Toggle__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field nav2_msgs__srv__Toggle__FIELDS[] = {
  {
    {nav2_msgs__srv__Toggle__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav2_msgs__srv__Toggle_Request__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav2_msgs__srv__Toggle_Response__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav2_msgs__srv__Toggle_Event__TYPE_NAME, 26, 26},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav2_msgs__srv__Toggle__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle_Event__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle_Request__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle_Response__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav2_msgs__srv__Toggle__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav2_msgs__srv__Toggle__TYPE_NAME, 20, 20},
      {nav2_msgs__srv__Toggle__FIELDS, 3, 3},
    },
    {nav2_msgs__srv__Toggle__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = nav2_msgs__srv__Toggle_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = nav2_msgs__srv__Toggle_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = nav2_msgs__srv__Toggle_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav2_msgs__srv__Toggle_Request__FIELD_NAME__enable[] = "enable";

static rosidl_runtime_c__type_description__Field nav2_msgs__srv__Toggle_Request__FIELDS[] = {
  {
    {nav2_msgs__srv__Toggle_Request__FIELD_NAME__enable, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav2_msgs__srv__Toggle_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav2_msgs__srv__Toggle_Request__TYPE_NAME, 28, 28},
      {nav2_msgs__srv__Toggle_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav2_msgs__srv__Toggle_Response__FIELD_NAME__success[] = "success";
static char nav2_msgs__srv__Toggle_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field nav2_msgs__srv__Toggle_Response__FIELDS[] = {
  {
    {nav2_msgs__srv__Toggle_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav2_msgs__srv__Toggle_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav2_msgs__srv__Toggle_Response__TYPE_NAME, 29, 29},
      {nav2_msgs__srv__Toggle_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav2_msgs__srv__Toggle_Event__FIELD_NAME__info[] = "info";
static char nav2_msgs__srv__Toggle_Event__FIELD_NAME__request[] = "request";
static char nav2_msgs__srv__Toggle_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field nav2_msgs__srv__Toggle_Event__FIELDS[] = {
  {
    {nav2_msgs__srv__Toggle_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {nav2_msgs__srv__Toggle_Request__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {nav2_msgs__srv__Toggle_Response__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav2_msgs__srv__Toggle_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle_Request__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {nav2_msgs__srv__Toggle_Response__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav2_msgs__srv__Toggle_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav2_msgs__srv__Toggle_Event__TYPE_NAME, 26, 26},
      {nav2_msgs__srv__Toggle_Event__FIELDS, 3, 3},
    },
    {nav2_msgs__srv__Toggle_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = nav2_msgs__srv__Toggle_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = nav2_msgs__srv__Toggle_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool enable\n"
  "---\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav2_msgs__srv__Toggle__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav2_msgs__srv__Toggle__TYPE_NAME, 20, 20},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 44, 44},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav2_msgs__srv__Toggle_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav2_msgs__srv__Toggle_Request__TYPE_NAME, 28, 28},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav2_msgs__srv__Toggle_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav2_msgs__srv__Toggle_Response__TYPE_NAME, 29, 29},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav2_msgs__srv__Toggle_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav2_msgs__srv__Toggle_Event__TYPE_NAME, 26, 26},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav2_msgs__srv__Toggle__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav2_msgs__srv__Toggle__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *nav2_msgs__srv__Toggle_Event__get_individual_type_description_source(NULL);
    sources[3] = *nav2_msgs__srv__Toggle_Request__get_individual_type_description_source(NULL);
    sources[4] = *nav2_msgs__srv__Toggle_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav2_msgs__srv__Toggle_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav2_msgs__srv__Toggle_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav2_msgs__srv__Toggle_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav2_msgs__srv__Toggle_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav2_msgs__srv__Toggle_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav2_msgs__srv__Toggle_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *nav2_msgs__srv__Toggle_Request__get_individual_type_description_source(NULL);
    sources[3] = *nav2_msgs__srv__Toggle_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
