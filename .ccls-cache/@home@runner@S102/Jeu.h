#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Carte.h"
#include "Joueur.h"
#include <vector>
#include <string>
#include <set>
using namespace std;

class Jeu {
  vector<Carte> _reserve;
  Joueur _joueur1;
  Joueur _joueur2;
  int _langue;
  vector<Carte> _tri(const vector<Carte>&);

public:
  // Constructeur vide
  Jeu();

  // Constructeur avec arguments
  Jeu(const vector<Carte>& reserve, const Joueur& joueur1, const Joueur& joueur2, int langue);

  // Accès à la réserve de cartes
  vector<Carte> getReserve() const;

  // Accès aux joueurs
  Joueur getJoueur1() const;
  Joueur getJoueur2() const;

  // Modification des joueurs
  void setJoueur1(Joueur joueur);
  void setJoueur2(Joueur joueur);

  // Vérifie si la partie est finie et renvoie le joueur vainqueur
  bool fini(Joueur & vainqueur);
  // Lance une manche (ou un tour)
  void unTour();
  // Affiche les règles du jeu
  void afficheRegle();
  // Affiche les stratégies
  void afficheStrat();
  
};
// Compare les attaques des 2 cartes
bool compareCarteAttaque(Carte a, Carte b);
// Renvoie l'indice d'une carte dans un paquet
int getIndex(const vector<Carte>& paquet, const Carte& carte);
// Trie un paquet de cartes en fonction d'un critère
vector<Carte> triCritereCarte(const vector<Carte>& paquetTrie, int critere);
// Pour le trie 
  //trie attaque croissante
  bool attaqueASC(const Carte& a, const Carte& b);
  //trie attaque décroissante
  bool attaqueDESC(const Carte& a, const Carte& b);
  //trie magie croissante
  bool magieASC(const Carte& a, const Carte& b);
  //trie magie décroissante
  bool magieDESC(const Carte& a, const Carte& b);
  //trie defense croissante
  bool defenseASC(const Carte& a, const Carte& b);
  //trie defense decroissante
  bool defenseDESC(const Carte& a, const Carte& b);
  //score croissant
  bool scoreASC(const Carte& a, const Carte& b);
  //score decroissant
  bool scoreDESC(const Carte& a, const Carte& b);
  // LA fonction renvoie le vecteur d'indice du trie d'un paquet de carte
  bool Alphabet(const Carte& a, const Carte& b);
  vector<int> trieur(const vector<Carte> paquet, int critere,const vector<Carte> piocheInitial);
  
#endif // JEU_H_INCLUDED
