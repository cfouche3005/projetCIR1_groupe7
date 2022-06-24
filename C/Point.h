#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PROJETCIR1_GROUPE7_POINT_H
#define PROJETCIR1_GROUPE7_POINT_H

struct Point
{
    struct Vector* r;
    struct Vector* v;
    int time;
    struct Cell* next;

};

struct Point* firstPoint
struct Point* createNewPoint(struct Vector* r,struct Vector* v,int time);
void pointTest();
void printPoint(struct Vector* v);
void deletePoint(struct Vector** v);

#endif //PROJETCIR1_GROUPE7_POINT_H
