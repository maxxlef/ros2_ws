import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from ros_maestro.msg import PwmCmd
import threading

# Define PWM values for different directions
COMMANDS = {
    "forward": {"left_motor": -1.0, "right_motor": -1.0},
    "backward": {"left_motor": 1.0, "right_motor": 1.0},
    "turn_left": {"left_motor": 0.5, "right_motor": -1.0},
    "turn_right": {"left_motor": -1.0, "right_motor": 0.5},
    "stop": {"left_motor": 0.0, "right_motor": 0.0}
}

class MotorController(Node):

    def __init__(self):
        super().__init__('motor_controller')
        self.pwm_pub = self.create_publisher(PwmCmd, '/cmd_pwm', 10)
        self.create_subscription(String, '/motor_command', self.command_callback, 10)
        self.get_logger().info("Motor controller node started. Listening for commands...")

    def execute_command(self, direction, duration):
        """
        Executes a motor command for a specified duration.
        """
        if direction in COMMANDS:
            motor_values = COMMANDS[direction]
            self.get_logger().info(f"Executing direction: {direction} for {duration} seconds")

            # Publish the motor commands
            self.pwm_pub.publish(PwmCmd(pin=1, command=motor_values["left_motor"]))  # Left motor
            self.pwm_pub.publish(PwmCmd(pin=0, command=motor_values["right_motor"]))  # Right motor

            # Wait for the duration
            rclpy.sleep(duration)

            # Stop the motors after the duration
            self.get_logger().info("Stopping motors after duration")
            self.pwm_pub.publish(PwmCmd(pin=1, command=0.0))  # Left motor
            self.pwm_pub.publish(PwmCmd(pin=0, command=0.0))  # Right motor
        else:
            self.get_logger().warn(f"Unknown direction: {direction}. Ignoring.")

    def command_callback(self, data):
        """
        Callback function to handle incoming commands.
        The command format is expected to be "direction:duration" (e.g., "forward:5").
        """
        try:
            command = data.data.strip().lower()
            direction, duration = command.split(":")
            duration = float(duration)

            # Run the command execution in a separate thread
            threading.Thread(target=self.execute_command, args=(direction, duration)).start()
        except ValueError:
            self.get_logger().error("Invalid command format. Use 'direction:duration', e.g., 'forward:5'.")


def main(args=None):
    rclpy.init(args=args)
    motor_controller = MotorController()

    rclpy.spin(motor_controller)

    # Shutdown
    motor_controller.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
