import rclpy
from launch import LaunchDescription
from launch.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='motor_controller',
            executable='motor_controller',
            name='motor_controller',
            output='screen',
            emulate_tty=True
        ),
    ])
