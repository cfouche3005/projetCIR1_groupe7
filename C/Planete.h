#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Trajectoire.h"

// Constante pour chaque planète de système solaire à réutiliser dans le code
//Mercure
#define MasseMe 3.301e+23 // Masse de la planète
#define exentriciteMe 0.20563069 // Exentricité de l'orbite de la planète
#define demigrandAxeMe 57909050000 // Demi-grand Axe de l'orbite de la planète

//Vénus
#define MasseV 4.867e+24
#define exentriciteV 0.00677323
#define demigrandAxeV 108209500000

//Terre
#define MasseT 5.972e+24
#define exentriciteT 0.01671022
#define demigrandAxeT 149.6e+9


//Mars
#define MasseMa 6.441e+23
#define exentriciteMa 0.09341233
#define demigrandAxeMa 227944000000

//Jupiter
#define MasseJ 1898.19e+24
#define exentriciteJ 0.04839266
#define demigrandAxeJ 778340000000

//Saturne
#define MasseS 568.34e+24
#define exentriciteS 0.05415060
#define demigrandAxeS 1427000000000

//Uranus
#define MasseU 86.813e+24
#define exentriciteU 0.04716771
#define demigrandAxeU 2871000000000

//Neptune
#define MasseN 102.413e+24
#define exentriciteN 0.00858587
#define demigrandAxeN 4500000000000

#ifndef PROJETCIR1_GROUPE7_PLANÈTE_H
#define PROJETCIR1_GROUPE7_PLANÈTE_H

struct Planet
{
    char* name;
    struct Queue* pathway;

};

// Opérations de création
int createPlanete(char* name, FILE* file, double mass, double eccentricity, double semiMajorAxis, int first);// creer une planète

#endif //PROJETCIR1_GROUPE7_PLANÈTE_H
