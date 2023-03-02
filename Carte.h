#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
using namespace std;




class Carte{
  string _nom;
  int _attaque;
  int _defense;
  int _magie;

public:

  //Constructeur vide. Créé la carte : Mains nues, 1 d’attaque, 1 de défense et 0 de puissance magique
  Carte();

  //Constructeur avec arguments : nom de la carte, attaque, défense et magie
  Carte(const string&, int, int, int);

  //Renvoie un int correspondant a l'attaque
  int getAttaque()const;

  //Renvoie un int correspondant a la defense
  int getDefense()const;

  //Renvoie un int correspondant a la magie
  int getMagie()const;

  //Renvoie un string correspondant au nom de la carte
  string getNom()const;

  //Affichage détaillé des caractéristiques de la carte
  void affichageLong(int langue)const;

  //Affichage succinct en une ligne des caractéristiques de la carte.
  void affichageCourt()const;

  //Calcule les dégats physiques, retourne un nombre positif si la cible les subit, en   négatif sinon
  int degatPhysique(const Carte &)const;

  //Calcule les dégats magiques, retourne un nombre positif si la cible les subit, en négatif sinon
  int degatMagique(const Carte &)const;

  //Renvoie true si les deux cartes ont le même nom, false sinon
  bool memeCarte(const Carte &) const;

  //Calcule le score de la carte
  int scoreCarte()const;
};
// Affiche une présentation sous forme de tableau d'un vecteur de carte
void affichageTableau(const vector<Carte>& cartes, int langue);
#endif // CARTE_H_INCLUDED