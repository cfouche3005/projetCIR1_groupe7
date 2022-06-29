#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Point.h"

struct Point* createPoint(struct Vector* r, struct Vector* v, unsigned int time){
    struct Point* head = malloc(sizeof(struct Point));
    if(head != NULL){
        head->r = r;
        head->v = v;
        head->time = time;
        head->next = NULL;
    }
    return head;
}

void deletePoint(struct Point** head){
    deleteVector(&(*head)->r);
    deleteVector(&(*head)->v);
    free(*head);
    *head = NULL;
}
