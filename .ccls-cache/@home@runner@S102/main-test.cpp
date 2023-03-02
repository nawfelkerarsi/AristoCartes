#include "Carte.h"
#include "Jeu.h"
#include "Joueur.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void mainTest(vector<Carte>& cartes) {
  int langue = 1;
  Carte c1; // Constructeur class carte vide
  Carte c2("Poignée de porte magique", 2, 0, 5); 
  // Test de la fonction affichageLong
  cout << "-----Test de affichageLong-----" << endl;
  c1.affichageLong(langue);
  // Test de la fonction affichageCourt
  cout << "-----Test de affichageCourt----" << endl;
  c2.affichageCourt();
  // Test de la fonction degatPhysique
  cout << "-----Tests de degatPhysique----" << endl;
  if (c1.degatPhysique(c2) == 2) {
    cout << "Test reussi" << endl;
  } else {
    cout << "Test echoue" << endl;
  }
  if (c2.degatPhysique(c1) == -2) {
    cout << "Test reussi" << endl;
  } else {
    cout << "Test echoue" << endl;
  }
  // Test de la fonction degatMagique
  cout << "-----Tests de degatMagie----" << endl;
  if (c1.degatMagique(c2) == 5) {
    cout << "Test reussi" << endl;
  } else {
    cout << "Test echoue" << endl;
  }
  if (c2.degatMagique(c1) == -5) {
    cout << "Test reussi" << endl;
  } else {
    cout << "Test echoue" << endl;
  }
   // Test de la classe Joueur 
    // Test de la fonction affichage joueur
  cout << "-----Affichage d'un joueur-----" << endl;
  Carte c3("Poignée de main", 3, 0, 4);
  Joueur j;
  Joueur j1("Joueur test 1", 27, {c2, c3});
  j1.affichage();
    // Test de la fonction carteSuiv
  cout << "-----Test de carteSuiv-----" << endl;
  // Carte ctest = j1.sesCartes().back();
  // Carte c4;
  // j1.carteSuiv(c4);
  // if(c4.memeCarte(ctest)){
  //  cout << "Test reussi" << endl;
  //}else{
  //  cout << "Test echoue" << endl;
  //}
    // Test de la fonction possedeCartes
  cout << "-----Test possedeCartes-----" << endl;
  if (j1.possedeCartes()) {
    cout << "Test reussi" << endl;
  } else {
    cout << "Test echoué" << endl;
  }
    // Test de la fonction enJeu
  cout << "-----Test enJeu-----" << endl;
  if (j1.enJeu()) {
    cout << "Test reussi" << endl;
  } else {
    cout << "Test echoué" << endl;
  }

  cout << "-----Test class Jeu-----" << endl;

  // Initialisation de la pile de cartes de chaque joueur
  // Création des joueurs
  Joueur joueur5("Joueur 5", 25, {});
  Joueur joueur6("Joueur 6", 25, {});
  // Test de la classe Jeu
  // Initialisation de la pile de cartes de chaque joueur
  joueur5.initCartes(cartes);
  joueur6.initCartes(cartes);
  Jeu jeu(cartes, joueur5, joueur6, langue);

  // Test de l'accès à la réserve de cartes
  cout << "Réserve de cartes :" << endl;
  for (Carte carte : jeu.getReserve()) {
    carte.affichageCourt();
  }

  // Test de l'accès aux joueurs
  cout << endl << "Joueur 1 :" << endl;
  jeu.getJoueur1().affichage();
  cout << endl << "Joueur 2 :" << endl;
  jeu.getJoueur2().affichage();

  // Test de la modification des joueurs
  cout << endl << "Modification des joueurs :" << endl;
  jeu.setJoueur1(Joueur("Joueur 1 modifié", 25, {Carte("Épée", 10, 1, 3)}));
  jeu.setJoueur2(Joueur("Joueur 2 modifié", 15, {Carte("Bouclier", 5, 8, 0)}));
  cout << "Joueur 1 :" << endl;
  jeu.getJoueur1().affichage();
  cout << endl << "Joueur 2 :" << endl;
  jeu.getJoueur2().affichage();

  // Test de la fonction fini
  cout << endl << "Test de la fonction fini :" << endl;
  Joueur vainqueur;
  while (!jeu.fini(vainqueur)) {
    cout << "Partie en cours" << endl;
    jeu.setJoueur2(Joueur("Joueur 2 modifié", 0, {Carte("Bouclier", 5, 8, 0)}));
  }
  cout << "Partie terminée, le vainqueur est " << vainqueur.sonNom() << endl;

  // Test fonction construireRangsAttaqueCroissante
  cout << endl << "Test de de trie par attaque croissante :" << endl;
  vector<int> rangs = trieur(cartes, 1, cartes);
  for (int i = 0; i < rangs.size(); i++) {
    cout << "index[" << rangs[i] << "] ";
    cartes[rangs[i]].affichageCourt();
  }
  // Test de la fonction trieur
  cout << endl << "Test de trie, score et index  :" << endl;
  rangs = trieur(cartes, 2, cartes);
  for (int i = 0; i < rangs.size(); i++) {
    cout << "index[" << rangs[i] << "] ";
    cout << "score[" << cartes[rangs[i]].scoreCarte() << "] ";
    cartes[rangs[i]].affichageCourt();
  }
  cout << endl << "Test de trie score :" << endl;
  rangs = trieur(cartes, 8, cartes);
  for (int i = 0; i < rangs.size(); i++) {
    cout << "index[" << rangs[i] << "] ";
    cout << "score[" << cartes[rangs[i]].scoreCarte() << "] ";
    cartes[rangs[i]].affichageCourt();
  }
  joueur5.rempliCartes(rangs);
  joueur6.rempliManuCartes(langue);
  // Test de la fonction scoreCarte
  cout << "Test de scoreCarte" << endl;
  if (c2.scoreCarte() == 7) {
    cout << "Test reussi" << endl;
  } else {
    cout << "Test echoue" << endl;
  }
}
