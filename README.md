# AristoCartes

AristoCartes est un jeu de cartes. Le but est de réduire les points de prestige de l'adversaire à zéro en utilisant des cartes qui ont des statistiques d'attaque, de défense et de magie. Le vainqueur est le premier à envoyer son adversaire dans la boue (prestige à zéro) ou d’avoir plus de prestige que son adversaire à la fin de l’affrontement (lorsqu’il n’y a plus de carte ou lorsque les deux joueurs sont dans le négatif).

## Installation
Pour installer AristoCartes, vous devez disposer du compilateur C++ et de la bibliothèque standard C++ STL. Vous pouvez cloner le dépôt GitHub et compiler le programme en utilisant les commandes suivantes :
```bash
git clone https://github.com/nawfelkerarsi/AristoCartes.git

```

## Fonctionnalités
1. Le jeu AristoCartes est en français mais également disponible en anglais et les joueurs peuvent choisir leur langue préférée au lancement du jeu. 
2.En plus du mode joueur contre joueur, AristoCartes offre également la possibilité de jouer contre l'ordinateur. Pour jouer contre l'ordinateur, le joueur peut simplement choisir le mode "Contre un autre joueur" lors du lancement du jeu et sélectionner le niveau de difficulté souhaité. 
3.Le jeu est également personnalisable, avec la possibilité d'ajouter des cartes supplémentaires dans le fichier "cartes.txt" en respectant le modèle de données. Enfin, AristoCartes offre une expérience de jeu amusante et stratégique, adaptée aux joueurs qui cherchent à tester leur intelligence et leur compétence en matière de cartes.

## Capture d'écran
![screenshot](https://raw.githubusercontent.com/nawfelkerarsi/AristoCartes/main/screenshot.png)
## Utilisations

Lorsque le jeu démarre, vous devez choisir un pseudo pour chaque joueur si vous êtes en mode multi-joueur, ou simplement votre pseudo si vous êtes en mode solo. Ensuite, vous pouvez sélectionner les cartes que vous voulez ajouter à votre jeu de cartes. Les cartes sont stockées dans un fichier texte nommé `cartes.txt`. Vous pouvez modifier ce fichier pour ajouter, modifier ou supprimer des cartes.

Après avoir sélectionné vos cartes, vous devez choisir une stratégie pour votre jeu de cartes. Les stratégies disponibles sont :
- Par ordre de sélectionnement
- Attaque la plus élevée
- Attaque la moins élevée
- Défense la plus élevée
- Défense la moins élevée
- Magie la plus élevée
- Magie la moins élevée

Une fois que vous avez choisi votre stratégie, vous pouvez commencer le jeu en appuyant sur la touche Entrée. Le jeu vous présentera ensuite une carte à la fois pour chaque joueur. Si vous avez la carte avec l'attaque la plus élevée, vous infligez des dégâts à votre adversaire. Si vous avez la carte avec la défense la plus élevée, vous réduisez les dégâts infligés par votre adversaire. Si vous avez la carte avec la magie la plus élevée, vous infligez des dégâts à votre adversaire sans réduction.

Le jeu se poursuit jusqu'à ce qu'un joueur n'ait plus de cartes dans son jeu de cartes ou que le prestige d'un joueur atteigne zéro ou moins. Si les deux joueurs ont encore des cartes et que leur prestige est supérieur à zéro à la fin de la partie, le joueur avec le prestige le plus élevé remporte la partie.

<br>

<img src="https://raw.githubusercontent.com/nawfelkerarsi/PharmaMasque/main/static/pharmamasque/logoUPS%20dark.png#gh-light-mode-only" width="200"/><img src="https://raw.githubusercontent.com/nawfelkerarsi/PharmaMasque/main/static/pharmamasque/logoUPS%20white.png#gh-dark-mode-only" width="200"/>
