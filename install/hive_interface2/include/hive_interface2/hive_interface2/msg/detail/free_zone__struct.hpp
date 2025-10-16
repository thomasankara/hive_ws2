// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hive_interface2:msg/FreeZone.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/free_zone.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__STRUCT_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hive_interface2__msg__FreeZone __attribute__((deprecated))
#else
# define DEPRECATED__hive_interface2__msg__FreeZone __declspec(deprecated)
#endif

namespace hive_interface2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FreeZone_
{
  using Type = FreeZone_<ContainerAllocator>;

  explicit FreeZone_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enterprise_full_id_str = "";
      this->deployment_full_id_str = "";
      this->slam_session_full_id_str = "";
      this->free_zone_full_id_str = "";
      this->free_zone_id = "";
      this->is_parking_available = 0l;
      this->is_offpoi_parking_allowed = 0l;
      this->is_long_wait_zone = 0l;
      this->zone_polygon_points_json = "";
      this->max_speed = 0l;
    }
  }

  explicit FreeZone_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : enterprise_full_id_str(_alloc),
    deployment_full_id_str(_alloc),
    slam_session_full_id_str(_alloc),
    free_zone_full_id_str(_alloc),
    free_zone_id(_alloc),
    zone_polygon_points_json(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enterprise_full_id_str = "";
      this->deployment_full_id_str = "";
      this->slam_session_full_id_str = "";
      this->free_zone_full_id_str = "";
      this->free_zone_id = "";
      this->is_parking_available = 0l;
      this->is_offpoi_parking_allowed = 0l;
      this->is_long_wait_zone = 0l;
      this->zone_polygon_points_json = "";
      this->max_speed = 0l;
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
  using _free_zone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _free_zone_id_type free_zone_id;
  using _is_parking_available_type =
    int32_t;
  _is_parking_available_type is_parking_available;
  using _is_offpoi_parking_allowed_type =
    int32_t;
  _is_offpoi_parking_allowed_type is_offpoi_parking_allowed;
  using _is_long_wait_zone_type =
    int32_t;
  _is_long_wait_zone_type is_long_wait_zone;
  using _zone_polygon_points_json_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_polygon_points_json_type zone_polygon_points_json;
  using _max_speed_type =
    int32_t;
  _max_speed_type max_speed;

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
  Type & set__free_zone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->free_zone_id = _arg;
    return *this;
  }
  Type & set__is_parking_available(
    const int32_t & _arg)
  {
    this->is_parking_available = _arg;
    return *this;
  }
  Type & set__is_offpoi_parking_allowed(
    const int32_t & _arg)
  {
    this->is_offpoi_parking_allowed = _arg;
    return *this;
  }
  Type & set__is_long_wait_zone(
    const int32_t & _arg)
  {
    this->is_long_wait_zone = _arg;
    return *this;
  }
  Type & set__zone_polygon_points_json(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone_polygon_points_json = _arg;
    return *this;
  }
  Type & set__max_speed(
    const int32_t & _arg)
  {
    this->max_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hive_interface2::msg::FreeZone_<ContainerAllocator> *;
  using ConstRawPtr =
    const hive_interface2::msg::FreeZone_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hive_interface2::msg::FreeZone_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hive_interface2::msg::FreeZone_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::FreeZone_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::FreeZone_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::FreeZone_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::FreeZone_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hive_interface2::msg::FreeZone_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hive_interface2::msg::FreeZone_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hive_interface2__msg__FreeZone
    std::shared_ptr<hive_interface2::msg::FreeZone_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hive_interface2__msg__FreeZone
    std::shared_ptr<hive_interface2::msg::FreeZone_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FreeZone_ & other) const
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
    if (this->free_zone_id != other.free_zone_id) {
      return false;
    }
    if (this->is_parking_available != other.is_parking_available) {
      return false;
    }
    if (this->is_offpoi_parking_allowed != other.is_offpoi_parking_allowed) {
      return false;
    }
    if (this->is_long_wait_zone != other.is_long_wait_zone) {
      return false;
    }
    if (this->zone_polygon_points_json != other.zone_polygon_points_json) {
      return false;
    }
    if (this->max_speed != other.max_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const FreeZone_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FreeZone_

// alias to use template instance with default allocator
using FreeZone =
  hive_interface2::msg::FreeZone_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__STRUCT_HPP_
