cmake_minimum_required(VERSION 3.5)
project(ros_maestro)

# Default to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Make sure the interface files are found correctly
ament_export_dependencies(rosidl_default_runtime std_msgs sensor_msgs)

# Declare ROS messages
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/PwmCmd.msg"
  DEPENDENCIES std_msgs
)

# Declare the package
ament_package()

# Include directories (if necessary)
include_directories(
  include
)

# Install Python scripts
install(PROGRAMS
  src/attopilot_driver.py
  src/maestro_driver.py
  src/relay_driver.py
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# Install headers
install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION include/${PROJECT_NAME}
)

# Install other necessary files
install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

