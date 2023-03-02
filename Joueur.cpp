#include "Joueur.h"
#include "Carte.h"
#include "Jeu.h"
#include <iostream>
#include <string>
#include <vector>
// Valeur par defaut du constructeur
Joueur::Joueur() {
  _nom = "Yugi";
  _PtPrestige = 25;
  _pileCartes = {Carte("main droite", 1, 0, 0), Carte("main gauche", 0, 1, 0),
                 Carte("tete", 1, -2, 0), Carte("bouche", 1, -1, 2)};
}
// définition des valeurs du constructeur
Joueur::Joueur(const string& nom, int PtPrestige, const vector<Carte>& pileCartes) {
  _nom = nom;
  _PtPrestige = PtPrestige;
  _pileCartes = pileCartes;
}
// Définie les rangs d'un paquets de cartes pour le trie
void Joueur::defRangsCartes(vector<int>& rangsCartes) {
  _rangsCartes = rangsCartes;
}
// Renvoie le nom du joueur
string Joueur::sonNom() const { return _nom; }
// Renvoie le prestige du joueur
int Joueur::sonPrestige() const { return _PtPrestige; }
// Renvoie la pile de carte du joueur
vector<Carte> Joueur::sesCartes() const { return _pileCartes; }
// Soustrait l'int passé en paramètre au prestige du joueur
void Joueur::moinsPrestige(int p) { _PtPrestige -= p; }
// Affiche les caractéristiques du joueur
void Joueur::affichage() const {
  cout << "Le joueur " << sonNom() << " a " << sonPrestige()
       << " points de prestige, il reste " << _pileCartes.size()
       << " cartes dans sa main." << endl;
}
  // Initialise la pile de cartes du joueur (prend les 20 premières cartes de la reserve)
void Joueur::initCartes(vector<Carte>& pileCartes) {
  for (int i = 0; i < pileCartes.size(); i++) {
    _pileCartes.push_back(pileCartes[i]);
  }
}
  // Anticipe la carte suivante et la joue
void Joueur::carteSuiv() {
  if (_rangsCartes.size() < 1)
    throw invalid_argument("Pas de cartes dans la pile.");
  _rangsCartes.pop_back();
}
// Verifie si un joueur possède encore des cartes
bool Joueur::possedeCartes() const {
  bool result = _pileCartes.size() > 0;
  return result;
}
// Verifie si un joueur est encore en Jeu
bool Joueur::enJeu() const {
  bool result = _PtPrestige > 0;
  return result;
}
 // Faire jouer une carte à un joueur
void Joueur::jouentUneCarte(Joueur &j, int langue) {
  if(langue == 1){
    cout << "> Le joueur " << _nom << " joue ";
  }else if(langue == 2){
    cout << "> The player " << _nom << " plays ";
  }

  _pileCartes[getRangsCartes().back()].affichageCourt();
  if(langue == 1){
    cout << "> Le joueur " << j.sonNom() << " joue ";
  }else if(langue == 2){
    cout << "> The player " << j.sonNom() << " plays ";
  }

  j.sesCartes()[j.getRangsCartes().back()].affichageCourt();
  j.sesCartes()[j.getRangsCartes().back()].affichageLong(langue);
  cout << endl;
  Carte carteJ1 = _pileCartes[getRangsCartes().back()];
  Carte carteJ2 = j.sesCartes()[j.getRangsCartes().back()];
  int degat = carteJ1.degatPhysique(carteJ2);
  carteSuiv();
  j.carteSuiv();
  if (degat > 0) {
    _PtPrestige -= degat;
    messageTour(degat, langue);
  
  } else if (degat < 0) {
    j.moinsPrestige(-degat);
    j.messageTour(degat, langue);
  } else {
    if(langue == 1){
      cout << "Egalite sur le combat physique." << endl;
    }else if(langue == 2){
      cout << "Equality on physical fight." << endl;
    }

  }

  degat = carteJ1.degatMagique(carteJ2);
  if (degat > 0) {
    _PtPrestige -= degat;
    messageTour(degat, langue);
  } else if (degat < 0) {
    j.moinsPrestige(-degat);
    j.messageTour(degat, langue);
  } else {
    if(langue == 1){
      cout << "Egalite sur le combat magique." << endl;
    }else if(langue == 2){
      cout << "Equality on magic fight." << endl;
    }

  }
  cout << endl;
}
// Mélange le paquet de carte
void Joueur::melange(vector<Carte> &v) {
  Carte temp;
  int r;
  for (int i = 0; i < v.size(); i++) {
    r = rand() % 100 + 1;
    temp = v.at(r);
    v.at(r) = v.at(i);
    v.at(i) = temp;
  }
  _pileCartes = v;
}
 // Mets des cartes dans le deck d'un joueur
void Joueur::rempliCartes(vector<int> &i) {
  vector<Carte> tempPileCartes = _pileCartes;
  for (int k = 0; k < 20; k++) {
    _pileCartes[k] = tempPileCartes[i[k]];
  }
}
// Demande au joueur de sélectionner ses cartes
void Joueur::rempliManuCartes(int langue) {
  vector<Carte> tempPileCartes = _pileCartes;
  _pileCartes = {};
  int numCarte; // c++ lol
  for (int c = 0; c < 20; c++) {
    if(langue == 1){
      cout << "Cartes restantes de la reserve:" << endl;
    }else if(langue == 2){
      cout << "Remaining sideboard cards:" << endl;
    }

    affichageTableau(tempPileCartes, langue);
    if(langue == 1){
      cout << c << "/20 cartes choisies, ";
      cout << "entrez un numero de carte" << endl;
    }else if(langue == 2){
      cout << c << "/20 chosen cards,";
      cout << "enter a card number" << endl;
    }
    cout << "> ";
    cin >> numCarte;
    int maxNumCarte = (tempPileCartes.size());
    if(numCarte>maxNumCarte){
      numCarte = tempPileCartes.size();
    }
    if(numCarte<1){
      numCarte = 1;
    }
    
    cout << endl;
    _pileCartes.push_back(tempPileCartes[numCarte-1]);
    if(langue == 1){
      cout << "Ajout de la carte ";
    }else if(langue == 2){
      cout << "Added card: ";
    }

    _pileCartes[c].affichageCourt();
    tempPileCartes.erase(tempPileCartes.begin() + numCarte-1);
  }
}
// remplissage automatique de carte (AI)
void Joueur::rempliAutoCartes() {
  vector<Carte> tempPileCartes = _pileCartes;
  _pileCartes = {};
  vector<int> temprangsJoueur2 = trieur(tempPileCartes, 1, tempPileCartes);
  vector<int> rangsJoueur2;
  for (int c = temprangsJoueur2.size() - 20; c < temprangsJoueur2.size(); c++) {
    _pileCartes.push_back(tempPileCartes[temprangsJoueur2[c]]);
  }
  rangsJoueur2 = trieur(_pileCartes, 1, _pileCartes);
  defRangsCartes(rangsJoueur2);
}
// Renvoie le vecteur de rang d'un paquet de cartes
vector<int> Joueur::getRangsCartes() { return _rangsCartes; }
// Affiche la listes des cartes
void Joueur::afficheListeCartes(int langue) {
  vector<Carte> pileCartes;
  for(int i = 0; i < _pileCartes.size(); i++){
    pileCartes.push_back(_pileCartes[_rangsCartes[i]]);
  }
  affichageTableau(pileCartes, langue);
}
// Affiche le status d'une manche
void Joueur::messageTour(int degat, int langue) {
  degat = -abs(degat);
  if(langue == 1){
  cout << "Le joueur " << _nom << " a subit " << degat
       << " point(s) de dégat";
  }else if(langue == 2){
  cout << "The player " << _nom << " suffered " << degat
       << " point(s) of damage";
  }

  if (_PtPrestige <= 0) {
    if(langue == 1){
      cout << ", il n'a plus de points de prestige" << endl;
    }else if(langue == 2){
      cout << ", he has no more prestige points" << endl;
    }

  } else {
    if(langue == 1){
      cout << ", il lui reste " << _PtPrestige << " point(s) de prestige" << endl;
    }else if(langue == 2){
      cout << ", he still has " << _PtPrestige << " point(s) of damage" << endl;
    }

  }
}

using namespace std;