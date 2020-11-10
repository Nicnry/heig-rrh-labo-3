/*
-----------------------------------------------------------------------------------
Nom du fichier : calculsDeDate.h
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 10.11.2020
Description : Définition de prototypes
Remarque(s) :
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#ifndef CALCULESDEDATE_H
#define CALCULESDEDATE_H

#include <string>

using namespace std;

bool calculerBissextile(unsigned annee);

unsigned calculerNbJourMois(unsigned mois, bool estBissextile);

unsigned calculerPremierJour(unsigned jour, unsigned mois, unsigned annee);

string moisLitteral(unsigned mois);

#endif
