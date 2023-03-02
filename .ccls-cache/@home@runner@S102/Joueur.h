#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Carte.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

class Joueur {
  string _nom;
  int _PtPrestige;
  vector<Carte> _pileCartes;
  vector<int> _rangsCartes;

public:
  // Constructeur vide
  Joueur();

  // Constructeur avec arguments
  Joueur(const string&, int, const vector<Carte>&);

  // Renvoie le nom du joueur
  string sonNom() const;

  // Renvoie le prestige du joueur
  int sonPrestige() const;

  // Renvoie la pile de carte du joueur
  vector<Carte> sesCartes() const;

  // Soustrait l'int passé en paramètre au prestige du joueur
  void moinsPrestige(int);

  // Affiche les caractéristiques du joueur
  void affichage() const;

  // Initialise la pile de cartes du joueur (prend les 20 premières cartes de la reserve)
  void initCartes(vector<Carte>&);
  // Verifie si un joueur possède encore des cartes
  bool possedeCartes() const;
  // Anticipe la carte suivante et la joue
  void carteSuiv();
  // Verifie si un joueur est encore en Jeu
  bool enJeu() const;
  // Faire jouer une carte à un joueur
  void jouentUneCarte(Joueur &, int langue);
  // Mélange le paquet de carte
  void melange(vector<Carte>&);
  // Mets des cartes dans le deck d'un joueur
  void rempliCartes(vector<int>&);
  // Demande au joueur de sélectionner ses cartes
  void rempliManuCartes(int langue);
  // remplissage automatique de carte (AI)
  void rempliAutoCartes();
  // Définie les rangs d'un paquets de cartes pour le trie
  void defRangsCartes(vector<int>& rangsCartes);
  // Renvoie le vecteur de rang d'un paquet de cartes
  vector<int> getRangsCartes();
  // Affiche la listes des cartes
  void afficheListeCartes(int langue);
  // Affiche le status d'une manche
  void messageTour(int degat, int langue);
};

#endif