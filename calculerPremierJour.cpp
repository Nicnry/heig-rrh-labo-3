/*
-----------------------------------------------------------------------------------
Nom du fichier : calculerPremierJour.cpp
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 08.11.2020
Description :
Remarque(s) :
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "calculerPremierJour.h"

int calculerPremierJour(int mois,int annee) {
	int premierJour;
	//congruance de zeller
	// 0 = Samedi 1 = Dimanche 2 = Lundi ... 7 = Vendredi
	premierJour =
		(1 + (13 * (mois + 1) / 5) + annee % 100 + annee % 100 / 4 + annee / 100 /
																						 4 -
		 2 * (annee / 100)) % 7;
	//1 = Lundi 2 = Mardi ... 7 = Dimanche
	premierJour = (premierJour + 6 - 1) % 7 + 1;
	return premierJour;
}