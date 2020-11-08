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

#include <iostream>
#include "calculerPremierJour.h"

using namespace std;

int calculerPremierJour(unsigned int jour, unsigned int mois,unsigned int annee) {
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