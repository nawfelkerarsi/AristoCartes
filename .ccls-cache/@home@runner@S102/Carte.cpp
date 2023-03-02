#include "Carte.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Constructeur vide.
Carte::Carte() {
  _nom = "Mains nues";
  _attaque = 1;
  _defense = 0;
  _magie = 0;
}
//Constructeur avec arguments
Carte::Carte(const string& nom, int attaque, int defense, int magie) {
  _nom = nom;
  _attaque = attaque;
  _defense = defense;
  _magie = magie;
}
//Renvoie un int correspondant a l'attaque
int Carte::getAttaque() const { return _attaque; }
//Renvoie un int correspondant a la defense
int Carte::getDefense() const { return _defense; }
//Renvoie un string correspondant au nom de la carte
string Carte::getNom() const { return _nom; }
//Renvoie un int correspondant a la magie
int Carte::getMagie() const { return _magie; }
//Affichage détaillé des caractéristiques de la carte
void Carte::affichageLong(int langue) const {
  cout << "***************************" << endl;
  if(langue == 1){
    cout << "Nom : " << _nom << endl;
    cout << "Attaque : " << _attaque << endl;
    cout << "Defense : " << _defense << endl;
    cout << "Magie : " << _magie << endl;
  }else if(langue == 2){
    cout << "Name : " << _nom << endl;
    cout << "Attack : " << _attaque << endl;
    cout << "Defense : " << _defense << endl;
    cout << "Magic : " << _magie << endl;
  }
  cout << "***************************" << endl;
}
//Affichage succinct en une ligne des caractéristiques de la carte.
void Carte::affichageCourt() const {
  cout << _nom << "[ " << _attaque << " , " << _defense << " , " << _magie
       << " ]" << endl;
}
// Affiche une présentation sous forme de tableau d'un vecteur de carte
void affichageTableau(const vector<Carte>& cartes, int langue) {
  cout << left << setfill('-') << "+" << setw(10) << "" << setw(20) << "+" << "+" << setw(9)
     << "" << "+" << setw(9) << "" << "+" << setw(9) << "" << "+" << setfill(' ') << endl;
  if(langue == 1){
      cout << left << "|" << setw(11) << "Numéro" << "|" << setw(19) << "Nom de la carte"
       << "|" << setw(9) << "Attaque" << "|" << setw(10) << "Défense" << "|" << setw(9)
       << "Magie" << "|" << endl;
  }else if(langue == 2){
      cout << left << "|" << setw(10) << "Number" << "|" << setw(19) << "Name of the card"
       << "|" << setw(9) << "Attack" << "|" << setw(9) << "Defense" << "|" << setw(9)
       << "Magic" << "|" << endl;
  }
  
  
  cout << left << setfill('-') << "+" << setw(10) << "" << setw(20) << "+" << "+" << setw(9)
     << "" << "+" << setw(9) << "" << "+" << setw(9) << "" << "+" << setfill(' ') << endl;
  
  for (int i = 0; i < cartes.size(); i++) {
    cout << left << "|" <<setw(10) << i+1 << setw(20) << "|" + cartes[i].getNom() << "|" << setw(9)
         << cartes[i].getAttaque() << "|" << setw(9) << cartes[i].getDefense()
         << "|" << setw(9) << cartes[i].getMagie() << "|" << endl;
  }
  cout << left << setfill('-') << "+" << setw(10) << "" << setw(20) << "+" << "+" << setw(9)
       << "" << "+" << setw(9) << "" << "+" << setw(9) << "" << "+" << setfill(' ') << endl;
}
  //Calcule les dégats physiques, retourne un nombre positif si la cible les subit, en   négatif sinon
int Carte::degatPhysique(const Carte &object) const {
  int degat;
  if (_attaque > object.getAttaque()) {
    degat =  _attaque - object.getDefense();
  } else if(_attaque < object.getAttaque()){
    degat = object.getAttaque() - _defense;
    if(degat < 0){
      degat = 0;
    }
  }else{
    degat = 0;
  }
  return degat;
}
  //Calcule les dégats magiques, retourne un nombre positif si la cible les subit, en négatif sinon
int Carte::degatMagique(const Carte &object) const {
  int degat;
  if (_magie > object.getMagie()) {
    degat = object.getMagie() - _magie;
  } else {
    degat = abs(_magie - object.getMagie());
  }
  return degat;
}
  //Renvoie true si les deux cartes ont le même nom, false sinon
bool Carte::memeCarte(const Carte &object) const {
  bool result = object.getNom() == _nom;
  return result;
}
  //Calcule le score de la carte
int Carte::scoreCarte() const {
  int score = _attaque + _defense + _magie;
  return score;
}