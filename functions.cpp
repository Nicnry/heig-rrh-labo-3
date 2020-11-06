/*
-----------------------------------------------------------------------------------
Nom du fichier : functions.cpp
Auteur(s) : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation : 05.11.2020
Description :
Remarque(s) :
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void saisieDate(unsigned int& mois, unsigned int& annee,  string message) {
	bool estValide = false;
	do {
		cout << message;
		cin >> mois >> annee;
		if (mois <=12 && mois >= 1 && annee >= 1900 && annee <= 2100){
		   estValide = true;
		}else{
         cin.clear(), cout << "Date non valide. Veuillez SVP recommencer." << endl;
      }
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!estValide);
}