/*
-----------------------------------------------------------------------------------
Nom du fichier : moisLitteral.cpp
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 06.11.2020
Description :
Remarque(s) :
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <string>
#include "moisLitteral.h"

using namespace std;

string moisLitteral(unsigned int mois) {
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