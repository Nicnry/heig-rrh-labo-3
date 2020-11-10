/*
-----------------------------------------------------------------------------------
Nom du fichier : saisieDate.cpp
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 10.11.2020
Description :
Remarque(s) :
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <string>
#include <iostream>
#include <iomanip>
#include "affichageConsole.h"
#include "calculsDeDate.h"

using namespace std;
void afficherCalendrier (unsigned moisDebut,unsigned anneeDebut,unsigned nbMois){
   unsigned moisActuel,premierJour,nbJour,nbEspace;
   unsigned anneeActuel = anneeDebut;
   string moisActuelLiterral;
   bool estBissextile;

   for (int i = 0; i < nbMois; i++) {

      moisActuel = moisDebut + i;
      estBissextile = calculerBissextile(anneeActuel);

      if (moisActuel > 12) {
         moisActuel = (moisActuel - 1) % 12 + 1;
         if (moisActuel % 12 - 1 == 0) {
            anneeActuel += 1;
            estBissextile = calculerBissextile(anneeActuel);
         }
      }
      moisActuelLiterral = moisLitteral(moisActuel);
      premierJour = calculerPremierJour(1, moisActuel, anneeActuel);
      nbJour = calculerNbJourMois(moisActuel, estBissextile);

      cout << moisActuelLiterral << " " << anneeActuel << endl;
      cout << "  L  M  M  J  V  S  D " << endl;
      nbEspace = premierJour - 1;
      for (int j = 0; j < nbEspace; j++) {
         cout << setw(3) << " ";
      }
      for (int k = 1; k <= nbJour; k++) {
         cout << setw(3) << k;
         if ((premierJour + k - 1) % 7 == 0) {
            cout << endl;
         }
      }
      cout << endl;
   }
}