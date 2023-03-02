#include "Jeu.h"
#include "Joueur.h"
#include "Carte.h"
#include <algorithm>
#include <string>


// Constructeur vide
Jeu::Jeu() {}

// Constructeur avec arguments
Jeu::Jeu(const vector<Carte>& reserve, const Joueur& joueur1, const Joueur& joueur2, int langue) {
  _reserve = _tri(reserve);
  _joueur1 = joueur1;
  _joueur2 = joueur2;
  _langue = langue;
}

// Accès à la réserve de cartes
vector<Carte> Jeu::getReserve() const { return _reserve; }

// Accès aux joueurs
Joueur Jeu::getJoueur1() const { return _joueur1; }

Joueur Jeu::getJoueur2() const { return _joueur2; }

// Modification des joueurs
void Jeu::setJoueur1(Joueur joueur) { _joueur1 = joueur; }

void Jeu::setJoueur2(Joueur joueur) { _joueur2 = joueur; }

// Vérifie si la partie est finie et renvoie le joueur vainqueur
bool Jeu::fini(Joueur &vainqueur) {
  if (_joueur1.sonPrestige() <= 0) {
    vainqueur = _joueur2;
    return true;
  } else if (_joueur2.sonPrestige() <= 0) {
    vainqueur = _joueur1;
    return true;
  } else if (!_joueur1.possedeCartes() && !_joueur2.possedeCartes()) {
    if (_joueur1.sonPrestige() > _joueur2.sonPrestige()) {
      vainqueur = _joueur1;
    } else {
      vainqueur = _joueur2;
    }
    return true;
  } else {
    return false;
  }
}
  // Lance une manche (ou un tour)
void Jeu::unTour() {
  _joueur1.jouentUneCarte(_joueur2, _langue);
}


  // Affiche les règles du jeu
void Jeu::afficheRegle(){
      if(_langue == 1){
        cout << endl << "[ Regles du jeu ]" << endl;
        cout << "Le jeu consiste en l'affrontement de cartes.\n"
                "Chaque cartes dispose des trois caractéristiques suivantes :\n"
                "- Attaque : Puissance d'attaque physique. Celui qui a la plus\n"
                "            eleve gagne le combat physique.\n"
                "- Defense : Permet de réduire les dégats physiques recus de sa \n"
                "            valeur (si vous disposez de 2 de défense et que\n" 
                "            l'adversaire a \n"
                "            une attaque de 3, vous ne recevrez que 1 dégats.\n"
                "- Magie :   Même principe que pour l'attaque, mais dans le combat\n"
                "            magique.\n";
        cout << "Entrez 'ok' pour continuer."<< endl;
      }else if(_langue == 2){
        cout << endl << "[Rules of the game]" << endl;
        cout << "The game consists of a clash of cards.\n"
                 "Each card has the following three characteristics:\n"
                 "- Attack:  Physical attack power. Whoever has the most\n"
                 "           student wins physical combat.\n"
                 "- Defense: Allows you to reduce the physical damage received\n" 
                 "           from your \n"
                 "           value (if you have 2 defense and the opponent has \n"
                 "           an attack of 3, you will only take 1 damage.\n"
                 "- Magic:   Same principle as attack, but in combat\n"
                 "           magical.\n";
        cout << "Enter 'ok' to continue."<< endl;
      }
      string regleAccepter;
      cout << "> ";
      cin >> regleAccepter;
        while (regleAccepter != "ok") {
          if(_langue == 1){
            cout << "Entrez 'ok' pour continuer." << endl;
          }else if(_langue == 1){
            cout << "Enter 'ok' to continue."  << endl;
          }
          cout << "> ";
        cin >> regleAccepter;
      }
}
// Compare les attaques des 2 cartes
bool compareCarteAttaque(Carte a, Carte b) {
  if (a.getAttaque() == b.getAttaque()) {
    if (a.getMagie() == b.getMagie()) {
      return a.getDefense() < b.getDefense();
    } else {
      return a.getMagie() > b.getMagie();
    }
  } else {
    return a.getAttaque() < b.getAttaque();
  }
}
// Renvoie l'indice d'une carte dans un paquet
int getIndex(const vector<Carte> &paquet, const Carte &carte) {
  for (int i = 0; i < paquet.size(); i++) {
    if (paquet[i].memeCarte(carte)) {
      return i;
    }
  }
  return -1;
}
//trie attaque croissante
bool attaqueASC(const Carte &a, const Carte &b) {
  if(a.getAttaque() == b.getAttaque()){
    if(a.getMagie() == b.getMagie()){
      return a.getDefense() < b.getDefense();
    }else{
      return a.getMagie() < b.getMagie();
    }
  }else{
    return a.getAttaque() < b.getAttaque();
  }
}
//trie attaque décroissante
bool attaqueDESC(const Carte &a, const Carte &b) {
  if(a.getAttaque() == b.getAttaque()){
    if(a.getMagie() == b.getMagie()){
      return a.getDefense() > b.getDefense();
    }else{
      return a.getMagie() > b.getMagie();
    }
  }else{
    return a.getAttaque() > b.getAttaque();
  }
}
//trie magie croissante
bool magieASC(const Carte &a, const Carte &b) {
  return a.getMagie() < b.getMagie();
}
//trie magie décroissante
bool magieDESC(const Carte &a, const Carte &b) {
  return a.getMagie() > b.getMagie();
}
//trie defense croissante
bool defenseASC(const Carte &a, const Carte &b) {
  return a.getDefense() < b.getDefense();
}
//trie defense decroissante
bool defenseDESC(const Carte &a, const Carte &b) {
  return a.getDefense() > b.getDefense();
}
//score croissant
bool scoreASC(const Carte &a, const Carte &b) {
  return a.scoreCarte() < b.scoreCarte();
}
//score decroissant
bool scoreDESC(const Carte &a, const Carte &b) {
  return a.scoreCarte() > b.scoreCarte();
}
//trie par ordre alphabetique
bool Alphabet(const Carte&a, const Carte &b) {
  return a.getNom() < b.getNom();
}
// Trie un paquet de cartes en fonction d'un critère
vector<Carte> triCritereCarte(const vector<Carte>& paquet, int critere){
  vector<Carte> paquetOrdonne = paquet;
    switch (critere){
      case 1:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), attaqueASC);
        break;
      case 2:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), attaqueDESC);
        break;
      case 3:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), magieASC);
        break;
      case 4:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), magieDESC);
        break;
      case 5:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), defenseASC);
        break;
      case 6:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), defenseDESC);
        break;
      case 8:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), scoreASC);
        break;
      case 9:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), scoreDESC);
        break;
      case 10:
        sort(paquetOrdonne.begin(), paquetOrdonne.end(), Alphabet);

        break;
     default:
        break;
  }
    return paquetOrdonne;
}
// LA fonction renvoie le vecteur d'indice du trie d'un paquet de carte
vector<int> trieur(const vector<Carte> paquet, int critere,const vector<Carte> piocheInitial) {
    vector<int> rangs;

      vector<Carte> paquetTrie = triCritereCarte(paquet, critere);
      for (int i = 0; i < paquetTrie.size(); i++) {
      rangs.push_back(getIndex(paquet, paquetTrie[i]));
      }
  

  return rangs;
}
// Affiche les stratégies
void Jeu::afficheStrat(){
  if(_langue == 1){
      cout  << "0. Classement manuel\n"
            << "1. Attaque croissante\n"
            << "2. Attaque decroissante\n"
            << "3. Magie croissante\n" 
            << "4. Magie decroissante\n" 
            << "5. Defense croissante\n"
            << "6. Defense decroissante\n" << endl;
  }else if(_langue == 2){
      cout  << "0. Order custom \n"
            << "1. Increasing Attack\n"
            << "2. Decreasing Attack\n"
            << "3. Growing Magic\n"
            << "4. Fading Magic\n"
            << "5. Increasing Defense\n"
            << "6. Decreasing Defense\n" << endl;
  }

}
// Tri du vecteur Cartes (ordre alphabetique) avant de le placer de la reserve
vector<Carte> Jeu::_tri(const vector<Carte>& paquet){
  vector<Carte> v = triCritereCarte(paquet, 10);
  return v;
}