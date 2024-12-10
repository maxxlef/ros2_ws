from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Déclaration d'un argument pour le chemin du fichier YAML
    return LaunchDescription([
        # Charger le fichier YAML avec les paramètres
        Node(
            package='maestro_node',
            executable='maestro_node',
            name='maestro_node',
            output='screen',
            parameters=[LaunchConfiguration('maestro_params')],
            arguments=['/dev/ttyACM0']
        ),
        DeclareLaunchArgument(
            'maestro_params',
            default_value='$(find maestro_node)/maestro2.yaml',
            description='Path to the maestro parameters YAML file'
        ),
    ])
