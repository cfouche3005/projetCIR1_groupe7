#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PROJETCIR1_GROUPE7_VECTEUR_H
#define PROJETCIR1_GROUPE7_VECTEUR_H

struct Vector
{
    double x;
    double y;
    double z;
};

struct Vector* createNewVector(double x,double y,double z);
struct Vector* additionVector(struct Vector* v1, struct Vector* v2);
struct Vector* soustractionVector(struct Vector* v1, struct Vector* v2);
struct Vector* multiplyVectorScalaire(struct Vector* v1, int s);
double normeVector(struct Vector* v);
void vectorTest();
void printVector(struct Vector* v);
void deleteVector(struct Vector** v);

#endif //PROJETCIR1_GROUPE7_VECTEUR_H
