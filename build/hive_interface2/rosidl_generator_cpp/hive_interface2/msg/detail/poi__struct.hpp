// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/poi.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__POI__STRUCT_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__POI__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hive_interface2__msg__Poi __attribute__((deprecated))
#else
# define DEPRECATED__hive_interface2__msg__Poi __declspec(deprecated)
#endif

namespace hive_interface2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Poi_
{
  using Type = Poi_<ContainerAllocator>;

  explicit Poi_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enterprise_full_id_str = "";
      this->deployment_full_id_str = "";
      this->slam_session_full_id_str = "";
      this->free_zone_full_id_str = "";
      this->is_in_free_zone = 0l;
      this->poi_full_id_str = "";
      this->poi_id = 0l;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->yaw = 0.0f;
      this->parking_mode = 0l;
      this->is_available = 0l;
      this->charging_mode = 0l;
      this->is_long_wait_zone = 0l;
    }
  }

  explicit Poi_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : enterprise_full_id_str(_alloc),
    deployment_full_id_str(_alloc),
    slam_session_full_id_str(_alloc),
    free_zone_full_id_str(_alloc),
    poi_full_id_str(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enterprise_full_id_str = "";
      this->deployment_full_id_str = "";
      this->slam_session_full_id_str = "";
      this->free_zone_full_id_str = "";
      this->is_in_free_zone = 0l;
      this->poi_full_id_str = "";
      this->poi_id = 0l;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->yaw = 0.0f;
      this->parking_mode = 0l;
      this->is_available = 0l;
      this->charging_mode = 0l;
      this->is_long_wait_zone = 0l;
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
  using _free_zone_full_id_str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _free_zone_full_id_str_type free_zone_full_id_str;
  using _is_in_free_zone_type =
    int32_t;
  _is_in_free_zone_type is_in_free_zone;
  using _poi_full_id_str_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _poi_full_id_str_type poi_full_id_str;
  using _poi_id_type =
    int32_t;
  _poi_id_type poi_id;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _parking_mode_type =
    int32_t;
  _parking_mode_type parking_mode;
  using _is_available_type =
    int32_t;
  _is_available_type is_available;
  using _charging_mode_type =
    int32_t;
  _charging_mode_type charging_mode;
  using _is_long_wait_zone_type =
    int32_t;
  _is_long_wait_zone_type is_long_wait_zone;

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
  Type & set__free_zone_full_id_str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->free_zone_full_id_str = _arg;
    return *this;
  }
  Type & set__is_in_free_zone(
    const int32_t & _arg)
  {
    this->is_in_free_zone = _arg;
    return *this;
  }
  Type & set__poi_full_id_str(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->poi_full_id_str = _arg;
    return *this;
  }
  Type & set__poi_id(
    const int32_t & _arg)
  {
    this->poi_id = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__parking_mode(
    const int32_t & _arg)
  {
    this->parking_mode = _arg;
    return *this;
  }
  Type & set__is_available(
    const int32_t & _arg)
  {
    this->is_available = _arg;
    return *this;
  }
  Type & set__charging_mode(
    const int32_t & _arg)
  {
    this->charging_mode = _arg;
    return *this;
  }
  Type & set__is_long_wait_zone(
    const int32_t & _arg)
  {
    this->is_long_wait_zone = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hive_interface2::msg::Poi_<ContainerAllocator> *;
  using ConstRawPtr =
    const hive_interface2::msg::Poi_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hive_interface2::msg::Poi_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hive_interface2::msg::Poi_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::Poi_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::Poi_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::Poi_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::Poi_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hive_interface2::msg::Poi_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hive_interface2::msg::Poi_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hive_interface2__msg__Poi
    std::shared_ptr<hive_interface2::msg::Poi_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hive_interface2__msg__Poi
    std::shared_ptr<hive_interface2::msg::Poi_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Poi_ & other) const
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
    if (this->free_zone_full_id_str != other.free_zone_full_id_str) {
      return false;
    }
    if (this->is_in_free_zone != other.is_in_free_zone) {
      return false;
    }
    if (this->poi_full_id_str != other.poi_full_id_str) {
      return false;
    }
    if (this->poi_id != other.poi_id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->parking_mode != other.parking_mode) {
      return false;
    }
    if (this->is_available != other.is_available) {
      return false;
    }
    if (this->charging_mode != other.charging_mode) {
      return false;
    }
    if (this->is_long_wait_zone != other.is_long_wait_zone) {
      return false;
    }
    return true;
  }
  bool operator!=(const Poi_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Poi_

// alias to use template instance with default allocator
using Poi =
  hive_interface2::msg::Poi_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__POI__STRUCT_HPP_
