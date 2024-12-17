// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_maestro:msg/PwmCmd.idl
// generated code does not contain a copyright notice

#ifndef ROS_MAESTRO__MSG__DETAIL__PWM_CMD__TRAITS_HPP_
#define ROS_MAESTRO__MSG__DETAIL__PWM_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros_maestro/msg/detail/pwm_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros_maestro
{

namespace msg
{

inline void to_flow_style_yaml(
  const PwmCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: pin
  {
    out << "pin: ";
    rosidl_generator_traits::value_to_yaml(msg.pin, out);
    out << ", ";
  }

  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PwmCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pin: ";
    rosidl_generator_traits::value_to_yaml(msg.pin, out);
    out << "\n";
  }

  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PwmCmd & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ros_maestro

namespace rosidl_generator_traits
{

[[deprecated("use ros_maestro::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_maestro::msg::PwmCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_maestro::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_maestro::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros_maestro::msg::PwmCmd & msg)
{
  return ros_maestro::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros_maestro::msg::PwmCmd>()
{
  return "ros_maestro::msg::PwmCmd";
}

template<>
inline const char * name<ros_maestro::msg::PwmCmd>()
{
  return "ros_maestro/msg/PwmCmd";
}

template<>
struct has_fixed_size<ros_maestro::msg::PwmCmd>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_maestro::msg::PwmCmd>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_maestro::msg::PwmCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS_MAESTRO__MSG__DETAIL__PWM_CMD__TRAITS_HPP_
