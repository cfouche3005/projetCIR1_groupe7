#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Point.h"

struct Point* createPoint(struct Vector* r,struct Vector* v,int time ){
    struct Point* p = malloc(sizeof(struct Point));
    if(p != NULL){
        p->r = r;
        p->v = v;
        p->time = time;
        p->next = NULL;
    }
    return p;
}