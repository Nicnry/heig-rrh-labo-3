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
#include "functions.h"

using namespace std;

int main() {
   unsigned int moisDebut, anneeDebut, moisFin, anneeFin;
   const string MESSAGE_DEBUT = "Entrez la date de debut [mm aaaa] : ";
   const string MESSAGE_FIN = "Entrez la date de fin [mm aaaa] : ";
   bool rejouer = true;
   char entreeRejouer;
   bool dateFinPlusGrandQueDebut = false;
   //do {

      do {
         saisieDate(moisDebut, anneeDebut, MESSAGE_DEBUT);
         saisieDate(moisFin, anneeFin, MESSAGE_FIN);
         if (anneeFin > anneeDebut || anneeFin == anneeDebut && moisFin >=
                                                                moisDebut) {
            dateFinPlusGrandQueDebut = true;
         } else {
            cin.clear(), cout << "Date non valide. Veuillez SVP recommencer."
                              << endl;
         }
      } while (!dateFinPlusGrandQueDebut);

      cout << moisDebut << " " << anneeFin << endl;
      cout << moisFin << " " << anneeFin;

     /* do {

         cout << "Voulez-vous quitter le programme ? [o/n] :";
         cin >> entreeRejouer;
         if(entreeRejouer == 'o'){
            rejouer = false;
         }
         cout << entreeRejouer << endl;
      }while(entreeRejouer != 'o' || entreeRejouer != 'n');
   }while(rejouer);*/

   return EXIT_SUCCESS;
}