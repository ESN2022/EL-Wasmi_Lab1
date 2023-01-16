# EL-Wasmi_Lab1
# **Lab 1: “Let there be light” - Implement a led chaser**

Dans ce laboratoire **"Lab 1 : Let there be light"**,* nous avons implémenté un contrôleur de suivi de LED en utilisant une carte Altera de10 lite. L'objectif était de créer un système qui permet de contrôler la vitesse et le déclenchement d'un LED chaser en utilisant un bouton et des Switchs. Les étapes suivies pour réaliser ce projet étaient les suivantes : conception de l'architecture, création d'un système Nios II de base, ajout de blocs et de logiciels pour contrôler les LEDs, implémentation d'un chenillard de 8 LEDs à l'aide d'un programme C, ajout d'un bouton pour déclencher le chenillard et utilisation de Switchs pour ajuster la vitesse, utilisation de la méthode de pooling au début pour détecter les changements d'état des boutons et des Switchs, et amélioration du code par la suite pour utiliser les interruptions.

Pour améliorer la lisibilité et la compréhension du projet, j'ai ajouté des images pour illustrer l'architecture système et des captures d'écran pour montrer les résultats obtenus.
J'ai également ajouté une vidéo démonstrative pour montrer le fonctionnement du chenillard de LEDs en utilisant les interruptions pour contrôler la vitesse et le déclenchement.


# **Architecture système :**

Avant de commencer le projet, j'ai commencé par concevoir l'architecture pour comprendre les différents composants et comment ils sont connectés. Le système d'architecture comprend un processeur Nios II, une mémoire RAM, un bloc JTAG pour la communication UART. J'ai également ajouté un PIO de 8 bits configuré en sortie pour contrôler les 8 LED, et deux PIO configurés en entrée : un de 1 bit pour détecter les changements du bouton-poussoir, et l'autre de 4 bits pour lire les commutateurs qui gèrent la vitesse du défilement des LEDs.

Voici un schéma de l'architecture système :

![arch](https://user-images.githubusercontent.com/75042681/212773375-1219b140-77f2-434b-8b0c-b91c39139b5f.PNG)

# Progress, results :
Au cours du projet, j'ai réalisé les étapes suivantes :
> 1er commit : Génération de la première architecture (nios2) et affectation des broches.

> 2ème commit : Validation du chenillard de LED avec la méthode de pooling :
- Modification de l’architecture Qsys en ajoutant les PIO de sortie pour les 8 LED, les PIO d’entrée pour le bouton poussoir et les commutateurs.
- Mise à jour du fichier d’entête
- Affectation des broches
- Création de la partie logicielle pour réaliser le chenillard de LED avec la méthode de pooling.

> 3ème commit : Laboratoire 1 terminé : Validation du chenillard de LED avec la méthode d’interruption

- Ajout des interruptions dans l’architecture Qsys pour le PIO du bouton poussoir et des commutateurs.
- Création d’une nouvelle application Nios II sur Eclipse, nommée “Lab1_interrupt”.
- Mise en place d’un nouveau code prenant en compte les interruptions du bouton et des commutateurs pour contrôler la poursuite des LED.

Les résultats obtenus ont montré que le système était capable de contrôler la vitesse et le déclenchement du chenillard de LED en utilisant un bouton et des commutateurs. La méthode d'interruption a également permis d'améliorer l'efficacité du système.
