#ifndef ROSMAESTROCONTROLLER_H
#define ROSMAESTROCONTROLLER_H

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <map>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <sstream>
#include "PololuController.h"
#include "TimeoutSerial.h"

class ROSMaestroController : public PololuController
{
public:
    // Constructeur
    ROSMaestroController(std::string name_node, std::shared_ptr<rclcpp::Node> node, TimeoutSerial* serial);
    
    // Destructeur
    ~ROSMaestroController();

    // Méthodes publiques
    void loadConfiguration();
    void addServo(std::string name, int channel);

private:
    // Méthodes privées
    void timerCallback();
    void connectCallback(const rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr& pub);
    void jointCallback(const sensor_msgs::msg::JointState::SharedPtr msg);

    // Membres privés
    std::shared_ptr<rclcpp::Node> node_;  // Node ROS2
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub_joint; // Publisher pour les joint states
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_joint; // Subscription pour les joint states
    std::shared_ptr<rclcpp::TimerBase> timer_;  // Timer ROS2

    // Variables liées aux servos
    std::string name_node_;  // Nom du noeud
    std::map<std::string, int> servo;  // Map des servos (nom -> canal)
    sensor_msgs::msg::JointState joint;  // Message des états des joints
    std::vector<std::string> list_servo;  // Liste des servos
    std::string tf_joint_string_;  // TF joint string

    // Structure pour définir un servo
    struct servo_t {
        std::string name;  // Nom du servo
        int channel;       // Canal du servo
    };
};

#endif // ROSMAESTROCONTROLLER_H
