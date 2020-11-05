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
	unsigned int firstMonth, firstYear, lastMonth, lastYear;

	bool test;
	do {
		verificationDate(firstMonth, firstYear,
						 "1Entrez la date de debut [mm aaaa] : ");
		verificationDate(lastMonth, lastYear,
						 "2Entrez la date de fin [mm aaaa] : ");

		if (firstYear > lastYear || (firstMonth > lastMonth && firstYear > lastYear)) {
			test = true;
			cout << "Donnée incorrect" << endl;
		} else {
			test = false;
		}
	} while (test);

	cout << firstMonth << " " << firstYear << endl;
	cout << lastMonth << " " << lastYear;

	return EXIT_SUCCESS;
}