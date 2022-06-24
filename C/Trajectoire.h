#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


#ifndef PROJETCIR1_GROUPE7_TRAJECTOIRE_H
#define PROJETCIR1_GROUPE7_TRAJECTOIRE_H

struct Queue
{
    struct List *l;
};

struct Queue* createEmptyQueue();
void enqueue(struct Queue* q, int item, bool* valid);
int dequeue(struct Queue* q, bool* valid);
void printQueue(struct Queue* q);
void deleteQueue(struct Queue** q);


#endif //PROJETCIR1_GROUPE7_TRAJECTOIRE_H
