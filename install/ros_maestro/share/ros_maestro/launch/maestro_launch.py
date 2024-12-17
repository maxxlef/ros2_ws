from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os

def generate_launch_description():
    # Déclaration des arguments de lancement
    config_path_arg = DeclareLaunchArgument(
        'config_path',
        default_value='path/to/your/default/config.yaml',
        description='Path to the YAML configuration file'
    )

    port_arg = DeclareLaunchArgument(
        'port',
        default_value='/dev/ttyUSB0',
        description='Port for Maestro driver'
    )

    # Création de la description du lancement
    maestro_driver_node = Node(
        package='ros_maestro',
        executable='maestro_driver',
        name='maestro_driver',
        output='screen',
        parameters=[{'port': LaunchConfiguration('port')},
                    LaunchConfiguration('config_path')]
    )

    return LaunchDescription([
        config_path_arg,
        port_arg,
        maestro_driver_node
    ])
