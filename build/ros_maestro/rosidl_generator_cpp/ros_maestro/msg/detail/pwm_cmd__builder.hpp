// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_maestro:msg/PwmCmd.idl
// generated code does not contain a copyright notice

#ifndef ROS_MAESTRO__MSG__DETAIL__PWM_CMD__BUILDER_HPP_
#define ROS_MAESTRO__MSG__DETAIL__PWM_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_maestro/msg/detail/pwm_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_maestro
{

namespace msg
{

namespace builder
{

class Init_PwmCmd_command
{
public:
  explicit Init_PwmCmd_command(::ros_maestro::msg::PwmCmd & msg)
  : msg_(msg)
  {}
  ::ros_maestro::msg::PwmCmd command(::ros_maestro::msg::PwmCmd::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_maestro::msg::PwmCmd msg_;
};

class Init_PwmCmd_pin
{
public:
  Init_PwmCmd_pin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PwmCmd_command pin(::ros_maestro::msg::PwmCmd::_pin_type arg)
  {
    msg_.pin = std::move(arg);
    return Init_PwmCmd_command(msg_);
  }

private:
  ::ros_maestro::msg::PwmCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_maestro::msg::PwmCmd>()
{
  return ros_maestro::msg::builder::Init_PwmCmd_pin();
}

}  // namespace ros_maestro

#endif  // ROS_MAESTRO__MSG__DETAIL__PWM_CMD__BUILDER_HPP_
