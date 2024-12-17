import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Path to the configuration file
    config_file = os.path.join(
        get_package_share_directory('ros_maestro'),
        'config',
        'pwmconfig_example.yaml'
    )

    # Declare launch arguments
    port_arg = DeclareLaunchArgument(
        'port',
        default_value='/dev/ttyACM0',
        description='Serial port for the Maestro controller'
    )

    return LaunchDescription([
        # Load parameters from YAML file
        SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1'),
        
        # Declare serial port argument
        port_arg,

        # Node definition
        Node(
            package='ros_maestro',
            executable='maestro_driver',
            name='maestro_driver',
            output='screen',
            parameters=[config_file],
            arguments=['--ros-args', '--log-level', 'info'],
            remappings=[('/old_topic', '/new_topic')],  # Replace with actual remappings if needed
        ),
    ])
