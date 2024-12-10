from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # Configuration du chemin et des arguments
    config_path = '/path/to/ros_maestro/config/pwmconfig_example.yaml'
    port = '/dev/polulu_servo_serial'

    return LaunchDescription([
        # Lancement des nœuds
        Node(
            package='ros_maestro',
            executable='attopilot_driver',
            name='attopilot1',
            parameters=[{'volt_topic': 'battery1_voltage_raw',
                         'curr_topic': 'battery1_current_raw',
                         'config_path': config_path,
                         'port': port}]
        ),
        Node(
            package='ros_maestro',
            executable='relay_driver',
            name='attopilot2',
            parameters=[{'volt_topic': 'battery2_voltage_raw',
                         'curr_topic': 'battery2_current_raw',
                         'config_path': config_path,
                         'port': port}]
        ),
    ])
