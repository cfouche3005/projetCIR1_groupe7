#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Vecteur.h"


struct Vector* createNewVector(double x,double y,double z){
    struct Vector* v = malloc(sizeof(struct Vector));
    if(v != NULL){
        v->x = x;
        v->y = y;
        v->z = z;
    }
    return v;
}

struct Vector* additionVector(struct Vector* v1, struct Vector* v2){
    struct Vector* v = createNewVector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
    return v;
}

struct Vector* soustractionVector(struct Vector* v1, struct Vector* v2){
    struct Vector* v = createNewVector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
    return v;
}

struct Vector* multiplyVectorScalaire(struct Vector* v1, int s){
    struct Vector* v = createNewVector((v1->x)*s, (v1->y)*s, (v1->z)*s);
    return v;
}

double normeVector(struct Vector* v){
    return sqrt(pow(v->x,2)+pow(v->y,2)+pow(v->z,2));
}

void printVector(struct Vector* v){
    printf("v = ( %e , %e , %e )\n ",v->x,v->y,v->z);
}

void deleteVector(struct Vector** v){
    free(*v);
    *v = NULL;
}

void vectorTest(){
    struct Vector* v1 = createNewVector(2,1,3);
    struct Vector* v2 = createNewVector(3,2,1);
    struct Vector* v3 = additionVector(v1,v2);
    printVector(v1);
    printVector(v2);
    printVector(v3);
    printVector(soustractionVector(v1,v2));
    printVector(multiplyVectorScalaire(v1,5));
    printf("%e", normeVector(v1));
    deleteVector(&v1);
    deleteVector(&v2);
    deleteVector(&v3);

}