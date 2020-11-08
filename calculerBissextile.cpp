/*
-----------------------------------------------------------------------------------
Nom du fichier : calculerBissextile.cpp
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 08.11.2020
Description :
Remarque(s) :
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "calculerBissextile.h"

bool calculerBissextile(int annee) {
	return annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0;
}