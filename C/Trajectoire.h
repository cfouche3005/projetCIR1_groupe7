#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Point.h"

// Constante à réutiliser dans le code
#define G 6.67430e-11 // constante gravitationelle G
#define Msoleil 1.9884e+30 // Masse soleil
#define deltaTime 8640 // ∆t


#ifndef PROJETCIR1_GROUPE7_TRAJECTOIRE_H
#define PROJETCIR1_GROUPE7_TRAJECTOIRE_H


struct List{
    unsigned int size;
    struct Point* head;
    struct Point* tail;
};

struct Queue{
    struct List* l;
};

// Opérations de création de la list
struct List* createEmptyList();
bool isListEmpty(struct List* l);
void deleteFirst(struct List* l);
unsigned int listSize(struct List* l);
void deleteList(struct List** l);


// Opérations de création de la Queue
struct Queue* createEmptyQueue();
void enqueue(struct Queue* q, struct Vector* r, struct Vector* v, unsigned int time, bool* valid);
unsigned int queueSize(struct Queue* q);
bool isQueueEmpty(struct Queue* q);
void deleteQueue(struct Queue** q);

void init(struct Queue* pathway, double eccentricity, double semiMajorAxis); // fonction qui initialise le premier point de la trajectoire
struct Queue*  createPathwayWithEuler(char* name, FILE* file, double eccentricity, double semiMajorAxis); // fonction qui crée la trajectoire avec la méthode d'Euler et l'affiche dans le fichier cible (ici planet.json)
struct Queue*  createPathwayWithEulerAsymmetric(char* name, FILE* file, double eccentricity, double semiMajorAxis); // fonction qui crée la trajectoire avec la méthode d'Euler Asymetrique et l'affiche dans le fichier cible (ici planet.json)
void printPathway(struct Queue* pathway, char* name, FILE* file, char* method);
void energyConservation(struct Queue* pathway, double mass); // fonction qui calcul la conservation d'energie


#endif //PROJETCIR1_GROUPE7_TRAJECTOIRE_H
