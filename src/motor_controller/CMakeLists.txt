cmake_minimum_required(VERSION 3.5)
project(motor_controller)

# Default to C++ 14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros_maestro REQUIRED)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

install(PROGRAMS
  src/motor_controller/motor_controller.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
