/*
-----------------------------------------------------------------------------------
Nom du fichier : saisieUtilisateur.h
Auteur(s)      : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation  : 10.11.2020
Description    : Définition de prototypes
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef SAISIEUTILISATEUR_H
#define SAISIEUTILISATEUR_H

#include <string>

using namespace std;

/**
 * Gére la saisie utilisateur pour respecter le format de la date
 * @param mois Le mois de la date. Celui-ci doit être comprise entre [01..12]
 * @param annee L'année de la date. Celle-ci doit être comprise entre [1900..2100]
 * @param message Message à afficher avant la saisie utilisateur, pour informer ce
 * ce qui est attendu lors de la saisie.
 */
void saisieDate(unsigned& mois, unsigned& annee, const string& message);

#endif
