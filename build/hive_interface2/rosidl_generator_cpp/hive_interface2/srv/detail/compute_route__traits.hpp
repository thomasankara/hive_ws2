// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hive_interface2:srv/ComputeRoute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/srv/compute_route.hpp"


#ifndef HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__TRAITS_HPP_
#define HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hive_interface2/srv/detail/compute_route__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'start_pose'
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace hive_interface2
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeRoute_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: start_pose
  {
    out << "start_pose: ";
    to_flow_style_yaml(msg.start_pose, out);
    out << ", ";
  }

  // member: goal_pose
  {
    out << "goal_pose: ";
    to_flow_style_yaml(msg.goal_pose, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeRoute_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_pose:\n";
    to_block_style_yaml(msg.start_pose, out, indentation + 2);
  }

  // member: goal_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_pose:\n";
    to_block_style_yaml(msg.goal_pose, out, indentation + 2);
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeRoute_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hive_interface2

namespace rosidl_generator_traits
{

[[deprecated("use hive_interface2::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hive_interface2::srv::ComputeRoute_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hive_interface2::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hive_interface2::srv::to_yaml() instead")]]
inline std::string to_yaml(const hive_interface2::srv::ComputeRoute_Request & msg)
{
  return hive_interface2::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hive_interface2::srv::ComputeRoute_Request>()
{
  return "hive_interface2::srv::ComputeRoute_Request";
}

template<>
inline const char * name<hive_interface2::srv::ComputeRoute_Request>()
{
  return "hive_interface2/srv/ComputeRoute_Request";
}

template<>
struct has_fixed_size<hive_interface2::srv::ComputeRoute_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<hive_interface2::srv::ComputeRoute_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<hive_interface2::srv::ComputeRoute_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'path'
#include "hive_interface2/msg/detail/lanelet_mini2__traits.hpp"

namespace hive_interface2
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeRoute_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: path
  {
    if (msg.path.size() == 0) {
      out << "path: []";
    } else {
      out << "path: [";
      size_t pending_items = msg.path.size();
      for (auto item : msg.path) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: total_distance_m
  {
    out << "total_distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.total_distance_m, out);
    out << ", ";
  }

  // member: estimated_time_s
  {
    out << "estimated_time_s: ";
    rosidl_generator_traits::value_to_yaml(msg.estimated_time_s, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeRoute_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.path.size() == 0) {
      out << "path: []\n";
    } else {
      out << "path:\n";
      for (auto item : msg.path) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: total_distance_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.total_distance_m, out);
    out << "\n";
  }

  // member: estimated_time_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estimated_time_s: ";
    rosidl_generator_traits::value_to_yaml(msg.estimated_time_s, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeRoute_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hive_interface2

namespace rosidl_generator_traits
{

[[deprecated("use hive_interface2::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hive_interface2::srv::ComputeRoute_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hive_interface2::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hive_interface2::srv::to_yaml() instead")]]
inline std::string to_yaml(const hive_interface2::srv::ComputeRoute_Response & msg)
{
  return hive_interface2::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hive_interface2::srv::ComputeRoute_Response>()
{
  return "hive_interface2::srv::ComputeRoute_Response";
}

template<>
inline const char * name<hive_interface2::srv::ComputeRoute_Response>()
{
  return "hive_interface2/srv/ComputeRoute_Response";
}

template<>
struct has_fixed_size<hive_interface2::srv::ComputeRoute_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hive_interface2::srv::ComputeRoute_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hive_interface2::srv::ComputeRoute_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace hive_interface2
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputeRoute_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeRoute_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeRoute_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hive_interface2

namespace rosidl_generator_traits
{

[[deprecated("use hive_interface2::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hive_interface2::srv::ComputeRoute_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  hive_interface2::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hive_interface2::srv::to_yaml() instead")]]
inline std::string to_yaml(const hive_interface2::srv::ComputeRoute_Event & msg)
{
  return hive_interface2::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hive_interface2::srv::ComputeRoute_Event>()
{
  return "hive_interface2::srv::ComputeRoute_Event";
}

template<>
inline const char * name<hive_interface2::srv::ComputeRoute_Event>()
{
  return "hive_interface2/srv/ComputeRoute_Event";
}

template<>
struct has_fixed_size<hive_interface2::srv::ComputeRoute_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hive_interface2::srv::ComputeRoute_Event>
  : std::integral_constant<bool, has_bounded_size<hive_interface2::srv::ComputeRoute_Request>::value && has_bounded_size<hive_interface2::srv::ComputeRoute_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<hive_interface2::srv::ComputeRoute_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hive_interface2::srv::ComputeRoute>()
{
  return "hive_interface2::srv::ComputeRoute";
}

template<>
inline const char * name<hive_interface2::srv::ComputeRoute>()
{
  return "hive_interface2/srv/ComputeRoute";
}

template<>
struct has_fixed_size<hive_interface2::srv::ComputeRoute>
  : std::integral_constant<
    bool,
    has_fixed_size<hive_interface2::srv::ComputeRoute_Request>::value &&
    has_fixed_size<hive_interface2::srv::ComputeRoute_Response>::value
  >
{
};

template<>
struct has_bounded_size<hive_interface2::srv::ComputeRoute>
  : std::integral_constant<
    bool,
    has_bounded_size<hive_interface2::srv::ComputeRoute_Request>::value &&
    has_bounded_size<hive_interface2::srv::ComputeRoute_Response>::value
  >
{
};

template<>
struct is_service<hive_interface2::srv::ComputeRoute>
  : std::true_type
{
};

template<>
struct is_service_request<hive_interface2::srv::ComputeRoute_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hive_interface2::srv::ComputeRoute_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__TRAITS_HPP_
