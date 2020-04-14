# TicTacToe

[![License: WTFPL](https://img.shields.io/badge/License-WTFPL-brightgreen.svg)](http://www.wtfpl.net/about/)


> L'objectif de ce projet est de créer une jeu de Morpion uniquement en ligne de commande et en C.


## Installation
Commencer par cloner ce dépot et lancer le jeu. Dans une console, tapez :
```
$ git clone https://github.com/SamuelHuet/TicTacToe
$ cd TicTacToe && ./play
```
## Comment jouer
Au lancement, le jeu vous demandera quel symbol vous souhaitez pour représenter votre pion, ainsi que celui de votre adversaire. A noter qu'il est interdit d'utiliser le caractère `?` car réservé au programme, et que les chiffres sont également à éviter. Vous pouvez aussi taper `@` pour jouer contre une Intelligence artificielle.
```
Select the player1 symbol then press [ENTER],
type '@' to let play an AI
```
Une fois vos caractères créé, le jeu commence. Il faudra alors taper le numéro de la case sur laquelle vous souhaitez jouer pour placer votre symbol à cet endroit là.
```
-------------------
|  1  |  2  |  3  |
-------------------
|  4  |  5  |  6  |
-------------------
|  7  |  8  |  9  |
-------------------

[PLAYER1] Select the number's box you want to play then press [ENTER]
```
A la fin de la partie, si le match n'est pas nul, le gagnant sera affiché de la sorte :
```
--------------WINNER---------------
--------------PLAYER1--------------
```

## Fonctionnement

La grille s'organise autour d'une structure composé de trois chaines de caractères représentant les lignes du tableau. Cette structure m'a permis d'éviter l'utilisation de tableau à deux dimensions qui, bien qu'ils m'auraient grandement facilité la tâche au niveau des tests, ils m'ont surtout apportés des problèmes lors des appels des fonctions (passage par adresse).
```
typedef struct{
  unsigned char line1 [3];
  unsigned char line2 [3];
  unsigned char line3 [3];
} Grid_struct;
```
Le code d'organnise autour de quelques fonctions relativement simple. Je passe les deux première car elles n'ont rien d'intéréssant. La fonction `play_as()` permet de jouer un pion qu'il soit du joueur 1 ou 2. Elle gère également un IA qui placera le pion aléatoirement.
`Settings()` vous demandera quel pion vous souhaitez jouer, `check_win()` verifiera si la partie est finie, et qui l'a gagné et enfin `get_box()` vous demandera sur quelle case vous voulez jouer et vous refusera évidemment le coup si la case n'est pas libre.
```
init()
print_grid()
play_as()
Settings()
check_win()
get_box()
```
-------
## Gant
Un \# est équivalent à un jour de travail
#### Prévisionnel
```
GUI       #       
Settings  ##
Partie    ###
IA        ####
```
#### Réèl
Une intégration en continue m'a permis de corriger les bugs chaque fois que je les percevais, et ainsi de gagner énormément de temps sur l'intégration. Ma motivation m'a égalemnent permis de boucler ce projet bien plus rapidement que ce que je l'avais prévu.
```
GUI       #       
Settings  ##
Partie    ##
IA        ##
```
## Difficultés
Les principales difficultés venaient d'une part du fait que je n'avais as pratiqué le C depuis un certain temps, mais en plus, j'avais très peu pratiqué le C système. J'étais donc peu habitué aux fonctions `printf()` ou `scanf()` et à leur utilisations. Mais cela ne m'a pas empéché d'arriver à un résutat par tatonnement et en consultant les documentations.
