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
#include <string>
#include "saisieDate.h"
#include "affichageConsole.h"

using namespace std;

int main() {
	char rejouer;
	do{

		unsigned moisDebut, anneeDebut, moisFin, anneeFin,nbMois;
		const string MESSAGE_DEBUT = "Entrez la date de debut [mm aaaa] : ";
		const string MESSAGE_FIN = "Entrez la date de fin [mm aaaa] : ";


		bool dateFinPlusGrandQueDebut = false;

		do {
			saisieDate(moisDebut, anneeDebut, MESSAGE_DEBUT);
			saisieDate(moisFin, anneeFin, MESSAGE_FIN);
			if (anneeFin > anneeDebut || anneeFin == anneeDebut && moisFin >= moisDebut) {
				dateFinPlusGrandQueDebut = true;
			} else {
				cin.clear(), cout << "Date non valide. Veuillez SVP recommencer." << endl;
			}
		} while (!dateFinPlusGrandQueDebut);


		// Calcul du nombre de mois total (donc le nombre de calendrier)
		switch (anneeFin - anneeDebut) {
			case 0:
				nbMois = moisFin - moisDebut + 1;
				break;
			case 1:
				nbMois = 12 - moisDebut + moisFin + 1;
				break;
			default:
				nbMois = (12 - moisDebut + 1) + (12 * (anneeFin - anneeDebut - 1)) +
							moisFin;
				break;
		}
      afficherCalendrier(moisDebut,anneeDebut,nbMois);
		cout << "Voulez-vous quitter le programme ? [o/n] :";
		cin >> rejouer;
	} while( rejouer == 'n' );
	cin.ignore(1);


   return EXIT_SUCCESS;
}