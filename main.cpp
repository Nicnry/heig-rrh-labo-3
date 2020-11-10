/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation  : 05.11.2020
Description    : Ce programme permet d'afficher des pages de calendrier entre 2 dates
                 qui seront entrées par l'utilisateur.
Remarque(s)    : Les données utilisateurs ne comprennent pas le jour. Nous avons
 comme contrainte l'interdiction d'utiliser des outils que nous n'avons pas vu en
 cours.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include "saisieUtilisateur.h"
#include "affichageConsole.h"

using namespace std;

int main() {
   string rejouer;
   do{

      unsigned moisDebut, anneeDebut, moisFin, anneeFin, nbMois = 0;
      const string MESSAGE_DEBUT = "Entrez la date de debut [mm aaaa] : ";
      const string MESSAGE_FIN = "Entrez la date de fin [mm aaaa] : ";


      bool dateFinPlusGrandQueDebut = false;

      // Gére le saisie utilisateur, jusqu'à que celle-ci soit valide
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

      // Affichage du calendrier et message de fin
      afficherCalendrier(moisDebut,anneeDebut,nbMois);
      cout << "Voulez-vous quitter le programme ? [o/n] :";
      cin >> rejouer;
      cin.clear();

      while (rejouer != "o" && rejouer != "n") {
         cout << "Veuillez choisir entre 'o' et 'n' :";
        cin >> rejouer;
         cin.clear();
      }

   } while( rejouer == "n" );
   cin.ignore(1);

   return EXIT_SUCCESS;
}