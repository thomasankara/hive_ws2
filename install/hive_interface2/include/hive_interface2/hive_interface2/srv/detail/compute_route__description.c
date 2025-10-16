// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hive_interface2:srv/ComputeRoute.idl
// generated code does not contain a copyright notice

#include "hive_interface2/srv/detail/compute_route__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__srv__ComputeRoute__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9d, 0x6b, 0x50, 0x55, 0x01, 0xc2, 0x6a, 0xa2,
      0x35, 0x47, 0xec, 0x27, 0x94, 0x81, 0x06, 0x75,
      0xa7, 0x1d, 0x82, 0xe9, 0x3f, 0x1c, 0x66, 0x02,
      0x31, 0xaf, 0x26, 0xb2, 0x90, 0x83, 0xf1, 0x61,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__srv__ComputeRoute_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x16, 0x2c, 0x36, 0xae, 0xe0, 0x4f, 0x49, 0x89,
      0x99, 0x9a, 0xd6, 0x73, 0xec, 0x61, 0x94, 0x99,
      0x2c, 0x1f, 0x64, 0x3d, 0x1b, 0xb3, 0xf3, 0x40,
      0xe8, 0x47, 0xa9, 0x0b, 0x35, 0x7b, 0x74, 0x15,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__srv__ComputeRoute_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0x35, 0xb7, 0x0b, 0x2c, 0xc1, 0xc2, 0x83,
      0x2f, 0xd3, 0x93, 0x04, 0x24, 0x88, 0xec, 0xd9,
      0xe0, 0x82, 0x81, 0x3b, 0x50, 0x64, 0x96, 0x7f,
      0xc6, 0x03, 0x07, 0x9b, 0x2d, 0x25, 0xd9, 0x33,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_hive_interface2
const rosidl_type_hash_t *
hive_interface2__srv__ComputeRoute_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1c, 0x27, 0xe2, 0x16, 0xb2, 0xd5, 0x02, 0x7a,
      0x47, 0xa3, 0x9a, 0xe6, 0x05, 0x54, 0xc9, 0xbd,
      0xaa, 0xbb, 0xcc, 0xce, 0x89, 0x8b, 0x0e, 0x62,
      0x57, 0xd1, 0x93, 0x99, 0x5b, 0x92, 0x43, 0xef,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/point__functions.h"
#include "geometry_msgs/msg/detail/pose__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "geometry_msgs/msg/detail/quaternion__functions.h"
#include "hive_interface2/msg/detail/lanelet_mini2__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Pose__EXPECTED_HASH = {1, {
    0xd5, 0x01, 0x95, 0x4e, 0x94, 0x76, 0xce, 0xa2,
    0x99, 0x69, 0x84, 0xe8, 0x12, 0x05, 0x4b, 0x68,
    0x02, 0x6a, 0xe0, 0xbf, 0xae, 0x78, 0x9d, 0x9a,
    0x10, 0xb2, 0x3d, 0xaf, 0x35, 0xcc, 0x90, 0xfa,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Quaternion__EXPECTED_HASH = {1, {
    0x8a, 0x76, 0x5f, 0x66, 0x77, 0x8c, 0x8f, 0xf7,
    0xc8, 0xab, 0x94, 0xaf, 0xcc, 0x59, 0x0a, 0x2e,
    0xd5, 0x32, 0x5a, 0x1d, 0x9a, 0x07, 0x6f, 0xff,
    0xf3, 0x8f, 0xbc, 0xe3, 0x6f, 0x45, 0x86, 0x84,
  }};
static const rosidl_type_hash_t hive_interface2__msg__LaneletMini2__EXPECTED_HASH = {1, {
    0xff, 0xee, 0xac, 0x92, 0x17, 0x9b, 0xe1, 0xd2,
    0x53, 0xdb, 0xba, 0xcc, 0xf2, 0xe5, 0x36, 0xbd,
    0x33, 0x10, 0x8c, 0x8b, 0x5d, 0x14, 0xcf, 0x43,
    0xc4, 0xab, 0xfb, 0xa6, 0x3b, 0x83, 0xaa, 0x1a,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char hive_interface2__srv__ComputeRoute__TYPE_NAME[] = "hive_interface2/srv/ComputeRoute";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Pose__TYPE_NAME[] = "geometry_msgs/msg/Pose";
static char geometry_msgs__msg__Quaternion__TYPE_NAME[] = "geometry_msgs/msg/Quaternion";
static char hive_interface2__msg__LaneletMini2__TYPE_NAME[] = "hive_interface2/msg/LaneletMini2";
static char hive_interface2__srv__ComputeRoute_Event__TYPE_NAME[] = "hive_interface2/srv/ComputeRoute_Event";
static char hive_interface2__srv__ComputeRoute_Request__TYPE_NAME[] = "hive_interface2/srv/ComputeRoute_Request";
static char hive_interface2__srv__ComputeRoute_Response__TYPE_NAME[] = "hive_interface2/srv/ComputeRoute_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char hive_interface2__srv__ComputeRoute__FIELD_NAME__request_message[] = "request_message";
static char hive_interface2__srv__ComputeRoute__FIELD_NAME__response_message[] = "response_message";
static char hive_interface2__srv__ComputeRoute__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field hive_interface2__srv__ComputeRoute__FIELDS[] = {
  {
    {hive_interface2__srv__ComputeRoute__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {hive_interface2__srv__ComputeRoute_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {hive_interface2__srv__ComputeRoute_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {hive_interface2__srv__ComputeRoute_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hive_interface2__srv__ComputeRoute__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__srv__ComputeRoute__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__srv__ComputeRoute__TYPE_NAME, 32, 32},
      {hive_interface2__srv__ComputeRoute__FIELDS, 3, 3},
    },
    {hive_interface2__srv__ComputeRoute__REFERENCED_TYPE_DESCRIPTIONS, 9, 9},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&hive_interface2__msg__LaneletMini2__EXPECTED_HASH, hive_interface2__msg__LaneletMini2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = hive_interface2__msg__LaneletMini2__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = hive_interface2__srv__ComputeRoute_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = hive_interface2__srv__ComputeRoute_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[7].fields = hive_interface2__srv__ComputeRoute_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[8].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char hive_interface2__srv__ComputeRoute_Request__FIELD_NAME__start_pose[] = "start_pose";
static char hive_interface2__srv__ComputeRoute_Request__FIELD_NAME__goal_pose[] = "goal_pose";
static char hive_interface2__srv__ComputeRoute_Request__FIELD_NAME__mode[] = "mode";

static rosidl_runtime_c__type_description__Field hive_interface2__srv__ComputeRoute_Request__FIELDS[] = {
  {
    {hive_interface2__srv__ComputeRoute_Request__FIELD_NAME__start_pose, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Request__FIELD_NAME__goal_pose, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Request__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hive_interface2__srv__ComputeRoute_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__srv__ComputeRoute_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__srv__ComputeRoute_Request__TYPE_NAME, 40, 40},
      {hive_interface2__srv__ComputeRoute_Request__FIELDS, 3, 3},
    },
    {hive_interface2__srv__ComputeRoute_Request__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__success[] = "success";
static char hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__message[] = "message";
static char hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__path[] = "path";
static char hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__total_distance_m[] = "total_distance_m";
static char hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__estimated_time_s[] = "estimated_time_s";

static rosidl_runtime_c__type_description__Field hive_interface2__srv__ComputeRoute_Response__FIELDS[] = {
  {
    {hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__path, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {hive_interface2__msg__LaneletMini2__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__total_distance_m, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Response__FIELD_NAME__estimated_time_s, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hive_interface2__srv__ComputeRoute_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {hive_interface2__msg__LaneletMini2__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__srv__ComputeRoute_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__srv__ComputeRoute_Response__TYPE_NAME, 41, 41},
      {hive_interface2__srv__ComputeRoute_Response__FIELDS, 5, 5},
    },
    {hive_interface2__srv__ComputeRoute_Response__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&hive_interface2__msg__LaneletMini2__EXPECTED_HASH, hive_interface2__msg__LaneletMini2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = hive_interface2__msg__LaneletMini2__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char hive_interface2__srv__ComputeRoute_Event__FIELD_NAME__info[] = "info";
static char hive_interface2__srv__ComputeRoute_Event__FIELD_NAME__request[] = "request";
static char hive_interface2__srv__ComputeRoute_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field hive_interface2__srv__ComputeRoute_Event__FIELDS[] = {
  {
    {hive_interface2__srv__ComputeRoute_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {hive_interface2__srv__ComputeRoute_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {hive_interface2__srv__ComputeRoute_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hive_interface2__srv__ComputeRoute_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {hive_interface2__msg__LaneletMini2__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {hive_interface2__srv__ComputeRoute_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hive_interface2__srv__ComputeRoute_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hive_interface2__srv__ComputeRoute_Event__TYPE_NAME, 38, 38},
      {hive_interface2__srv__ComputeRoute_Event__FIELDS, 3, 3},
    },
    {hive_interface2__srv__ComputeRoute_Event__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&hive_interface2__msg__LaneletMini2__EXPECTED_HASH, hive_interface2__msg__LaneletMini2__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = hive_interface2__msg__LaneletMini2__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = hive_interface2__srv__ComputeRoute_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = hive_interface2__srv__ComputeRoute_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ===============================\n"
  "# HiveRoutePlanner - ComputeRoute.srv\n"
  "# ===============================\n"
  "\n"
  "# --- Requ\\xc3\\xaate ---\n"
  "geometry_msgs/Pose start_pose          # Pose de d\\xc3\\xa9part (orientation ignor\\xc3\\xa9e ici)\n"
  "geometry_msgs/Pose goal_pose           # Pose d'arriv\\xc3\\xa9e (orientation ignor\\xc3\\xa9e ici)\n"
  "\n"
  "# Mode de co\\xc3\\xbbt :\n"
  "# 0 = distance minimale\n"
  "# 1 = temps minimal (utilise max_speed de chaque lanelet)\n"
  "int32 mode\n"
  "\n"
  "---\n"
  "\n"
  "# --- R\\xc3\\xa9ponse ---\n"
  "bool success                           # true si un itin\\xc3\\xa9raire a \\xc3\\xa9t\\xc3\\xa9 trouv\\xc3\\xa9 (ou ligne droite < seuil)\n"
  "string message                         # infos ou erreur\n"
  "hive_interface2/LaneletMini2[] path    # suite de lanelets (peut \\xc3\\xaatre vide si \"ligne droite\")\n"
  "float64 total_distance_m               # distance totale pr\\xc3\\xa9vue (m)\n"
  "float64 estimated_time_s               # temps estim\\xc3\\xa9 (s)";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__srv__ComputeRoute__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__srv__ComputeRoute__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 803, 803},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__srv__ComputeRoute_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__srv__ComputeRoute_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__srv__ComputeRoute_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__srv__ComputeRoute_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
hive_interface2__srv__ComputeRoute_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hive_interface2__srv__ComputeRoute_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__srv__ComputeRoute__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[10];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 10, 10};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__srv__ComputeRoute__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[5] = *hive_interface2__msg__LaneletMini2__get_individual_type_description_source(NULL);
    sources[6] = *hive_interface2__srv__ComputeRoute_Event__get_individual_type_description_source(NULL);
    sources[7] = *hive_interface2__srv__ComputeRoute_Request__get_individual_type_description_source(NULL);
    sources[8] = *hive_interface2__srv__ComputeRoute_Response__get_individual_type_description_source(NULL);
    sources[9] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__srv__ComputeRoute_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__srv__ComputeRoute_Request__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__srv__ComputeRoute_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__srv__ComputeRoute_Response__get_individual_type_description_source(NULL),
    sources[1] = *hive_interface2__msg__LaneletMini2__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hive_interface2__srv__ComputeRoute_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hive_interface2__srv__ComputeRoute_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[5] = *hive_interface2__msg__LaneletMini2__get_individual_type_description_source(NULL);
    sources[6] = *hive_interface2__srv__ComputeRoute_Request__get_individual_type_description_source(NULL);
    sources[7] = *hive_interface2__srv__ComputeRoute_Response__get_individual_type_description_source(NULL);
    sources[8] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
