/*
-----------------------------------------------------------------------------------
Nom du fichier : calculsDeDate.cpp
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 10.11.2020
Description :
Remarque(s) :
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include "calculsDeDate.h"

using namespace std;

bool calculerBissextile(unsigned annee) {
   return annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0;
}

unsigned calculerNbJourMois(unsigned mois, bool estBissextile) {
   if (mois == 2) {
      if (estBissextile) {
         return 29;
      } else {
         return 28;
      }
   } else if (mois <= 7 && (mois % 2) != 0 || mois >= 8 && (mois % 2) == 0) {
      return 31;
   } else if (mois <= 7 && (mois % 2) == 0 || mois >= 8 && (mois % 2) != 0) {
      return 30;
   } else {
      return 0;
   }
}

unsigned calculerPremierJour(unsigned jour, unsigned mois,unsigned annee) {
   unsigned int premierJour;
   unsigned int k;
   unsigned int j;

   if (mois == 1)
   {
      mois = 13;
      annee--;
   }
   if (mois == 2)
   {
      mois = 14;
      annee--;
   }
   k = annee % 100;
   j = annee / 100;

   //congruance de zeller
   // 0 = Samedi 1 = Dimanche 2 = Lundi ... 7 = Vendredi
   premierJour = jour + 13*(mois+1)/5 + k + k/4 + j/4 + 5*j;
   premierJour = premierJour % 7;
   cout << premierJour << endl;
   //1 = Lundi 2 = Mardi ... 7 = Dimanche
   premierJour = ((premierJour + 5) % 7) + 1;
   return premierJour;
}

string moisLitteral(unsigned mois) {
   switch (mois){
      case 1:
         return "Janvier";
      case 2:
         return "Fevrier";
      case 3:
         return "Mars";
      case 4:
         return "Avril";
      case 5:
         return "Mai";
      case 6:
         return "Juin";
      case 7:
         return "Juillet";
      case 8:
         return "Aout";
      case 9:
         return "Septembre";
      case 10:
         return "Octobre";
      case 11 :
         return "Novembre";
      case 12:
         return "Decembre";
      default:
         return "ERROR";
   }
}