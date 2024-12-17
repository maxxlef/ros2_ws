import launch
from launch import LaunchDescription
from launch.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gyro_publisher_package',
            executable='gyro_publisher_node.py',
            name='gyro_publisher',
            output='screen',
            parameters=[],
            remappings=[]
        ),
    ])
