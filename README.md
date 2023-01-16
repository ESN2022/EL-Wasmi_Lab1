# EL-Wasmi_Lab1
# **Lab 1: “Let there be light” - Implement a led chaser**

Dans ce laboratoire **"Lab 1 : Let there be light"**,* nous avons implémenté un contrôleur de suivi de LED en utilisant une carte Altera de10 lite. L'objectif était de créer un système qui permet de contrôler la vitesse et le déclenchement d'un LED chaser en utilisant un bouton et des Switchs. Les étapes suivies pour réaliser ce projet étaient les suivantes : conception de l'architecture, création d'un système Nios II de base, ajout de blocs et de logiciels pour contrôler les LEDs, implémentation d'un chenillard de 8 LEDs à l'aide d'un programme C, ajout d'un bouton pour déclencher le chenillard et utilisation de Switchs pour ajuster la vitesse, utilisation de la méthode de pooling au début pour détecter les changements d'état des boutons et des Switchs, et amélioration du code par la suite pour utiliser les interruptions.


# **Architecture système :**

Avant de commencer le projet, j'ai commencé par dessiner l'architecture pour comprendre les différents composants et comment ils sont connectés.



![arch](https://user-images.githubusercontent.com/75042681/212773375-1219b140-77f2-434b-8b0c-b91c39139b5f.PNG)

Le système d'architecture comprend un processeur Nios II, une mémoire RAM, un bloc JTAG pour la communication UART. J'ai également ajouté un PIO de 8 bits configuré en sortie pour contrôler les 8 LED, et deux PIO configurés en entrée : un de 1 bit pour détecter les changements du bouton-poussoir, et l'autre de 4 bits pour lire les switchs qui gèrent la vitesse du défilement des LEDs.
