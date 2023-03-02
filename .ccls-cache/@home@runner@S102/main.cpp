#include "Carte.h"
#include "Jeu.h"
#include "Joueur.h"
#include "main-test.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
  try {
    srand(time(NULL));
    //initialisation des CONSTANTES 
    const int VS_IA = 1;
    const int VS_JOUEUR = 2;
    const int PT_PRESTIGE_BASE = 25;
    //initialisation des variables/Classes
    vector<Carte> cartes;
    ifstream jeu;
    string nom;
    int attaque;
    int def;
    int magie;
    int nbL;
    Joueur j1;
    Joueur j2;

    jeu.open("cartes.txt");
    if (!jeu.eof()) {
      jeu >> nbL;
    }
    for (int i = 0; i < nbL & !jeu.eof(); i++) {
      jeu >> nom;
      jeu >> attaque;
      jeu >> def;
      jeu >> magie;
      cartes.push_back(Carte(nom, attaque, def, magie));
    }

  
    //mainTest(cartes); //<-- Sous programme contenant les tests
    
    // Mise en place de la partie
    int choixLangue;
    int choixMode;
    string nomJoueur;
    bool stop = false;
    while (!stop) {
      cout << "\n\n\n\n";
      cout << "Welcome to" << endl;
      cout << "  ___       _     _        _____            _       \n"
              " / _ \\     (_)   | |      /  __ \\          | |      \n"
              "/ /_\\ \\_ __ _ ___| |_ ___ | /  \\/ __ _ _ __| |_ ___   ___ \n"
              "|  _  | '__| / __| __/ _ \\| |    / _` | '__| __/ _ \\ / __|\n"
              "| | | | |  | \\__ \\ || (_) | \\__/\\ (_| | |  | ||  __/\\__ \\ \n"
              "\\_| |_/_|  |_|___/\\__\\___/ \\____/\\__,_|_|   \\__\\___||___/\n\n";
      cout << "          Game directed by Nawfel Kerarsi and Gaëtan Josse\n\n\n"<< endl;
      cout << "> Press [Enter] to Continue ";
      cin.ignore();
      cout << endl;
      // choix de la langue
      cout << "Choose a language" << endl;
      cout << "1. French" << endl;
      cout << "2. English" << endl;
      cout << "> ";
      cin >> choixLangue;
      while (choixLangue != 2 && choixLangue != 1) {
        cout << "Invalid choice, try again." << endl;
        cout << "> ";
        cin >> choixLangue;
      }
      cout << endl;
      int langue = choixLangue;
      Jeu jeuActuel(cartes, j1, j2, langue);
      //choix du mode de jeu
      if(choixLangue == 1){
        cout << "Choisir un mode de jeu" << endl;
        cout << "1. Contre un ordinateur" << endl;
        cout << "2. Contre un autre joueur" << endl;
      }else if(choixLangue == 2){
        cout << "Choose a game mode" << endl;
        cout << "1. Against a computer" << endl;
        cout << "2. Against another player" << endl;
      }
      cout << "> ";
      cin >> choixMode;
      while (choixMode != VS_IA && choixMode != VS_JOUEUR) {
        if(choixLangue == 1){
          cout << "Choix invalide, recommencez." << endl;
        }else if(choixLangue == 2){
          cout << "Invalid choice, try again." << endl;
        } 
        cout << "> ";
        cin >> choixMode;
      }
      cout << endl;
      if (choixMode == VS_IA) {
        if(choixLangue == 1){
          cout << "Veuillez entrer votre nom." << endl;
        }else if(choixLangue == 2){
          cout << "Please enter your name." << endl;
        }
        cout << "> ";
        cin >> nomJoueur;
        j1 = Joueur(nomJoueur, PT_PRESTIGE_BASE, jeuActuel.getReserve());
        j2 = Joueur("Terminator", PT_PRESTIGE_BASE, jeuActuel.getReserve());
      } else if (choixMode == VS_JOUEUR) {
        if(choixLangue == 1){
          cout << "Veuillez entrer le nom du joueur 1." << endl;
        }else if (choixLangue == 2){
          cout << "Please enter the name of player 1." << endl;
        }
        cout << "> ";
        cin >> nomJoueur;
        j1 = Joueur(nomJoueur, PT_PRESTIGE_BASE, jeuActuel.getReserve());
        if(choixLangue == 1){
          cout << "Veuillez entrer le nom du joueur 2." << endl;
        } else if (choixLangue == 2){
          cout << "Please enter the name of player 2." << endl;
        }
        cout << "> ";
        cin >> nomJoueur;
        j2 = Joueur(nomJoueur, PT_PRESTIGE_BASE, jeuActuel.getReserve());
      }
      
      
      jeuActuel.afficheRegle();
      affichageTableau(jeuActuel.getReserve(), langue);
      // Choix de la stratégie et constitution de la pioche
      int choixStrat;
      vector<int> rangsJoueur1, rangsJoueur2;
      
      cout << endl << j1.sonNom();
      if(langue == 1){
        cout << ", choisissez votre stratégie et construisez votre paquet de cartes." << endl;
      }else if(langue == 2){
        cout << ", choose your strategy and build your deck of cards." << endl;
      }

      jeuActuel.afficheStrat();
      cout << "> ";
      cin >> choixStrat;
      while (choixStrat > 6 || choixStrat < 0) {
          cout << "Invalid choice, try again." << endl;
          cout << "> ";
          cin >> choixStrat;
        }
      if(langue == 1){
        cout << "Entrez le numero des cartes que vous souhaitez ajouter a votre jeu."<< endl;
      }else if(langue == 2){
        cout << "Enter the number of cards you wish to add to your deck."<< endl;
      }

           
      j1.rempliManuCartes(langue);
      rangsJoueur1 = trieur(j1.sesCartes(), choixStrat, cartes);
      j1.defRangsCartes(rangsJoueur1);

      j1.afficheListeCartes(langue);
      if (choixMode == VS_IA) {
        // definir les strategie du robot
        j2.rempliAutoCartes();
        rangsJoueur2 = j2.getRangsCartes();
        j2.defRangsCartes(rangsJoueur2);
      } else {
        cout << endl
             << j2.sonNom();
        if(langue == 1){
        cout  << ", à votre tour de choisir votre stratégie et construire votre paquet de cartes." << endl;
        }else if(langue == 2){
        cout  << ", it's your turn to choose your strategy and build your deck of cards." << endl;
        }

             
        jeuActuel.afficheStrat();
        cout << "> ";
        cin >> choixStrat;
        while (choixStrat > 6 || choixStrat < 0) {
          cout << "Invalid choice, try again." << endl;
          cout << "> ";
          cin >> choixStrat;
        }
        if(langue == 1){
          cout << "Entrez le numero des cartes que vous souhaitez ajouter a votre jeu." << endl;
        }else if(langue == 2){
          cout << "Enter the number of cards you want to add to your deck." << endl; 
        }

        j2.rempliManuCartes(langue);
        rangsJoueur2 = trieur(j2.sesCartes(), choixStrat, cartes);

        j2.defRangsCartes(rangsJoueur2);
        j2.afficheListeCartes(langue);
      }
      // Préparation du joueur Vainqueur
      Joueur vainqueur;
      jeuActuel.setJoueur1(j1);
      jeuActuel.setJoueur2(j2);
      for (int k = 0; k < 20; k++) {
        if (!jeuActuel.fini(vainqueur)) {
          jeuActuel.unTour();
          if (!jeuActuel.fini(vainqueur)) {
            if(langue == 1){
              cout << "La partie continue avec les joueurs qui tirent une nouvelle carte de leur pile." << endl;
            }else if(langue == 2){
              cout << "The game continues with the players drawing a new card from their pile." << endl;
            }
          }
        }
      }
      //félicitation au vainqueur
      if(langue == 1){
        cout << "le joueur " << vainqueur.sonNom() << " a gagné, félicitation à lui !" << endl;
      }else if(langue == 2){
        cout << "the player " << vainqueur.sonNom() << " won, congratulations to him !" << endl;
      }
      // demande de rejouer
      string res;
      if(langue == 1){  
        cout << "Rejouer la partie ? [O/N]" << endl;
      }else if(langue == 2){
        cout << "Replay the game ? [Y/N]" << endl;
      }
      cout << "> ";
      cin >> res;
      if (res == "N" || res == "n" || res == "NON" || res == "Non" ||
          res == "non" || res == "NO" || res == "No" || res == "no") {
        stop = true;
      }
    }
    return 0;
  } catch (invalid_argument ex) {
    cout << ex.what() << endl; // exception
  }
}