#include <cstdlib>
#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include "TimeoutSerial.h"
#include "ROSMaestroController.h"

using namespace std;

std::string name_node = "maestro_node";

class MaestroNode : public rclcpp::Node {
public:
    // Constructeur du nœud MaestroNode, initialisation de la communication série
    MaestroNode(const std::string& serial_port)
        : Node(name_node), serial_(serial_port, 9600) {
        serial_.setTimeout(boost::posix_time::seconds(1));

        RCLCPP_INFO(this->get_logger(), "Start");

        // Initialiser le contrôleur avec le nœud actuel
        controller_ = std::make_shared<ROSMaestroController>(name_node, this->shared_from_this(), &serial_);
        controller_->loadConfiguration();

        // Timer pour gérer la communication série (non-bloquante)
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&MaestroNode::timer_callback, this)
        );
    }

    ~MaestroNode() {
        RCLCPP_INFO(this->get_logger(), "Close");
        serial_.close();
    }

private:
    void timer_callback() {
        try {
            // Exemple de lecture série
            std::string response = serial_.readStringUntil("\n");
            RCLCPP_INFO(this->get_logger(), "Received: '%s'", response.c_str());
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "Serial communication error: %s", e.what());
        }

        // D'autres logiques peuvent être ajoutées ici pour traiter des messages ou envoyer des commandes série
    }

    TimeoutSerial serial_;
    std::shared_ptr<ROSMaestroController> controller_;
    rclcpp::TimerBase::SharedPtr timer_; // Timer pour gérer la lecture série
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);

    if (argc != 2) {
        std::cerr << "Need serial port name as argument" << std::endl;
        return -1;
    }

    // Récupérer le nom du port série passé en argument
    std::string serial_port = argv[1];

    // Créer le nœud MaestroNode
    auto node = std::make_shared<MaestroNode>(serial_port);

    // Faire tourner le nœud
    rclcpp::spin(node);

    // Arrêter proprement
    rclcpp::shutdown();
    return 0;
}

