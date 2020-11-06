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
#include "saisiedate.h"
#include "moislitteral.h"

using namespace std;
int calculerPremierJour(int mois,int annee){
   int premierJour;
   //congruance de zeller
   // 0 = Samedi 1 = Dimanche 2 = Lundi ... 7 = Vendredi
   premierJour = (1 + (13*(mois+1)/5) + annee % 100 + annee % 100 / 4 + annee / 100 /
   4 - 2 * (annee / 100)) % 7;
   //1 = Lundi 2 = Mardi ... 7 = Dimanche
   premierJour = (premierJour + 6 -1 ) % 7 + 1;
   return premierJour;
}
bool calculerBissextile(int annee){
   return annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0;
}
int calculerNbJourMois(int mois, bool estBissextile) {
   if(mois == 2){
      if(estBissextile){
         return 29;
      }else{
         return 28;
      }
   }else if (mois <= 7 && (mois % 2) != 0 || mois >= 8 && (mois % 2 ) == 0) {
      return 31;
   }else if(mois <= 7 && (mois % 2) == 0 || mois >= 8 && (mois % 2) != 0){
      return 30;
   }else{
      return 0;
   }
}
void afficherCalendrier(int jourDebut,int nbJour){

}
int main() {
   unsigned int moisDebut, anneeDebut, moisFin, anneeFin;
   const string MESSAGE_DEBUT = "Entrez la date de debut [mm aaaa] : ";
   const string MESSAGE_FIN = "Entrez la date de fin [mm aaaa] : ";
   bool rejouer = true;
   char entreeRejouer;

   unsigned int nbMois = 0;
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
   cout << "NB MOIS " << nbMois << endl;
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
      if (moisActuel % 12 - 1 == 0) {
         anneeActuel += 1;
         estBissextile= calculerBissextile(anneeActuel);
      }
      if (moisActuel > 12) {
         moisActuel = (moisActuel - 1) % 12 + 1;
      }

      moisActuelLiterral = moisLitteral(moisActuel);
      premierJour = calculerPremierJour(moisActuel,anneeActuel);
      nbJours = calculerNbJourMois(moisActuel,estBissextile);
      cout << moisActuelLiterral << " " << anneeActuel<< endl;
      cout << "  L  M  M  J  V  S  D " << endl;

      nbEspace = premierJour -1;
      for(int i= 0; i < nbEspace; i ++)
      {
         cout << setw(3) <<" ";
      }
      for(int i = 0; i< nbJours; i++){
         cout << setw(3) << i ;
         if((premierJour + i) %7 == 0){
            cout<< endl;
         }
      }
      cout << endl;
   }
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