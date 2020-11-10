/*
-----------------------------------------------------------------------------------
Nom du fichier : affichageConsole.h
Auteur(s)      : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation  : 10.11.2020
Description    : Définition de prototypes
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef AFFICHAGECONSOLE_H
#define AFFICHAGECONSOLE_H

/**
 * Affiche le calendrier dans la console, en tout premier lieu le mois et l'année
 * sont affichés côte à côte, puis les différents jours de la semaine (lundi à
 * dimanche) suivi par les jours du mois, ainsi de suite pour les mois suivants
 * @param moisDebut Le premier mois à afficher
 * @param anneeDebut L'année du premier mois à afficher
 * @param nbMois Nombre de mois à afficher après la première date saisie
 */
void afficherCalendrier(unsigned moisDebut,unsigned anneeDebut,unsigned nbMois);

#endif
