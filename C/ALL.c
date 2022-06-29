
#include "ALL.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


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


//-------------------------------------------------------------------------------------


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

struct Point* addFirst(struct Point* head, struct Vector* r, struct Vector* v, unsigned int time){
    struct Point* newhead = createPoint(r,v,time);
    newhead->next = head;
    return newhead;
}

struct Point* deleteFirst(struct Point* head){
    struct Point* newhead = head->next;
    free(head);
    return newhead;

}


//-----------------------------------------------------------------------------------------


struct Queue* createEmptyQueue(){
    struct Queue* q = malloc(sizeof(struct Queue));
    if(q != NULL){
        q->size = 0;
        q->head = NULL;
        q->tail = NULL;
    }
    return q;

}


void enqueue(struct Queue* q, struct Vector* r, struct Vector* v, unsigned int time, bool* valid){
    *valid = true;
    struct Point* newTail = createPoint(r, v, time);
    if(isQueueEmpty(q)){
        q->head=q->tail=newTail;
    }
    else{
        q->tail->next= newTail;
        q->tail = newTail;
    }
    q->size++;

}

int dequeue(struct Queue* q, bool* valid){
    struct Queue* res;
    res->head->r = q->head->r;
    deleteFirst(q->head);


}

unsigned int queueSize(struct Queue* q){
    return q->size;
}


bool isQueueEmpty(struct Queue* q){
    return (queueSize(q) == 0);
}


void deleteQueue(struct Queue** q){
    free(*q);
    *q = NULL;
}


void init(struct Queue* pathway,double exentricite,double demigrandAxe){
    bool valid;
    struct Vector* position = createNewVector(demigrandAxe*(1-exentricite),0,0);
    struct Vector* vitesse = createNewVector(0,sqrt((G*Msoleil*(1+exentricite))/(demigrandAxe*(1-exentricite))),0);
    enqueue(pathway,position,vitesse,0,&valid);

}

struct Queue*  createPathwayWithEuler(char* nom, FILE* file, double exentricite, double demigrandAxe){
    bool valid;
    struct Queue* pathway = createEmptyQueue();
    init(pathway,exentricite,demigrandAxe);
    printf("Combien de points sont à tracer ? ");
    unsigned int limitTime;
    scanf("%d",&limitTime);
    printf("\n");
    for(unsigned int time = 0; time <= limitTime;time++) {
        if(time == 0){
            fprintf(file,"\"%s-euler\" : [\n",nom);
            fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d],\n", pathway->tail->r->x, pathway->tail->r->y,pathway->tail->r->z, pathway->tail->v->x, pathway->tail->v->y, pathway->tail->v->z,pathway->tail->time);
            time++;
        }
        struct Vector *nextPosition = additionVector(pathway->tail->r,multiplyVectorScalaire(pathway->tail->v, deltaTime));
        struct Vector *nextVitesse = createNewVector(pathway->tail->v->x -((G * Msoleil / pow(normeVector(pathway->tail->r), 3)) *deltaTime * pathway->tail->r->x), pathway->tail->v->y -((G * Msoleil / pow(normeVector(pathway->tail->r), 3)) *deltaTime *pathway->tail->r->y), 0);
        enqueue(pathway, nextPosition, nextVitesse, time, &valid);
        fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d]", pathway->tail->r->x, pathway->tail->r->y,pathway->tail->r->z, pathway->tail->v->x, pathway->tail->v->y, pathway->tail->v->z,pathway->tail->time);
        if (time != limitTime) {
            fprintf(file, ",\n");
        }
    }
    fprintf(file,"]\n");
    return pathway;
}

struct Queue* createPathwayWithEulerAsymmetric(char* nom, FILE* file, double exentricite, double demigrandAxe){
    bool valid;
    struct Queue* pathway = createEmptyQueue();
    init(pathway,exentricite,demigrandAxe);
    printf("Combien de points sont à tracer ? ");
    unsigned int limitTime;
    scanf("%d",&limitTime);
    printf("\n");
    for(unsigned int time = 0; time <= limitTime;time++) {
        if(time == 0){
            fprintf(file,"\"%s-euler_asymmetric\" : [\n",nom);
            fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d],\n", pathway->tail->r->x, pathway->tail->r->y,pathway->tail->r->z, pathway->tail->v->x, pathway->tail->v->y, pathway->tail->v->z,pathway->tail->time);
            time++;
        }
        struct Vector *nextPosition = additionVector(pathway->tail->r,multiplyVectorScalaire(pathway->tail->v, deltaTime));
        struct Vector *nextVitesse = createNewVector(pathway->tail->v->x -((G * Msoleil / pow(normeVector(nextPosition), 3)) *deltaTime * nextPosition->x), pathway->tail->v->y -((G * Msoleil / pow(normeVector(nextPosition), 3)) *deltaTime *nextPosition->y), 0);
        enqueue(pathway, nextPosition, nextVitesse, time, &valid);
        fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d]", pathway->tail->r->x, pathway->tail->r->y,pathway->tail->r->z, pathway->tail->v->x, pathway->tail->v->y, pathway->tail->v->z,pathway->tail->time);
        if (time != limitTime) {
            fprintf(file, ",\n");
        }
    }
    fprintf(file,"]\n");
    return pathway;
}



/*
void printPathway(struct Queue* pathway, char* name, FILE* file,char* method){
    struct Point* iter = pathway->head;
    fprintf(file,"\"%s-%s\" : [\n",name,method);
    for(unsigned int time = 0;time<=queueSize(pathway);time++){
        fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d]", iter->r->x, iter->r->y,iter->r->z, iter->v->x, iter->v->y, iter->v->z,iter->time);
        if(time != queueSize(pathway)) {
            fprintf(file, ",\n");
        }
        iter = iter->next;
    }
    fprintf(file,"]\n");

}
 */

void energyConservation(struct Queue* pathway, double masse){
    struct Point* iter = pathway->head;
    double Ep = ((G*Msoleil*masse)/pow(normeVector(iter->r),2));
    double Ec = (masse/(2*pow(normeVector(iter->v),2)));
    double E = Ep+Ec;
    double res = 0;
    iter = iter->next;
    for(unsigned int point = 1;point<queueSize(pathway);point++){
         Ep = ((G*Msoleil*masse)/pow(normeVector(iter->r),2));
         Ec = (masse/(2*pow(normeVector(iter->v),2)));
         res= res + ((Ep+Ec)/E);
         E = Ep+Ec;
         iter = iter->next;
    }
    printf("Il y a conservation d'énergie si le résultat est aux environs de 1 (10.00000e-01 ici): %e\n",res/queueSize(pathway));
}

//----------------------------------------------------------------------------------------------------------------------


int createPlanete(char* nom, FILE* file, double masse, double exentricite, double demigrandAxe, int first){
    printf("\nAvec quelle méthode ?\n");
    printf("1 -> Euler\n");
    printf("2 -> Euler Asymétrique\n");
    printf("3 -> Les deux\n");
    printf("Choix: ");
    int methodChoice;
    scanf("%d",&methodChoice);
    if((methodChoice >= 1) && (methodChoice <= 3)){
        if(first == 0){
            fprintf(file,"{");
        }
        if(first == 1){
            fprintf(file,",\n");
        }
        first = 1;
        printf("\n Afficher la conservation d'énergie ?\n");
        printf("1 -> Oui\n");
        printf("Autre nombre -> Non\n");
        printf("Choix: ");
        int energyChoice;
        scanf("%d",&energyChoice);
        if(methodChoice == 1){
            struct Queue* fullPathwayEuler = createPathwayWithEuler(nom,file,exentricite, demigrandAxe);
            if(energyChoice == 1){
                printf("Test de la conservation d'énergie avec la méthode d'Euler;\n");
                energyConservation(fullPathwayEuler, masse);
            }

        }
        if(methodChoice == 2){
            struct Queue* fullPathwayEulerAsymmetric = createPathwayWithEulerAsymmetric(nom,file,exentricite, demigrandAxe);
            if(energyChoice == 1){
                printf("Test de la conservation d'énergie avec la méthode d'Euler Asymétrique;\n");
                energyConservation(fullPathwayEulerAsymmetric, masse);
            }
        }
        if(methodChoice == 3){
            struct Queue* fullPathwayEuler = createPathwayWithEuler(nom,file,exentricite, demigrandAxe);
            if(energyChoice == 1){
                printf("Test de la conservation d'énergie avec la méthode d'Euler;\n");
                energyConservation(fullPathwayEuler, masse);
            }
            printf("\n");
            fprintf(file,",\n");
            struct Queue* fullPathwayEulerAsymmetric = createPathwayWithEulerAsymmetric(nom,file,exentricite, demigrandAxe);
            if(energyChoice == 1){
                printf("Test de la conservation d'énergie avec la méthode d'Euler Asymétrique;\n");
                energyConservation(fullPathwayEulerAsymmetric, masse);
            }
        }
    }
    else{
        printf("Mauvaise réponse...\n");
    }
    return first;
    //printPathway(fullPathwayEulerAsymmetric, nom, file,"euler_asymmetric");


}
