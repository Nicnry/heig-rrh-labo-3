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
using namespace std;

int main() {
	unsigned int firstMonth, firstYear, lastMonth, lastYear;
	bool saisieOK2;
	do {
		cout << "Entrez la date de debut [mm aaaa] : ";
		cin >> firstMonth >> firstYear;
		if (firstMonth <= 0) {
			cin.clear(),
				cout << "Saisie incorrecte" << endl;
		}
		saisieOK2 = false;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (saisieOK2);
	/*
	cout << "Entrez la date de debut [mm aaaa] : ";
	cin >> firstMonth >> firstYear;
	cout << "Entrez la date de fin [mm aaaa] : ";
	cin >>  lastMonth >> lastYear;

	cout << firstMonth << " " << firstYear;
	cout << lastMonth << " " << lastYear;
	*/
	return EXIT_SUCCESS;
}