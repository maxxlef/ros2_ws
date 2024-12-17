// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros_maestro:msg/PwmCmd.idl
// generated code does not contain a copyright notice

#ifndef ROS_MAESTRO__MSG__DETAIL__PWM_CMD__STRUCT_H_
#define ROS_MAESTRO__MSG__DETAIL__PWM_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PwmCmd in the package ros_maestro.
typedef struct ros_maestro__msg__PwmCmd
{
  int16_t pin;
  float command;
} ros_maestro__msg__PwmCmd;

// Struct for a sequence of ros_maestro__msg__PwmCmd.
typedef struct ros_maestro__msg__PwmCmd__Sequence
{
  ros_maestro__msg__PwmCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_maestro__msg__PwmCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS_MAESTRO__MSG__DETAIL__PWM_CMD__STRUCT_H_
