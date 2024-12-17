#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import serial
import time

class GyroPublisher(Node):
    def __init__(self, port='/dev/ttyUSB1', baudrate=57600):
        super().__init__('gyro_publisher')
        
        self.publisher_ = self.create_publisher(String, 'gyro_data', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)  # 10 Hz
        self.port = port
        self.baudrate = baudrate
        self.ser = None

        try:
            # Initialiser la connexion au port série
            self.ser = serial.Serial(self.port, self.baudrate, timeout=1)
            self.get_logger().info(f"Connexion établie sur {self.port} à {self.baudrate} bauds")
            time.sleep(2)  # Attendre que le capteur soit prêt

            # Initialiser le capteur (si nécessaire)
            self.ser.write(b'GYRO_START\n')
        except serial.SerialException as e:
            self.get_logger().error(f"Erreur de connexion au port série : {e}")
            return

    def timer_callback(self):
        if self.ser:
            ligne = self.ser.readline().decode('utf-8').strip()
            if ligne:
                self.get_logger().info(f"Données reçues : {ligne}")
                msg = String()
                msg.data = ligne
                self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    gyro_publisher = GyroPublisher()

    try:
        rclpy.spin(gyro_publisher)
    except KeyboardInterrupt:
        pass
    finally:
        gyro_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
