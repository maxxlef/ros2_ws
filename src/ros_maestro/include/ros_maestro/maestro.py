import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Int32
import serial

class MaestroControllerNode(Node):
    def __init__(self):
        super().__init__('maestro_controller')
        self.declare_parameter('tty', '/dev/ttyACM0')  # Paramètre pour le port série
        self.declare_parameter('servo_channels', 6)  # Nombre de canaux de servos

        # Initialisation du port série
        ttyStr = self.get_parameter('tty').get_parameter_value().string_value
        self.usb = serial.Serial(ttyStr)
        self.PololuCmd = chr(0xaa) + chr(0xc)
        
        # Configurer les canaux
        self.servo_channels = self.get_parameter('servo_channels').get_parameter_value().integer_value
        self.Targets = [0] * self.servo_channels
        self.Mins = [0] * self.servo_channels
        self.Maxs = [0] * self.servo_channels

        # Subscribers et Publishers
        self.target_subscriber = self.create_subscription(
            Int32,
            'servo_target',
            self.set_target_callback,
            10
        )
        self.position_publisher = self.create_publisher(JointState, 'servo_position', 10)

        # Timer pour publier les positions
        self.timer = self.create_timer(0.1, self.publish_position)

    def close(self):
        self.usb.close()

    def setRange(self, chan, min, max):
        self.Mins[chan] = min
        self.Maxs[chan] = max

    def setTarget(self, chan, target):
        if self.Mins[chan] > 0 and target < self.Mins[chan]:
            target = self.Mins[chan]
        if self.Maxs[chan] > 0 and target > self.Maxs[chan]:
            target = self.Maxs[chan]

        lsb = target & 0x7f
        msb = (target >> 7) & 0x7f
        cmd = self.PololuCmd + chr(0x04) + chr(chan) + chr(lsb) + chr(msb)
        self.usb.write(cmd)
        self.Targets[chan] = target

    def setTargetCallback(self, msg: Int32):
        # Exemple : contrôle du canal 0 uniquement
        self.setTarget(0, msg.data)

    def getPosition(self, chan):
        cmd = self.PololuCmd + chr(0x10) + chr(chan)
        self.usb.write(cmd)
        lsb = ord(self.usb.read())
        msb = ord(self.usb.read())
        return (msb << 8) + lsb

    def publishPosition(self):
        joint_state_msg = JointState()
        joint_state_msg.name = [f'servo_{i}' for i in range(self.servo_channels)]
        joint_state_msg.position = [self.getPosition(i) for i in range(self.servo_channels)]
        self.position_publisher.publish(joint_state_msg)

def main(args=None):
    rclpy.init(args=args)
    node = MaestroControllerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
