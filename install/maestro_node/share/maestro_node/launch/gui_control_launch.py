from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
import os

def generate_launch_description():
    # Déclare les arguments
    use_gui = LaunchConfiguration('use_gui', default='True')
    robot_description = LaunchConfiguration('robot_description', default='file://' + os.path.join(os.path.expanduser('~'), 'ros2_ws/src/maestro_node/arvi.urdf'))

    return LaunchDescription([
        # Déclare les paramètres
        DeclareLaunchArgument('use_gui', default_value='True', description='Use GUI'),
        DeclareLaunchArgument('robot_description', default_value=robot_description, description='Robot description file'),

        # Paramètre 'use_gui'
        Node(
            package='maestro_node',
            executable='maestro_node',
            name='maestro_node',
            output='screen',
            parameters=[{'use_gui': use_gui}],
        ),
        
        # Nœud joint_state_publisher
        Node(
            package='joint_state_publisher',
            executable='joint_state_publisher',
            name='joint_state_publisher',
            remappings=[('/joint_states', '/servo/command/joint_states')],
            output='screen'
        ),

        # Nœud robot_state_publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            parameters=[{'robot_description': LaunchConfiguration('robot_description')}],
            output='screen'
        ),
    ])
