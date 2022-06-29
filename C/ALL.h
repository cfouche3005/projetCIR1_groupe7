#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define G 6.67430e-11
#define Msoleil 1.9884e+30
#define deltaTime 8640


//Mercure
#define MasseMe 3.301e+23
#define PerihelieMe 46001009
#define exentriciteMe 0.20563069
#define demigrandAxeMe 57909050000

//Vénus
#define MasseV 4.867e+24
#define PerihelieV 107476170
#define exentriciteV 0.00677323
#define demigrandAxeV 108209500000

//Terre
#define MasseT 5.972e+24
#define PerihelieT 147098291
#define exentriciteT 0.01671022
#define demigrandAxeT 149.6e+9


//Mars
#define MasseMa 6.441e+23
#define PerihelieMa 206655215
#define exentriciteMa 0.09341233
#define demigrandAxeMa 227944000000

//Jupiter
#define MasseJ 1898.19e+24
#define PerihelieJ 740679835
#define exentriciteJ 0.04839266
#define demigrandAxeJ 778340000000

//Saturne
#define MasseS 568.34e+24
#define PerihelieS 1349823615
#define exentriciteS 0.05415060
#define demigrandAxeS 1427000000000

//Uranus
#define MasseU 86.813e+24
#define PerihelieU 2734998229
#define exentriciteU 0.04716771
#define demigrandAxeU 2871000000000

//Neptune
#define MasseN 102.413e+24
#define PerihelieN 4459753056
#define exentriciteN 0.00858587
#define demigrandAxeN 4500000000000



#ifndef PROJETCIR1_GROUPE7_ALL_H
#define PROJETCIR1_GROUPE7_ALL_H



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

//----------------------------------------------------------------------------------------------------------------------

struct Point
{
    struct Vector* r;
    struct Vector* v;
    unsigned int time;
    struct Point* next;

};



// Opérations de création


struct Point* createPoint(struct Vector* r, struct Vector* v, unsigned int time);
struct Point* addFirst(struct Point* head, struct Vector* r, struct Vector* v, unsigned int time);
struct Point* deleteFirst(struct Point* head);

//----------------------------------------------------------------------------------------------------------------------


struct Queue
{
    unsigned int size;
    struct Point* head;
    struct Point* tail;

};

struct Queue* createEmptyQueue();

void deleteFirstQueue(struct Queue* q);
void deleteItemPosQueue(struct Queue* q, unsigned int position, bool* valid);
void deleteList(struct Queue** q);


void enqueue(struct Queue* q, struct Vector* r, struct Vector* v, unsigned int time, bool* valid);
int head(struct Queue* q, bool* valid);
int dequeue(struct Queue* q, bool* valid);
unsigned int queueSize(struct Queue* q);
bool isQueueEmpty(struct Queue* q);
void printQueue(struct Queue* q);
void deleteQueue(struct Queue** q);

void init(struct Queue* traj, double exentricite, double demigrandAxe);
struct Queue*  createPathwayWithEuler(char* nom, FILE* file, double exentricite, double demigrandAxe);
struct Queue*  createPathwayWithEulerAsymmetric(char* nom, FILE* file, double exentricite, double demigrandAxe);
void printPathway(struct Queue* pathway, char* name, FILE* file, char* method);
void energyConservation(struct Queue* pathway, double masse);


//---------------------------------------------------------------------------------------------------------------------



struct Planete
{
    char* nom;
    double masse;
    struct Queue* pathway;

};

int createPlanete(char* nom, FILE* file, double masse, double exentricite, double demigrandAxe, int first);


#endif //PROJETCIR1_GROUPE7_ALL_H
