// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros_maestro:msg/PwmCmd.idl
// generated code does not contain a copyright notice

#ifndef ROS_MAESTRO__MSG__DETAIL__PWM_CMD__STRUCT_HPP_
#define ROS_MAESTRO__MSG__DETAIL__PWM_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros_maestro__msg__PwmCmd __attribute__((deprecated))
#else
# define DEPRECATED__ros_maestro__msg__PwmCmd __declspec(deprecated)
#endif

namespace ros_maestro
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PwmCmd_
{
  using Type = PwmCmd_<ContainerAllocator>;

  explicit PwmCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pin = 0;
      this->command = 0.0f;
    }
  }

  explicit PwmCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pin = 0;
      this->command = 0.0f;
    }
  }

  // field types and members
  using _pin_type =
    int16_t;
  _pin_type pin;
  using _command_type =
    float;
  _command_type command;

  // setters for named parameter idiom
  Type & set__pin(
    const int16_t & _arg)
  {
    this->pin = _arg;
    return *this;
  }
  Type & set__command(
    const float & _arg)
  {
    this->command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_maestro::msg::PwmCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_maestro::msg::PwmCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_maestro::msg::PwmCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_maestro::msg::PwmCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_maestro::msg::PwmCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_maestro::msg::PwmCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_maestro::msg::PwmCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_maestro::msg::PwmCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_maestro::msg::PwmCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_maestro::msg::PwmCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_maestro__msg__PwmCmd
    std::shared_ptr<ros_maestro::msg::PwmCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_maestro__msg__PwmCmd
    std::shared_ptr<ros_maestro::msg::PwmCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PwmCmd_ & other) const
  {
    if (this->pin != other.pin) {
      return false;
    }
    if (this->command != other.command) {
      return false;
    }
    return true;
  }
  bool operator!=(const PwmCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PwmCmd_

// alias to use template instance with default allocator
using PwmCmd =
  ros_maestro::msg::PwmCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros_maestro

#endif  // ROS_MAESTRO__MSG__DETAIL__PWM_CMD__STRUCT_HPP_
