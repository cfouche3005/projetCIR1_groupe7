#include <stdlib.h>
#include <stdio.h>
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

struct Vector* subtractionVector(struct Vector* v1, struct Vector* v2){
    struct Vector* v = createNewVector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
    return v;
}

struct Vector* multiplyVectorByScalar(struct Vector* v1, int s){
    struct Vector* v = createNewVector((v1->x)*s, (v1->y)*s, (v1->z)*s);
    return v;
}

double normVector(struct Vector* v){
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
    printVector(v1); //test de createNewVector()
    printVector(v2); //test de printVector()
    printVector(v3); //test de additionVector()
    printVector(subtractionVector(v1,v2)); //test de subtractionVector()
    printVector(multiplyVectorByScalar(v1,5)); //test de multiplyVectorByScalar()
    printf("%e", normVector(v1)); //test de normVector()
    deleteVector(&v1);
    deleteVector(&v2);
    deleteVector(&v3);
    // Pour effectuer le test de la fonction deleteVector() , executer: "valgrind --tool=memcheck --leak-check=full <nom_programme>"
    // Tous les vecteurs utilisé dans ces tests seront effacées avec cette fonction!
}