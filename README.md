
# Installation et configuration du package ROS2

Bienvenue dans notre projet ROS2 ! 🚀

Ce projet contient des packages qui facilitent l'intégration de Kinect et du contrôleur Maestro avec ROS2. Voici un guide facile pour l'installation sur un autre ordinateur !

# Table des matières

1. [Prérequis](#prérequis)
2. [Cloner le dépôt](#cloner-le-dépot)
3. [Structure du workspace](#structure-du-workspace)
4. [Installation des dépendances](#installation-des-dépendances)
5. [Compilation du workspace](#compilation-du-workspace)
6. [Sourcing de l'environnement](#sourcing-de-lenvironnement)
7. [Lancer les nodes](#lancer-les-nodes)
   1. [Lancer ros2_kinect2](#lancer-ros2_kinect2)
   2. [Lancer maestro_node](#lancer-maestro_node)
8. [Structure des packages](#structure-des-packages)
   1. [argparse](#argparse)
   2. [maestro_node](#maestro_node)
   3. [ros2_kinect2](#ros2_kinect2)
   4. [ros_maestro](#ros_maestro)
9. [Contributions](#contributions)
10. [Licence](#licence)

## Prérequis

Avant de démarrer, assurez-vous que vous avez installé :

- **ROS2 Humble** (ou une version compatible)
- **CMake** (version récente)
- **Colcon** pour la construction des packages ROS2

Si vous n'avez pas encore installé ROS2, suivez les instructions officielles [ici](https://docs.ros.org/en/humble/Installation.html).

## Cloner le dépôt

Pour commencer, vous devez cloner ce dépôt dans votre espace de travail ROS2. Ouvrez votre terminal et tapez :

```bash
cd ~
git clone https://votre-repository-url.git
cd ros2_ws
```

## Structure du workspace

Voici la structure de votre workspace ROS2 après l'installation du package :

```bash
ros2_ws/
├── build/          # Apparait lors du build
├── install/        # Apparait lors du build
├── log/            # Apparait lors du build
└── src/
    ├── argparse/   # Contient des outils pour travailler avec les arguments
    ├── maestro_node/  # Le contrôleur Maestro
    ├── ros2_kinect2/  # Intégration Kinect
    ├── ros_maestro/  # Le package Maestro pour contrôler les moteurs
    ├── motor_controller/ # Pour controller les moteurs
    └── gyro_publisher_package/ # Pour publier les mesures du gyro
```

## Installation des dépendances

Assurez-vous que toutes les dépendances de votre workspace sont installées. Dans le terminal, allez dans le répertoire `ros2_ws` et tapez :

```bash
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -r -y
```

Cela va installer toutes les dépendances nécessaires à l'exécution de vos packages ROS2.

## Compilation du workspace

Une fois les dépendances installées, il est temps de compiler le workspace. Toujours dans le répertoire `ros2_ws`, exécutez :

```bash
colcon build --symlink-install
```

Cela construira tous les packages présents dans le dossier `src/` et générera les fichiers nécessaires dans les dossiers `build/` et `install/`.

## Sourcing de l'environnement

Avant d'utiliser votre workspace, il faut sourcer l'environnement ROS2. Exécutez cette commande dans votre terminal :

```bash
source install/setup.bash
```

Pour éviter de le refaire à chaque nouvelle session, vous pouvez ajouter cette ligne à la fin de votre fichier `~/.bashrc` :

```bash
echo "source ~/ros2_ws/install/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

## Lancer les nodes

### 1. Lancer `ros2_kinect2`

Pour démarrer le node Kinect, utilisez la commande suivante :

```bash
ros2 launch ros2_kinect2 kinect2_launch.py
```

Cela démarrera le node Kinect et commencera à envoyer des données.

### 2. Lancer `maestro_node`

Pour démarrer le node Maestro, utilisez la commande suivante :

```bash
ros2 launch maestro_node maestro_launch.py
```

Cela lancera le node Maestro, qui contrôlera le robot en fonction des messages reçus.

## Structure des packages

### `argparse`

Contient des outils utiles pour la gestion des arguments dans les scripts Python et C++. Il fournit des solutions pour la gestion des arguments complexes comme les options, les sous-commandes, etc.

### `maestro_node`

Ce package est responsable de la communication avec le contrôleur Maestro et des URDF associés. Il inclut :

- Des fichiers de lancement pour l'intégration dans ROS2
- Des fichiers de configuration YAML pour le comportement du contrôleur
- Des fichiers URDF pour la simulation du robot

### `ros2_kinect2`

Ce package contient l'intégration de Kinect pour ROS2. Il vous permet d'utiliser un capteur Kinect pour la détection et la capture de données de profondeur et d'image, et les diffuser dans ROS2 sous forme de topics.

### `ros_maestro`

Ce package est responsable du contrôle du robot via le contrôleur Maestro. Il inclut des scripts Python pour interagir avec le matériel et des fichiers de configuration pour ajuster les paramètres du robot.

### `motor_controller`

Ce package permet de simplifier l'utilisation de ros_maestro

### `gyro_publisher_package`

Le nœud ROS2 est initialisé avec le nom gyro_publisher. Ce package publie sur le topic gyro_data les mesures.

## Contributions

Vous voulez contribuer ? Super ! Envoyez vos pull requests, créez des issues ou améliorez la documentation. Si vous avez des questions, n'hésitez pas à consulter le fichier `CONTRIBUTING.md` ou à nous contacter.

Merci de faire partie de l'aventure ! 🎉

## Licence

Ce projet est sous licence MIT.

