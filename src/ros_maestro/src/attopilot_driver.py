#!/usr/bin/env python
# coding=utf-8

# Author : Simon CHANU
# Notes  : Uniquement un noeud de traitement
# Input  : tension ou courant en Float32
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import numpy as np

class Attopilot(Node):
    def __init__(self):
        super().__init__('driver_attopilot')

        self.curr_tab = []
        self.volt_tab = []
        self.tab_len = 100
        self.voltage_limit = 20.0
        self.current_limit = 30.0

        # Publication sans le suffixe _raw
        sub_voltage = self.get_parameter('volt_topic').get_parameter_value().string_value
        sub_current = self.get_parameter('curr_topic').get_parameter_value().string_value

        self.pub_volt = self.create_publisher(Float32, sub_voltage[:-4], 10)
        self.pub_curr = self.create_publisher(Float32, sub_current[:-4], 10)

        # Abonnement
        self.create_subscription(Float32, sub_voltage, self.cb_voltage, 10)
        self.create_subscription(Float32, sub_current, self.cb_current, 10)

    def cb_voltage(self, msg):
        # 255.75 pts sur 5V avec un ratio de 1:15.7
        # coeffTheorique = 1/255.75*5.0*15.7
        coeffAjustement = 1.0 / 13.83
        voltage_raw = msg.data * coeffAjustement
        self.volt_tab.append(voltage_raw)
        if len(self.volt_tab) > self.tab_len:
            self.volt_tab = self.volt_tab[1:]

        voltage = np.mean(self.volt_tab)
        if voltage < self.voltage_limit:
            self.get_logger().error("Battery too low (<20V) [safety margin : 2V]")
        self.pub_volt.publish(Float32(data=voltage))

    def cb_current(self, msg):
        # 255.75 pts sur 5V avec un ratio de 1:15.7
        # coeffTheorique = 1/255.75*5.0*15.7
        coeffAjustement = 1.0 / 49.8
        current_raw = msg.data * coeffAjustement
        self.curr_tab.append(current_raw)
        if len(self.curr_tab) > self.tab_len:
            self.curr_tab = self.curr_tab[1:]

        current = np.mean(self.curr_tab)
        if current > self.current_limit:
            self.get_logger().error("Consumption too high on one battery (>15A) [2 batteries : 30A]")
        self.pub_curr.publish(Float32(data=current))

def main(args=None):
    rclpy.init(args=args)

    # Déclare les paramètres
    node = Attopilot()

    node.declare_parameter('volt_topic', 'battery1_voltage_raw')
    node.declare_parameter('curr_topic', 'battery1_current_raw')

    rclpy.spin(node)

    # Shutdown du noeud ROS2
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

