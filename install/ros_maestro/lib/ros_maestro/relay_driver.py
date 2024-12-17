#!/usr/bin/env python
# coding=utf-8

# Author : Simon CHANU
# Notes  : Uniquement un noeud de traitement
# Input  : tension ou courant en Float32

import rclpy
from rclpy.node import Node
from std_srvs.srv import SetBool
from ros_maestro.msg import PwmCmd

class RelayDriver(Node):

    def __init__(self):
        super().__init__('driver_relay')
        self.get_logger().info("Node Initialised")

        # Déclaration du service
        self.srv = self.create_service(SetBool, 'toogle_relay', self.toggle_relay)

        # Publication sans le suffixe _raw
        self.pub = self.create_publisher(PwmCmd, 'pwm_cmd', 10)

    def toggle_relay(self, request, response):
        msg = PwmCmd()
        msg.pin = 6
        response.success = False
        response.message = 'relay desactivated (open)'

        if request.data:
            msg.command = 100
            response.success = True
            response.message = 'relay activated (closed)'
        else:
            msg.command = -100

        self.pub.publish(msg)
        return response


def main(args=None):
    rclpy.init(args=args)

    node = RelayDriver()

    # Exécution du spin pour traiter les callbacks
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
