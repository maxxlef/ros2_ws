cmake_minimum_required(VERSION 3.5)
project(maestro_node)

# Trouver les paquets nécessaires pour ROS2
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)
find_package(sensor_msgs REQUIRED)


# Liste des fichiers source
set(maestro_SRC
    src/TimeoutSerial.cpp
    src/PololuController.cpp
    src/ROSMaestroController.cpp
    src/maestro_node.cpp
)

# Ajouter l'exécutable pour le nœud
add_executable(maestro_node ${maestro_SRC})

# Ajouter le répertoire d'inclusion d'`asio` (manuel)
include_directories(/usr/include/asio)

# Lier les bibliothèques nécessaires
target_link_libraries(maestro_node ${Boost_LIBRARIES})

# Déclarer les dépendances ROS2
ament_target_dependencies(maestro_node rclcpp std_msgs tf2 tf2_ros sensor_msgs)


# Ajouter les répertoires d'inclusion
include_directories(include)

# Installer l'exécutable
install(TARGETS maestro_node
  DESTINATION lib/${PROJECT_NAME})

# Installer les fichiers d'inclusion
install(DIRECTORY include/
  DESTINATION include/)

# Installer les fichiers launch
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch)

# Activer le paquet pour ament
ament_package()

