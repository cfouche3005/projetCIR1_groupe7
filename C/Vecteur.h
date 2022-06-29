#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#ifndef PROJETCIR1_GROUPE7_VECTEUR_H
#define PROJETCIR1_GROUPE7_VECTEUR_H

struct Vector
{
    double x;
    double y;
    double z;
};

// Opérations de création
struct Vector* createNewVector(double x,double y,double z); // creer un nouveau vecteur
void printVector(struct Vector* v); // afficher un vecteur donné
void deleteVector(struct Vector** v); // supprimer un vecteur donné

// Opérations mathématiques sur des vecteurs
struct Vector* additionVector(struct Vector* v1, struct Vector* v2); // Calcul du resultat de l'addition entre 2 vecteurs
struct Vector* subtractionVector(struct Vector* v1, struct Vector* v2); // Calcul du resultat de la soustraction entre 2 vecteurs
struct Vector* multiplyVectorByScalar(struct Vector* v1, int s); // Calcul du resultat de la multiplication entre un vecteur et un scalaire
double normVector(struct Vector* v); //  Calcul la norme d'un vecteur donné

// Tests des fonctions opérations mathématiques sur des vecteurs
void vectorTest();

#endif //PROJETCIR1_GROUPE7_VECTEUR_H
