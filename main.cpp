/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 05.11.2020
Description : Ce programme permet d'afficher des pages de calendrier entre 2 dates
              qui seront entrées par l'utilisateur.
Remarque(s) : Les données utilisateurs ne comprennent pas le jour.
tutu : entrer les variables sur une seule ligne
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "saisieDate.h"
#include "moisLitteral.h"
#include "calculerPremierJour.h"
#include "calculerBissextile.h"
#include "calculerNbJourMois.h"

using namespace std;

int main() {
   unsigned int moisDebut, anneeDebut, moisFin, anneeFin;
   const string MESSAGE_DEBUT = "Entrez la date de debut [mm aaaa] : ";
   const string MESSAGE_FIN = "Entrez la date de fin [mm aaaa] : ";
   char entreeRejouer;

   unsigned int nbMois = 0;
   bool dateFinPlusGrandQueDebut = false;

   do {
      saisieDate(moisDebut, anneeDebut, MESSAGE_DEBUT);
      saisieDate(moisFin, anneeFin, MESSAGE_FIN);
      if (anneeFin > anneeDebut || anneeFin == anneeDebut && moisFin >= moisDebut) {
         dateFinPlusGrandQueDebut = true;
      } else {
         cin.clear(), cout << "Date non valide. Veuillez SVP recommencer." << endl;
      }
   } while (!dateFinPlusGrandQueDebut);


   // Calcul du nombre de mois total (donc le nombre de calendrier)
   switch (anneeFin - anneeDebut) {
      case 0:
         nbMois = moisFin - moisDebut + 1;
         break;
      case 1:
         nbMois = 12 - moisDebut + moisFin + 1;
         break;
      default:
         nbMois = (12 - moisDebut + 1) + (12 * (anneeFin - anneeDebut - 1)) +
                  moisFin;
         break;
   }

   unsigned int moisActuel;
   unsigned int anneeActuel = anneeDebut;
   string moisActuelLiterral;
   bool estBissextile;
   unsigned int premierJour;
   unsigned int nbJours;
   unsigned int nbEspace;
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
      premierJour = calculerPremierJour(1,moisActuel, anneeActuel);
      nbJours = calculerNbJourMois(moisActuel, estBissextile);
      cout << moisActuelLiterral << " " << anneeActuel << endl;
      cout << "  L  M  M  J  V  S  D " << endl;
      nbEspace = premierJour - 1;
      for (int i = 0; i < nbEspace; i++) {
         cout << setw(3) << " ";
      }
      for (int i = 1; i <= nbJours; i++) {
         cout << setw(3) << i;
         if ((premierJour + i - 1) % 7 == 0) {
            cout << endl;
         }
      }
      cout << endl;
   }

   /*
   do {
		cout << "Voulez-vous quitter le programme ? [o/n] :";
		cin >> entreeRejouer;
		cout << entreeRejouer << endl;
	} while(entreeRejouer != 'o' || entreeRejouer != 'n'); */

   return EXIT_SUCCESS;
}