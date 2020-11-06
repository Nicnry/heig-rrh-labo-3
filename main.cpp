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
      cout << moisFin << " " << anneeFin << endl;

     /* do {

         cout << "Voulez-vous quitter le programme ? [o/n] :";
         cin >> entreeRejouer;
         if(entreeRejouer == 'o'){
            rejouer = false;
         }
         cout << entreeRejouer << endl;
      }while(entreeRejouer != 'o' || entreeRejouer != 'n');
   }while(rejouer);*/

   // TODO : Afficher le calendrier
   // TODO : Defiler les mois
   // TODO : Afficher les jours jusqu'a 31
   // TODO : Calculer le nombre de jours du mois pour un vrai résultat

   // TODO : Calculer le jour du mois
   // TODO : Year code
   // TODO : Month code
   // TODO : Century code
   // TODO : Date number
   // TODO : Leap year code
   // TODO : (Addition de tout - leap year code) mod 7


   int nbMois;
   // Selon le nombre d'années qui sépare les deux dates, une action différente
   // est entreprise
   switch(anneeDebut - anneeFin)
   {
      // Quand il n'y à pas d'années de différence, le nombre de mois totaux
      // correspond à la soustraction du mois le plus éloigné à celui le plus récent
      case 0:
         nbMois = moisFin - moisDebut;
         break;
         // Lorsqu'une année sépare deux dates, il faut prendre en compte tous les
         // mois pour parcourir le réstant de l'année et y ajouter le nombre de mois
         // pour arrivé à la date ciblée
      case 1:
         nbMois = 12 - moisDebut + moisFin;
         break;
         // Lorsqu'il y à plusieurs années qui sépare les dates, chaque année
         // complète comptabilise 12 mois et puis on applique la même logique que
         // lorsqu'il y a 1 ans qui sépare deux dates
      default:
         nbMois = (anneeFin - anneeDebut - 1) * 12 + 12 - moisDebut  + moisFin;
         break;
   }

   // Affichage du calendrier
   for (int i = moisDebut; i <= moisDebut + nbMois; i++) {
      switch (i % 12) {
         case 1:
            cout << "Janvier" << endl;
            break;
         case 2:
            cout << "Fevrier" << endl;
            break;
         case 3:
            cout << "Mars" << endl;
            break;
         case 4:
            cout << "Avril" << endl;
            break;
         case 5:
            cout << "Mai" << endl;
            break;
         case 6:
            cout << "Juin" << endl;
            break;
         case 7:
            cout << "Juillet" << endl;
            break;
         case 8:
            cout << "Aout" << endl;
            break;
         case 9:
            cout << "Septembre" << endl;
            break;
         case 10:
            cout << "Octobre" << endl;
            break;
         case 11:
            cout << "Novrembre" << endl;
            break;
         case 12:
            cout << "Decembre" << endl;
            break;
      }
   }

   return EXIT_SUCCESS;
}