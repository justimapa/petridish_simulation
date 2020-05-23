Ce programme est une simulation informatique d'une assiette de Petri modélisant le comportement de différents types de bactéries en compétition pour des sources de nutriment.

Les bactéries sont caractérisées par:
- leur capacité à se diviser
- les différentes mutations qu'ils subissent lors de la division
- les intéractions qu'ils ont avec les deux différentes sources de nutriment

La simulation a donc pour but final d'illustrer les mécanismes de séléction naturelle parmi les différents types de bactéries qui peuvent se trouver dans des environements différents dans l'assiette de Petri d'une simulation à l'autre.

##COMPILATION ET EXECUTION

Ce projet utilise [Cmake](https://cmake.org/) pour compiler


* en ligne de commande:
	- dans le dossier build: cmake ../src
	- make nom_cible pour la génération de la cible


* Dans QTCreator:
	- mise en place du projet : ouvrir le fichier src/CmakeLists.txt
	- choisir la cible à exécuter

##CIBLES PRINCIPALES:

* application -> application finale
* nutrimentTest -> permet de tester les nutriments 
* simpleBactTest -> permet de tester les bactéries simples
* twitchingTest -> permet de tester les bactéries à tentacule
* swarmTest -> permet de tester les bactéries avec comportement de groupe

##FICHIERS DE CONFIGURATION

Le fichier de configuration à utiliser pour toutes les cibles est app.json.

##COMMANDES

Les commandes pour l'utilisation d'une cible particulière sont données dans un panneau d'aide a droite de la fenêtre de simulation.

##MODIFICATION DE CONCEPTION

Le codage du projet a été realisé en adéquation avec l'énoncé (pas de modifications personnelles d'éléments de conception suggérés).

##EXTENSIONS

1. La possibilité d'avoir plusieurs assiettes de Petri dans un laboratoire. Le nombre d'assiettes de Petri peut etre modifié dans le fichier de configuration.

Les statistiques affichées correspondent à l'assiette de Petri visualisée, mais les différentes assiettes sont simulées simultanément.

2. Une classe Bacteriophage qui permet de simuler les impacts d'un organisme qui s'attaque aux bactéries. Les bactériophages peuvent avoir deux états: lytique ou lysogénique, et ceci impacte l'effet qu'ils ont sur les bactéries.

3. Les bactéries, quant à eux, peuvent développer ou perdre une immunité face aux effets des bactériophages. La probabilité de d'acquérir ou de perdre cette immunité est modifiable dans le fichier de configuration, et cette probabilité est propre à chaque type de bactérie.

Une page de statistiques a été ajoutée pour visualiser le nombre de bactériophages, de bactéries immunes et de bactéries vulnérables. 





