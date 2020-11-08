/*
-----------------------------------------------------------------------------------
Nom du fichier : calculerNbJourMois.cpp
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 08.11.2020
Description :
Remarque(s) :
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "calculerNbJourMois.h"

int calculerNbJourMois(unsigned int mois, bool estBissextile) {
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