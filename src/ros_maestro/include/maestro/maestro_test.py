#!/usr/bin/env python3
# coding=utf-8

import rclpy
from rclpy.node import Node
from maestro import Controller

class MaestroTestNode(Node):
    def __init__(self):
        super().__init__('maestro_test')
        
        # Déclaration des paramètres ROS2 pour channel et target
        self.declare_parameter('channel', 0)  # Canal par défaut : 0
        self.declare_parameter('target', 6000)  # Valeur PWM par défaut : 6000
        
        # Lecture des paramètres
        channel = self.get_parameter('channel').value
        target = self.get_parameter('target').value

        # Log des valeurs récupérées
        self.get_logger().info(f'Channel: {channel}, Target: {target}')

        # Communication avec Maestro
        servo = Controller()
        try:
            servo.setAccel(channel, 4)  # Configure l'accélération
            servo.setTarget(channel, target)  # Configure la cible
            self.get_logger().info(f"Set channel {channel} to target {target}")
        except Exception as e:
            self.get_logger().error(f"Failed to communicate with Maestro: {e}")
        finally:
            servo.close()
            self.get_logger().info("Closed Maestro connection")

def main(args=None):
    rclpy.init(args=args)
    node = MaestroTestNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

