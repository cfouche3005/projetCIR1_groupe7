#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Vecteur.h"

#ifndef PROJETCIR1_GROUPE7_POINT_H
#define PROJETCIR1_GROUPE7_POINT_H

struct Point
{
    struct Vector* r; // vecteur position
    struct Vector* v; // vecteur vitesse
    unsigned int time;
    struct Point* next;

};


// Opérations de création
struct Point* createPoint(struct Vector* r, struct Vector* v, unsigned int time); // creer un point
void deletePoint(struct Point** head); // supprimer un point donné

#endif //PROJETCIR1_GROUPE7_POINT_H
