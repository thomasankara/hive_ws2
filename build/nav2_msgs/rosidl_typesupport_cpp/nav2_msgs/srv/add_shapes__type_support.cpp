// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from nav2_msgs:srv/AddShapes.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "nav2_msgs/srv/detail/add_shapes__functions.h"
#include "nav2_msgs/srv/detail/add_shapes__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace nav2_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _AddShapes_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AddShapes_Request_type_support_ids_t;

static const _AddShapes_Request_type_support_ids_t _AddShapes_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _AddShapes_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AddShapes_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AddShapes_Request_type_support_symbol_names_t _AddShapes_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav2_msgs, srv, AddShapes_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav2_msgs, srv, AddShapes_Request)),
  }
};

typedef struct _AddShapes_Request_type_support_data_t
{
  void * data[2];
} _AddShapes_Request_type_support_data_t;

static _AddShapes_Request_type_support_data_t _AddShapes_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AddShapes_Request_message_typesupport_map = {
  2,
  "nav2_msgs",
  &_AddShapes_Request_message_typesupport_ids.typesupport_identifier[0],
  &_AddShapes_Request_message_typesupport_symbol_names.symbol_name[0],
  &_AddShapes_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t AddShapes_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AddShapes_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &nav2_msgs__srv__AddShapes_Request__get_type_hash,
  &nav2_msgs__srv__AddShapes_Request__get_type_description,
  &nav2_msgs__srv__AddShapes_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nav2_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::srv::AddShapes_Request>()
{
  return &::nav2_msgs::srv::rosidl_typesupport_cpp::AddShapes_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, nav2_msgs, srv, AddShapes_Request)() {
  return get_message_type_support_handle<nav2_msgs::srv::AddShapes_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "nav2_msgs/srv/detail/add_shapes__functions.h"
// already included above
// #include "nav2_msgs/srv/detail/add_shapes__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nav2_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _AddShapes_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AddShapes_Response_type_support_ids_t;

static const _AddShapes_Response_type_support_ids_t _AddShapes_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _AddShapes_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AddShapes_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AddShapes_Response_type_support_symbol_names_t _AddShapes_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav2_msgs, srv, AddShapes_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav2_msgs, srv, AddShapes_Response)),
  }
};

typedef struct _AddShapes_Response_type_support_data_t
{
  void * data[2];
} _AddShapes_Response_type_support_data_t;

static _AddShapes_Response_type_support_data_t _AddShapes_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AddShapes_Response_message_typesupport_map = {
  2,
  "nav2_msgs",
  &_AddShapes_Response_message_typesupport_ids.typesupport_identifier[0],
  &_AddShapes_Response_message_typesupport_symbol_names.symbol_name[0],
  &_AddShapes_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t AddShapes_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AddShapes_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &nav2_msgs__srv__AddShapes_Response__get_type_hash,
  &nav2_msgs__srv__AddShapes_Response__get_type_description,
  &nav2_msgs__srv__AddShapes_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nav2_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::srv::AddShapes_Response>()
{
  return &::nav2_msgs::srv::rosidl_typesupport_cpp::AddShapes_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, nav2_msgs, srv, AddShapes_Response)() {
  return get_message_type_support_handle<nav2_msgs::srv::AddShapes_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "nav2_msgs/srv/detail/add_shapes__functions.h"
// already included above
// #include "nav2_msgs/srv/detail/add_shapes__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nav2_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _AddShapes_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AddShapes_Event_type_support_ids_t;

static const _AddShapes_Event_type_support_ids_t _AddShapes_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _AddShapes_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AddShapes_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AddShapes_Event_type_support_symbol_names_t _AddShapes_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav2_msgs, srv, AddShapes_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav2_msgs, srv, AddShapes_Event)),
  }
};

typedef struct _AddShapes_Event_type_support_data_t
{
  void * data[2];
} _AddShapes_Event_type_support_data_t;

static _AddShapes_Event_type_support_data_t _AddShapes_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AddShapes_Event_message_typesupport_map = {
  2,
  "nav2_msgs",
  &_AddShapes_Event_message_typesupport_ids.typesupport_identifier[0],
  &_AddShapes_Event_message_typesupport_symbol_names.symbol_name[0],
  &_AddShapes_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t AddShapes_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AddShapes_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &nav2_msgs__srv__AddShapes_Event__get_type_hash,
  &nav2_msgs__srv__AddShapes_Event__get_type_description,
  &nav2_msgs__srv__AddShapes_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nav2_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav2_msgs::srv::AddShapes_Event>()
{
  return &::nav2_msgs::srv::rosidl_typesupport_cpp::AddShapes_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, nav2_msgs, srv, AddShapes_Event)() {
  return get_message_type_support_handle<nav2_msgs::srv::AddShapes_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "nav2_msgs/srv/detail/add_shapes__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nav2_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _AddShapes_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AddShapes_type_support_ids_t;

static const _AddShapes_type_support_ids_t _AddShapes_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _AddShapes_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AddShapes_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AddShapes_type_support_symbol_names_t _AddShapes_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav2_msgs, srv, AddShapes)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav2_msgs, srv, AddShapes)),
  }
};

typedef struct _AddShapes_type_support_data_t
{
  void * data[2];
} _AddShapes_type_support_data_t;

static _AddShapes_type_support_data_t _AddShapes_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AddShapes_service_typesupport_map = {
  2,
  "nav2_msgs",
  &_AddShapes_service_typesupport_ids.typesupport_identifier[0],
  &_AddShapes_service_typesupport_symbol_names.symbol_name[0],
  &_AddShapes_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t AddShapes_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AddShapes_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<nav2_msgs::srv::AddShapes_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<nav2_msgs::srv::AddShapes_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<nav2_msgs::srv::AddShapes_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<nav2_msgs::srv::AddShapes>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<nav2_msgs::srv::AddShapes>,
  &nav2_msgs__srv__AddShapes__get_type_hash,
  &nav2_msgs__srv__AddShapes__get_type_description,
  &nav2_msgs__srv__AddShapes__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nav2_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<nav2_msgs::srv::AddShapes>()
{
  return &::nav2_msgs::srv::rosidl_typesupport_cpp::AddShapes_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, nav2_msgs, srv, AddShapes)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<nav2_msgs::srv::AddShapes>();
}

#ifdef __cplusplus
}
#endif
