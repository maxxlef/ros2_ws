cmake_minimum_required(VERSION 3.5)
project(gyro_publisher_package)

# Trouver les dépendances nécessaires
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

# Ajouter le dossier source
install(PROGRAMS
  src/gyro_publisher_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
