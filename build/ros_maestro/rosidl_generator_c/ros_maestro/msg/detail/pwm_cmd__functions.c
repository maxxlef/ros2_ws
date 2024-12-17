// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros_maestro:msg/PwmCmd.idl
// generated code does not contain a copyright notice
#include "ros_maestro/msg/detail/pwm_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ros_maestro__msg__PwmCmd__init(ros_maestro__msg__PwmCmd * msg)
{
  if (!msg) {
    return false;
  }
  // pin
  // command
  return true;
}

void
ros_maestro__msg__PwmCmd__fini(ros_maestro__msg__PwmCmd * msg)
{
  if (!msg) {
    return;
  }
  // pin
  // command
}

bool
ros_maestro__msg__PwmCmd__are_equal(const ros_maestro__msg__PwmCmd * lhs, const ros_maestro__msg__PwmCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pin
  if (lhs->pin != rhs->pin) {
    return false;
  }
  // command
  if (lhs->command != rhs->command) {
    return false;
  }
  return true;
}

bool
ros_maestro__msg__PwmCmd__copy(
  const ros_maestro__msg__PwmCmd * input,
  ros_maestro__msg__PwmCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // pin
  output->pin = input->pin;
  // command
  output->command = input->command;
  return true;
}

ros_maestro__msg__PwmCmd *
ros_maestro__msg__PwmCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_maestro__msg__PwmCmd * msg = (ros_maestro__msg__PwmCmd *)allocator.allocate(sizeof(ros_maestro__msg__PwmCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros_maestro__msg__PwmCmd));
  bool success = ros_maestro__msg__PwmCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros_maestro__msg__PwmCmd__destroy(ros_maestro__msg__PwmCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros_maestro__msg__PwmCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros_maestro__msg__PwmCmd__Sequence__init(ros_maestro__msg__PwmCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_maestro__msg__PwmCmd * data = NULL;

  if (size) {
    data = (ros_maestro__msg__PwmCmd *)allocator.zero_allocate(size, sizeof(ros_maestro__msg__PwmCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros_maestro__msg__PwmCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros_maestro__msg__PwmCmd__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros_maestro__msg__PwmCmd__Sequence__fini(ros_maestro__msg__PwmCmd__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros_maestro__msg__PwmCmd__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros_maestro__msg__PwmCmd__Sequence *
ros_maestro__msg__PwmCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_maestro__msg__PwmCmd__Sequence * array = (ros_maestro__msg__PwmCmd__Sequence *)allocator.allocate(sizeof(ros_maestro__msg__PwmCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros_maestro__msg__PwmCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros_maestro__msg__PwmCmd__Sequence__destroy(ros_maestro__msg__PwmCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros_maestro__msg__PwmCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros_maestro__msg__PwmCmd__Sequence__are_equal(const ros_maestro__msg__PwmCmd__Sequence * lhs, const ros_maestro__msg__PwmCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros_maestro__msg__PwmCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros_maestro__msg__PwmCmd__Sequence__copy(
  const ros_maestro__msg__PwmCmd__Sequence * input,
  ros_maestro__msg__PwmCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros_maestro__msg__PwmCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros_maestro__msg__PwmCmd * data =
      (ros_maestro__msg__PwmCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros_maestro__msg__PwmCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros_maestro__msg__PwmCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros_maestro__msg__PwmCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
