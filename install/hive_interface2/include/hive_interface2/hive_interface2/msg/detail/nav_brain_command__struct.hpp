// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hive_interface2:msg/NavBrainCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/nav_brain_command.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__STRUCT_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'destination'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hive_interface2__msg__NavBrainCommand __attribute__((deprecated))
#else
# define DEPRECATED__hive_interface2__msg__NavBrainCommand __declspec(deprecated)
#endif

namespace hive_interface2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavBrainCommand_
{
  using Type = NavBrainCommand_<ContainerAllocator>;

  explicit NavBrainCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : destination(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->free_zone_id = 0l;
      this->poi_id = 0l;
      this->object_tracking_id = 0l;
      this->mission_id = 0l;
    }
  }

  explicit NavBrainCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : destination(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->free_zone_id = 0l;
      this->poi_id = 0l;
      this->object_tracking_id = 0l;
      this->mission_id = 0l;
    }
  }

  // field types and members
  using _free_zone_id_type =
    int32_t;
  _free_zone_id_type free_zone_id;
  using _poi_id_type =
    int32_t;
  _poi_id_type poi_id;
  using _destination_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _destination_type destination;
  using _object_tracking_id_type =
    int32_t;
  _object_tracking_id_type object_tracking_id;
  using _mission_id_type =
    int32_t;
  _mission_id_type mission_id;

  // setters for named parameter idiom
  Type & set__free_zone_id(
    const int32_t & _arg)
  {
    this->free_zone_id = _arg;
    return *this;
  }
  Type & set__poi_id(
    const int32_t & _arg)
  {
    this->poi_id = _arg;
    return *this;
  }
  Type & set__destination(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->destination = _arg;
    return *this;
  }
  Type & set__object_tracking_id(
    const int32_t & _arg)
  {
    this->object_tracking_id = _arg;
    return *this;
  }
  Type & set__mission_id(
    const int32_t & _arg)
  {
    this->mission_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hive_interface2::msg::NavBrainCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const hive_interface2::msg::NavBrainCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hive_interface2::msg::NavBrainCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hive_interface2::msg::NavBrainCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::NavBrainCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::NavBrainCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::NavBrainCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::NavBrainCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hive_interface2::msg::NavBrainCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hive_interface2::msg::NavBrainCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hive_interface2__msg__NavBrainCommand
    std::shared_ptr<hive_interface2::msg::NavBrainCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hive_interface2__msg__NavBrainCommand
    std::shared_ptr<hive_interface2::msg::NavBrainCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavBrainCommand_ & other) const
  {
    if (this->free_zone_id != other.free_zone_id) {
      return false;
    }
    if (this->poi_id != other.poi_id) {
      return false;
    }
    if (this->destination != other.destination) {
      return false;
    }
    if (this->object_tracking_id != other.object_tracking_id) {
      return false;
    }
    if (this->mission_id != other.mission_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavBrainCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavBrainCommand_

// alias to use template instance with default allocator
using NavBrainCommand =
  hive_interface2::msg::NavBrainCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__STRUCT_HPP_
