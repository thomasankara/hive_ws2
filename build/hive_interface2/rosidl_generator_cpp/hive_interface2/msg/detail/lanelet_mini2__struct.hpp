// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hive_interface2:msg/LaneletMini2.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/lanelet_mini2.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__STRUCT_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hive_interface2__msg__LaneletMini2 __attribute__((deprecated))
#else
# define DEPRECATED__hive_interface2__msg__LaneletMini2 __declspec(deprecated)
#endif

namespace hive_interface2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LaneletMini2_
{
  using Type = LaneletMini2_<ContainerAllocator>;

  explicit LaneletMini2_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enterprise_full_id_str = "";
      this->deployment_full_id_str = "";
      this->slam_session_full_id_str = "";
      this->lanelet_mini_id = 0l;
      this->start_point_x = 0.0f;
      this->start_point_y = 0.0f;
      this->start_point_z = 0.0f;
      this->end_point_x = 0.0f;
      this->end_point_y = 0.0f;
      this->end_point_z = 0.0f;
      this->navigation_direction = 0l;
      this->border_mode = 0l;
      this->u_turn_allowed = false;
      this->slope_alert = false;
      this->vegetation_alert = false;
      this->offroad_alert = false;
      this->configuration_group_id_str = "";
      this->road_group_id_str = "";
      this->max_speed = 0l;
      this->width = 0.0f;
    }
  }

  explicit LaneletMini2_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : enterprise_full_id_str(_alloc),
    deployment_full_id_str(_alloc),
    slam_session_full_id_str(_alloc),
    configuration_group_id_str(_alloc),
    road_group_id_str(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enterprise_full_id_str = "";
      this->deployment_full_id_str = "";
      this->slam_session_full_id_str = "";
      this->lanelet_mini_id = 0l;
      this->start_point_x = 0.0f;
      this->start_point_y = 0.0f;
      this->start_point_z = 0.0f;
      this->end_point_x = 0.0f;
      this->end_point_y = 0.0f;
      this->end_point_z = 0.0f;
      this->navigation_direction = 0l;
      this->border_mode = 0l;
      this->u_turn_allowed = false;
      this->slope_alert = false;
      this->vegetation_alert = false;
      this->offroad_alert = false;
      this->configuration_group_id_str = "";
      this->road_group_id_str = "";
      this->max_speed = 0l;
      this->width = 0.0f;
    }
  }

  // field types and members
  using _enterprise_full_id_str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _enterprise_full_id_str_type enterprise_full_id_str;
  using _deployment_full_id_str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _deployment_full_id_str_type deployment_full_id_str;
  using _slam_session_full_id_str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _slam_session_full_id_str_type slam_session_full_id_str;
  using _lanelet_mini_id_type =
    int32_t;
  _lanelet_mini_id_type lanelet_mini_id;
  using _start_point_x_type =
    float;
  _start_point_x_type start_point_x;
  using _start_point_y_type =
    float;
  _start_point_y_type start_point_y;
  using _start_point_z_type =
    float;
  _start_point_z_type start_point_z;
  using _end_point_x_type =
    float;
  _end_point_x_type end_point_x;
  using _end_point_y_type =
    float;
  _end_point_y_type end_point_y;
  using _end_point_z_type =
    float;
  _end_point_z_type end_point_z;
  using _navigation_direction_type =
    int32_t;
  _navigation_direction_type navigation_direction;
  using _border_mode_type =
    int32_t;
  _border_mode_type border_mode;
  using _u_turn_allowed_type =
    bool;
  _u_turn_allowed_type u_turn_allowed;
  using _slope_alert_type =
    bool;
  _slope_alert_type slope_alert;
  using _vegetation_alert_type =
    bool;
  _vegetation_alert_type vegetation_alert;
  using _offroad_alert_type =
    bool;
  _offroad_alert_type offroad_alert;
  using _configuration_group_id_str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _configuration_group_id_str_type configuration_group_id_str;
  using _road_group_id_str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _road_group_id_str_type road_group_id_str;
  using _max_speed_type =
    int32_t;
  _max_speed_type max_speed;
  using _width_type =
    float;
  _width_type width;

  // setters for named parameter idiom
  Type & set__enterprise_full_id_str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->enterprise_full_id_str = _arg;
    return *this;
  }
  Type & set__deployment_full_id_str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->deployment_full_id_str = _arg;
    return *this;
  }
  Type & set__slam_session_full_id_str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->slam_session_full_id_str = _arg;
    return *this;
  }
  Type & set__lanelet_mini_id(
    const int32_t & _arg)
  {
    this->lanelet_mini_id = _arg;
    return *this;
  }
  Type & set__start_point_x(
    const float & _arg)
  {
    this->start_point_x = _arg;
    return *this;
  }
  Type & set__start_point_y(
    const float & _arg)
  {
    this->start_point_y = _arg;
    return *this;
  }
  Type & set__start_point_z(
    const float & _arg)
  {
    this->start_point_z = _arg;
    return *this;
  }
  Type & set__end_point_x(
    const float & _arg)
  {
    this->end_point_x = _arg;
    return *this;
  }
  Type & set__end_point_y(
    const float & _arg)
  {
    this->end_point_y = _arg;
    return *this;
  }
  Type & set__end_point_z(
    const float & _arg)
  {
    this->end_point_z = _arg;
    return *this;
  }
  Type & set__navigation_direction(
    const int32_t & _arg)
  {
    this->navigation_direction = _arg;
    return *this;
  }
  Type & set__border_mode(
    const int32_t & _arg)
  {
    this->border_mode = _arg;
    return *this;
  }
  Type & set__u_turn_allowed(
    const bool & _arg)
  {
    this->u_turn_allowed = _arg;
    return *this;
  }
  Type & set__slope_alert(
    const bool & _arg)
  {
    this->slope_alert = _arg;
    return *this;
  }
  Type & set__vegetation_alert(
    const bool & _arg)
  {
    this->vegetation_alert = _arg;
    return *this;
  }
  Type & set__offroad_alert(
    const bool & _arg)
  {
    this->offroad_alert = _arg;
    return *this;
  }
  Type & set__configuration_group_id_str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->configuration_group_id_str = _arg;
    return *this;
  }
  Type & set__road_group_id_str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->road_group_id_str = _arg;
    return *this;
  }
  Type & set__max_speed(
    const int32_t & _arg)
  {
    this->max_speed = _arg;
    return *this;
  }
  Type & set__width(
    const float & _arg)
  {
    this->width = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hive_interface2::msg::LaneletMini2_<ContainerAllocator> *;
  using ConstRawPtr =
    const hive_interface2::msg::LaneletMini2_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hive_interface2::msg::LaneletMini2_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hive_interface2::msg::LaneletMini2_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::LaneletMini2_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::LaneletMini2_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::LaneletMini2_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::LaneletMini2_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hive_interface2::msg::LaneletMini2_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hive_interface2::msg::LaneletMini2_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hive_interface2__msg__LaneletMini2
    std::shared_ptr<hive_interface2::msg::LaneletMini2_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hive_interface2__msg__LaneletMini2
    std::shared_ptr<hive_interface2::msg::LaneletMini2_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LaneletMini2_ & other) const
  {
    if (this->enterprise_full_id_str != other.enterprise_full_id_str) {
      return false;
    }
    if (this->deployment_full_id_str != other.deployment_full_id_str) {
      return false;
    }
    if (this->slam_session_full_id_str != other.slam_session_full_id_str) {
      return false;
    }
    if (this->lanelet_mini_id != other.lanelet_mini_id) {
      return false;
    }
    if (this->start_point_x != other.start_point_x) {
      return false;
    }
    if (this->start_point_y != other.start_point_y) {
      return false;
    }
    if (this->start_point_z != other.start_point_z) {
      return false;
    }
    if (this->end_point_x != other.end_point_x) {
      return false;
    }
    if (this->end_point_y != other.end_point_y) {
      return false;
    }
    if (this->end_point_z != other.end_point_z) {
      return false;
    }
    if (this->navigation_direction != other.navigation_direction) {
      return false;
    }
    if (this->border_mode != other.border_mode) {
      return false;
    }
    if (this->u_turn_allowed != other.u_turn_allowed) {
      return false;
    }
    if (this->slope_alert != other.slope_alert) {
      return false;
    }
    if (this->vegetation_alert != other.vegetation_alert) {
      return false;
    }
    if (this->offroad_alert != other.offroad_alert) {
      return false;
    }
    if (this->configuration_group_id_str != other.configuration_group_id_str) {
      return false;
    }
    if (this->road_group_id_str != other.road_group_id_str) {
      return false;
    }
    if (this->max_speed != other.max_speed) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    return true;
  }
  bool operator!=(const LaneletMini2_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LaneletMini2_

// alias to use template instance with default allocator
using LaneletMini2 =
  hive_interface2::msg::LaneletMini2_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__STRUCT_HPP_
