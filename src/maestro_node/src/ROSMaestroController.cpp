#include "ROSMaestroController.h"
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <chrono>

const std::string tf_string = "tf";
const std::string joint_string = "joint_states";
const std::string command_string = "command";

using namespace std;
using namespace std::chrono_literals;

ROSMaestroController::ROSMaestroController(std::string name_node, std::shared_ptr<rclcpp::Node> node, TimeoutSerial* serial)
: PololuController(serial), node_(node), name_node_(name_node) {

    // JointState position
    pub_joint = node_->create_publisher<sensor_msgs::msg::JointState>(name_node + "/" + joint_string, 1);
    sub_joint = node_->create_subscription<sensor_msgs::msg::JointState>(
        name_node + "/" + command_string + "/" + joint_string, 1, 
        std::bind(&ROSMaestroController::jointCallback, this, std::placeholders::_1)
    );

    // Timer
    timer_ = node_->create_wall_timer(1s, std::bind(&ROSMaestroController::timerCallback, this));
}

ROSMaestroController::~ROSMaestroController() {
}

void ROSMaestroController::timerCallback() {
    rclcpp::Time now = node_->get_clock()->now();
    double rate = 1;
    node_->get_parameter(name_node_ + "/timer/rate", rate);
    // Convert rate from Hz to seconds
    std::chrono::duration<double> period(1.0 / rate);
    timer_->cancel();
    timer_ = node_->create_wall_timer(period, std::bind(&ROSMaestroController::timerCallback, this));

    int i = 0;
    for (auto& servo_pair : servo) {
        joint.name[i] = servo_pair.first;
        joint.position[i] = maestroGetAngle(servo_pair.second);
        joint.velocity[i] = 0;
        joint.effort[i] = 0;
        i++;
    }
    joint.header.stamp = now;
    pub_joint->publish(joint);

    if (pub_joint->get_subscription_count() == 0) {
        RCLCPP_INFO(node_->get_logger(), "Wait users");
        timer_->cancel();
    }
}

void ROSMaestroController::connectCallback(const rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr& pub) {
    RCLCPP_INFO(node_->get_logger(), "Connect: %zu - %s", pub->get_subscription_count(), pub->get_topic_name());

    timer_->reset();
}

void ROSMaestroController::jointCallback(const sensor_msgs::msg::JointState::SharedPtr msg) {
    int length = msg->name.size();
    for (int i = 0; i < length; ++i) {
        std::string name = msg->name[i];
        if (servo.find(name) != servo.end()) {
            int channel = servo[name];
            maestroSetAngle(channel, msg->position[i]);
        }
    }
}

void ROSMaestroController::loadConfiguration() {
    if (node_->has_parameter(name_node_ + "/servo")) {
        int length = 0;
        if (node_->has_parameter(name_node_ + "/servo/length")) {
            node_->get_parameter(name_node_ + "/servo/length", length);
            joint.name.resize(length);
            joint.position.resize(length);
            joint.velocity.resize(length);
            joint.effort.resize(length);
            for (int i = 0; i < length; ++i) {
                servo_t temp_servo;
                std::ostringstream convert;
                convert << i;
                node_->get_parameter(name_node_ + "/servo/name/" + convert.str(), temp_servo.name);
                node_->get_parameter(name_node_ + "/servo/channel/" + convert.str(), temp_servo.channel);
                servo[temp_servo.name] = temp_servo.channel;
                maestroSetAngle(temp_servo.channel, 0);
            }
            list_servo.resize(length);
        } else {
            RCLCPP_ERROR(node_->get_logger(), "Unknown number of servos");
        }
    } else {
        RCLCPP_ERROR(node_->get_logger(), "Never configuration for servo");
    }
    // Set timer rate
    double rate = 1;
    if (node_->has_parameter(name_node_ + "/timer/rate")) {
        node_->get_parameter(name_node_ + "/timer/rate", rate);
        RCLCPP_DEBUG(node_->get_logger(), "Sync parameter /timer/rate: load - %f Hz", rate);
    } else {
	node_->set_parameter(rclcpp::Parameter(name_node_ + "/timer/rate", rate));
        RCLCPP_DEBUG(node_->get_logger(), "Sync parameter /timer/rate: set - %f Hz", rate);
    }
    timer_->reset();
    // Names TF
    if (node_->has_parameter(name_node_ + "/" + tf_string)) {
        RCLCPP_DEBUG(node_->get_logger(), "Sync parameter %s: load", tf_string.c_str());
        node_->get_parameter(name_node_ + "/" + tf_string + "/" + joint_string, tf_joint_string_);
    } else {
        RCLCPP_DEBUG(node_->get_logger(), "Sync parameter %s: set", tf_string.c_str());
        tf_joint_string_ = joint_string;
        node_->set_parameter(rclcpp::Parameter(name_node_ + "/" + tf_string + "/" + joint_string, tf_joint_string_));
    }
    joint.header.frame_id = tf_joint_string_;
}

void ROSMaestroController::addServo(std::string name, int channel) {
    int length = 0;
    servo_t temp_servo;
    std::ostringstream convert;
    temp_servo.name = name;
    temp_servo.channel = channel;
    node_->get_parameter(name_node_ + "/servo/length", length);
    node_->set_parameter(rclcpp::Parameter(name_node_ + "/servo/length", length + 1));
    convert << length;
    joint.name.resize(length + 1);
    joint.position.resize(length + 1);
    joint.velocity.resize(length + 1);
    joint.effort.resize(length + 1);
    list_servo.resize(length + 1);
    node_->set_parameter(rclcpp::Parameter(name_node_ + "/servo/name/" + convert.str(), temp_servo.name));
    node_->set_parameter(rclcpp::Parameter(name_node_ + "/servo/channel/" + convert.str(), temp_servo.channel));
    servo[temp_servo.name] = temp_servo.channel;
    maestroSetAngle(temp_servo.channel, 0);
}
