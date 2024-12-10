/* 
 * File:   PololuController.h
 * Author: raffaello
 *
 * Created on 25 November 2013, 10:14
 */

#ifndef POLOLUCONTROLLER_H
#define POLOLUCONTROLLER_H

#include "TimeoutSerial.h"

// Inclusion de la bibliothèque standard pour les threads et mutex
#include <mutex>  // Remplacement de boost/thread.hpp par <mutex>

// Si tu veux utiliser des éléments de ROS2, tu peux inclure rclcpp ici, mais ce fichier n'en a pas besoin.
#include "rclcpp/rclcpp.hpp"  // Pour utiliser les nœuds dans ROS2 si nécessaire

class PololuController {
public:
    // Constructeur qui prend un pointeur sur un objet TimeoutSerial
    PololuController(TimeoutSerial* serial);

    // Destructeur virtuel pour la gestion des ressources
    virtual ~PololuController();

    // Méthodes pour manipuler les angles des moteurs
    void maestroSetAngle(int channel, double target);
    double maestroGetAngle(int channel);

private:
    // Pointeur vers l'objet TimeoutSerial, utilisé pour la communication série
    TimeoutSerial* serial;

    // Mutex pour la synchronisation des accès à la communication série (utilisation de std::mutex)
    std::mutex pololuMutex;  // Remplacement de boost::mutex par std::mutex

    // Méthodes privées pour manipuler directement les cibles des moteurs
    void maestroSetTarget(int channel, double target);
    double maestroGetTarget(int channel);
};

#endif	/* POLOLUCONTROLLER_H */

