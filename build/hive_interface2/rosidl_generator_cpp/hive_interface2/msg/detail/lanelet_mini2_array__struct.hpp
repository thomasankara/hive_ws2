// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hive_interface2:msg/LaneletMini2Array.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/lanelet_mini2_array.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__STRUCT_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'lanelets'
#include "hive_interface2/msg/detail/lanelet_mini2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hive_interface2__msg__LaneletMini2Array __attribute__((deprecated))
#else
# define DEPRECATED__hive_interface2__msg__LaneletMini2Array __declspec(deprecated)
#endif

namespace hive_interface2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LaneletMini2Array_
{
  using Type = LaneletMini2Array_<ContainerAllocator>;

  explicit LaneletMini2Array_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit LaneletMini2Array_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _lanelets_type =
    std::vector<hive_interface2::msg::LaneletMini2_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hive_interface2::msg::LaneletMini2_<ContainerAllocator>>>;
  _lanelets_type lanelets;

  // setters for named parameter idiom
  Type & set__lanelets(
    const std::vector<hive_interface2::msg::LaneletMini2_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hive_interface2::msg::LaneletMini2_<ContainerAllocator>>> & _arg)
  {
    this->lanelets = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hive_interface2::msg::LaneletMini2Array_<ContainerAllocator> *;
  using ConstRawPtr =
    const hive_interface2::msg::LaneletMini2Array_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hive_interface2::msg::LaneletMini2Array_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hive_interface2::msg::LaneletMini2Array_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::LaneletMini2Array_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::LaneletMini2Array_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::LaneletMini2Array_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::LaneletMini2Array_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hive_interface2::msg::LaneletMini2Array_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hive_interface2::msg::LaneletMini2Array_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hive_interface2__msg__LaneletMini2Array
    std::shared_ptr<hive_interface2::msg::LaneletMini2Array_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hive_interface2__msg__LaneletMini2Array
    std::shared_ptr<hive_interface2::msg::LaneletMini2Array_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LaneletMini2Array_ & other) const
  {
    if (this->lanelets != other.lanelets) {
      return false;
    }
    return true;
  }
  bool operator!=(const LaneletMini2Array_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LaneletMini2Array_

// alias to use template instance with default allocator
using LaneletMini2Array =
  hive_interface2::msg::LaneletMini2Array_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__STRUCT_HPP_
