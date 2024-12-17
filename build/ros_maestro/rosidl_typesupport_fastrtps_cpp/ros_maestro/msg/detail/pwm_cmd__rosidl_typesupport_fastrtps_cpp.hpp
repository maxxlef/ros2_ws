// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ros_maestro:msg/PwmCmd.idl
// generated code does not contain a copyright notice

#ifndef ROS_MAESTRO__MSG__DETAIL__PWM_CMD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ROS_MAESTRO__MSG__DETAIL__PWM_CMD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ros_maestro/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ros_maestro/msg/detail/pwm_cmd__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace ros_maestro
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros_maestro
cdr_serialize(
  const ros_maestro::msg::PwmCmd & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros_maestro
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros_maestro::msg::PwmCmd & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros_maestro
get_serialized_size(
  const ros_maestro::msg::PwmCmd & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros_maestro
max_serialized_size_PwmCmd(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ros_maestro

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros_maestro
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros_maestro, msg, PwmCmd)();

#ifdef __cplusplus
}
#endif

#endif  // ROS_MAESTRO__MSG__DETAIL__PWM_CMD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
