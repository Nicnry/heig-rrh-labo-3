/*
-----------------------------------------------------------------------------------
Nom du fichier : calculsDeDate.h
Auteur(s)      : Alexandre Junod, Jarod Streckeisen, Nicolas Henry
Date creation  : 10.11.2020
Description    : Définition de prototypes
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef CALCULESDEDATE_H
#define CALCULESDEDATE_H

#include <string>

using namespace std;

/**
 * Calcule si l'année est bissextile
 * @param annee L'année pour la quelle le code va calculer si c'est une année
 * bissextile
 * @return Une valeur booléenne, afin de savoir si l'année est bissextile
 */
bool calculerBissextile(unsigned annee);

/**
 * Calcule le nombre de jours dans un mois
 * @param mois Le mois pour lequel le code va calculer le nombre de jours
 * @param estBissextile Indique si l'année est bissextile
 * @return
 */
unsigned calculerNbJourMois(unsigned mois, bool estBissextile);

/**
 * Calcule le jour pour la date donnée (lundi à dimanche)
 * @param jour Le jour de la date. Pour l'instant le premier jour est hardcodé,
 * mais celui-ci est disponible pour une future évolutivité
 * @param mois Le mois de la date
 * @param annee L'année de la date
 * @return Retourne le jour date du séléctionnée. 1 = Lundi 2 = Mardi ... 7 =
 * Dimanche
 */
unsigned calculerJourDate(unsigned jour, unsigned mois, unsigned annee);

/**
 * Référence du mois en valeur numérique à sa forme écrite. 1 = Janvier 2 = Févreier
 * ... 12 = Décembre
 * @param mois Le mois pour le quel la forme écrite doit être retournée
 * @return Retourne mois esous forme écrite
 */
string moisLitteral(unsigned mois);

#endif
