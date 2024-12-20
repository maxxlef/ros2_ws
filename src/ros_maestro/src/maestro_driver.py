#!/usr/bin/env python
# coding=utf-8

# Author : Simon
# Notes  : Utilise un message specifique
# Input  : Reçoit les commandes des autres noeuds pour les moteurs sous la forme d'une pin et d'une commande en pwm

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from ros_maestro.msg import PwmCmd
from maestro.maestro import Controller  # Si ce fichier est présent dans le bon répertoire

# 1000 : marche avant
# 1500 : statique
# 2000 : marche arrière
# Channel : 0:L 1:R

class PWMBoard(Controller):
    def __init__(self, port, actuators, sensors, data_types):
        super().__init__(ttyStr=port)

        # Formattage des données (quelle pin de la carte associée à quoi)
        self.devices_by_pins = self.gen_dic_by_pin_keys(actuators)
        self.devices_by_name = actuators
        self.types = data_types
        self.sensors = sensors
        print(f'devices_by_pins : {self.devices_by_pins}')

        for device in self.devices_by_name:
            pin = self.devices_by_name[device]['pin']
            data_type = self.devices_by_name[device]['data_type']
            self.setAccel(pin, self.types[data_type]['accel'])

    def gen_dic_by_pin_keys(self, devices):
        """
        Transforme la table de hachage où on accède aux numéros des pins par le nom de l'appareil en une table de
        hachage où on accède au nom de l'appareil par son numéro de pin associé
        :param devices:
        :return pin_dic:
        """
        pin_dic = dict()
        for device in devices:
            print(f'device : {device}')
            pin = int(devices[device]['pin'])
            pin_dic[pin] = device
        return pin_dic

    def cb_pwm(self, msg):
        print(f'pin : {msg.pin}')  # pin en int
        print(f'cmd : {msg.command}')  # commande en float

        # Gestion du type de commande
        device_name = self.devices_by_pins[msg.pin]
        print(f'device_name: {device_name}')
        type = self.devices_by_name[device_name]['data_type']
        print(f'type: {type}')
        range = self.types[type]['range']
        range_min = range[0]
        range_max = range[1]
        range_tot = range_max - range_min
        range_zero = range_min + range_tot / 2.0
        print(f'range: {range}')

        # Calcul de la commande en pwm
        cmd = (msg.command - range_zero) * 1000 / range_tot + 1500
        print(f'pwm sent to board : {int(cmd)}')

        # Envoi de la commande (traduction en polulu 0-2000 = 0-8192)
        cmd = int(cmd * 4.000)
        print(f'cmd sent to board : {int(cmd)} on pin {msg.pin}')
        self.setTarget(int(msg.pin), int(cmd))

    def publish(self, sensors):
        for device in sensors:
            pub = sensors[device]['publisher']
            pin = int(sensors[device]['pin'])

            # rclpy.loginfo("getting positions")
            val = self.getPosition(pin)
            # rclpy.loginfo("Sensors values")
            pub.publish(val)

class MaestroDriverNode(Node):
    def __init__(self):
        super().__init__('driver_maestro')

        self.get_logger().info("driver_maestro Node Initialised")
        port = self.declare_parameter('port', '/dev/ttyACM0').value
        devices = self.declare_parameter('maestro/device', {}).value
        data_types = self.declare_parameter('maestro/data_types', {}).value

        actuators = {}
        sensors = {}
        for device in devices:
            self.get_logger().info(f"{data_types[devices[device]['data_type']]['type']}")
            if data_types[devices[device]['data_type']]['type'] == 'input':
                sensors[device] = devices[device]
                sensors[device]['publisher'] = self.create_publisher(Float32, device, 10)
            if data_types[devices[device]['data_type']]['type'] == 'output':
                actuators[device] = devices[device]

        self.maestro = PWMBoard(port, actuators, sensors, data_types)

        self.create_subscription(PwmCmd, 'cmd_pwm', self.maestro.cb_pwm, 10)

        # Timer to publish sensor values
        self.timer = self.create_timer(0.1, self.publish_sensors)

    def publish_sensors(self):
        self.maestro.publish(self.maestro.sensors)

def main(args=None):
    rclpy.init(args=args)

    node = MaestroDriverNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
