#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Trajectoire.h"


struct Queue* createEmptyQueue(){
    struct Queue* q = malloc(sizeof(struct Queue));
    if(q != NULL){
        q->l = createEmptyList();
    }
    return q;

}


void enqueue(struct Queue* q, int item, bool* valid){
    *valid = true;
    addFirst(q->l, item);
}


int dequeue(struct Queue* q, bool* valid){
    int tempo = head(q,valid);
    deleteItemPos(q->l,listSize(q->l)-1,valid);
    return tempo;

}


void printQueue(struct Queue* q){
    if(isQueueEmpty(q)){
        printf("rear –> NULL <– front\n");
    }
    else{
        bool valid;
        for(int i = 0;i<queueSize(q);i++){
            if(i == 0){
                printf("rear -> %d",getItemPos(q->l,i,&valid));
            }
            else{
                printf(" - %d",getItemPos(q->l,i,&valid));
            }
        }
        printf(" <– front\n");
    }
}


void deleteQueue(struct Queue** q){
    deleteList(&((*q)->l));
    free(*q);
    *q = NULL;