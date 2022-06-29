#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Trajectoire.h"

//-----------------------------------------------Opérations de création de la list--------------------------------------
struct List* createEmptyList(){
    struct List* l = malloc(sizeof(struct List));
    if(l != NULL){
        l->size = 0;
        l->head = NULL;
        l->tail = NULL;
    }
    return l;
}

bool isListEmpty(struct List* l){
    if(l->size == 0){
        return true;
    }
    return false;
}

void deleteFirst(struct List* l){
    if(!isListEmpty(l)){
        struct Point* newHead;
        newHead = l->head->next;
        deletePoint(&l->head);
        l->head = newHead;
        l->size--;
    }
}

unsigned int listSize(struct List* l){
    return l->size;
}

void deleteList(struct List** l){
    struct List* ll = *l;
    for(unsigned int iter = 0; iter< listSize(ll); iter++){
        deleteFirst(ll);
    }
    free(ll);
    *l = NULL;
}


//-----------------------------------------------Opérations de création de la Queue--------------------------------------

struct Queue* createEmptyQueue(){
    struct Queue* q = malloc(sizeof(struct Queue));
    if(q != NULL){
        q->l = createEmptyList();
    }
    return q;

}


void enqueue(struct Queue* q, struct Vector* r, struct Vector* v, unsigned int time, bool* valid){
    *valid = true;
    struct Point* newTail = createPoint(r, v, time);
    if(isQueueEmpty(q)){
        q->l->head=q->l->tail=newTail;
    }
    else{
        q->l->tail->next= newTail;
        q->l->tail = newTail;
    }
    q->l->size++;

}

unsigned int queueSize(struct Queue* q){
    return q->l->size;
}


bool isQueueEmpty(struct Queue* q){
    return (queueSize(q) == 0);
}


void deleteQueue(struct Queue** q){
    deleteList(&((*q)->l));
    free(*q);
    *q = NULL;
}

//-------------------------fonction de création, affichage et calcul pour la trajectoire--------------------------------


void init(struct Queue* pathway,double eccentricity,double semiMajorAxis){// création du premier point de la trajectoire grâce aux formule du périhélie
    bool valid;
    struct Vector* firstPosition = createNewVector(semiMajorAxis*(1-eccentricity),0,0); // position du premier point ou position au périhélie
    struct Vector* firstSpeed = createNewVector(0,sqrt((G*Msoleil*(1+eccentricity))/(semiMajorAxis*(1-eccentricity))),0); // vitesse du premier point ou vitesse au périhélie
    enqueue(pathway,firstPosition,firstSpeed,0,&valid);
    //deleteVector(&firstPosition);
    //deleteVector(&firstSpeed);

}

struct Queue*  createPathwayWithEuler(char* name, FILE* file, double eccentricity, double semiMajorAxis){ // création du reste des points de la trajectoire grâce aux formule de la méthode d'Euler et affichage de la trajectoire dans le fichier ciblé (planet.json)
    bool valid;
    struct Queue* pathway = createEmptyQueue(); // création d'une trajectoire vide
    init(pathway,eccentricity,semiMajorAxis); // initialisation du premier point
    printf("Combien de points sont à tracer ? "); // partie initialisation menu
    unsigned int limitTime;// nombre de points voulu
    scanf("%d",&limitTime);
    printf("\n");
    for(unsigned int time = 0; time < limitTime;time++) { // boucle pour calculer et afficher tous les points voulu
        if(time == 0){
            fprintf(file,"\"%s-euler\" : [\n",name);
            fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d],\n", pathway->l->tail->r->x, pathway->l->tail->r->y,pathway->l->tail->r->z, pathway->l->tail->v->x, pathway->l->tail->v->y, pathway->l->tail->v->z,pathway->l->tail->time); // affichage du premier point déja initialisé dans le fichier cible (planet.json)
            time++;
        }
        struct Vector *nextPosition = additionVector(pathway->l->tail->r,multiplyVectorByScalar(pathway->l->tail->v, deltaTime)); // création du vecteur position du point suivant avec la méthode de calcul d'Euler
        struct Vector *nextSpeed = createNewVector(pathway->l->tail->v->x -((G * Msoleil / pow(normVector(pathway->l->tail->r), 3)) *deltaTime * pathway->l->tail->r->x), pathway->l->tail->v->y -((G * Msoleil / pow(normVector(pathway->l->tail->r), 3)) *deltaTime *pathway->l->tail->r->y), 0); // création du vecteur vitesse du point suivant avec la méthode de calcul d'Euler
        enqueue(pathway, nextPosition, nextSpeed, time, &valid); // création du point suivant de la trajectoire
        //deleteVector(&nextPosition);
        //deleteVector(&nextSpeed);
        fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d]", pathway->l->tail->r->x, pathway->l->tail->r->y,pathway->l->tail->r->z, pathway->l->tail->v->x, pathway->l->tail->v->y, pathway->l->tail->v->z,pathway->l->tail->time); // affichage du point qui vient d'être crée
        if (time != (limitTime-1)) {
            fprintf(file, ",\n");
        }
    }
    fprintf(file,"]\n");
    return pathway;
}

struct Queue* createPathwayWithEulerAsymmetric(char* name, FILE* file, double eccentricity, double semiMajorAxis){// création du reste des points de la trajectoire grâce aux formule de la méthode d'Euler Asymétrique et affichage de la trajectoire dans le fichier ciblé (planet.json)
    bool valid;
    struct Queue* pathway = createEmptyQueue(); // création d'une trajectoire vide
    init(pathway,eccentricity,semiMajorAxis); // initialisation du premier point
    printf("Combien de points sont à tracer ? "); // partie initialisation menu
    unsigned int limitTime;// nombre de points voulu
    scanf("%d",&limitTime);
    printf("\n");
    for(unsigned int time = 0; time < limitTime;time++) { // boucle pour calculer et afficher tous les points voulu
        if(time == 0){
            fprintf(file,"\"%s-euler_asymmetric\" : [\n",name);
            fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d],\n", pathway->l->tail->r->x, pathway->l->tail->r->y,pathway->l->tail->r->z, pathway->l->tail->v->x, pathway->l->tail->v->y, pathway->l->tail->v->z,pathway->l->tail->time);// affichage du premier point déja initialisé dans le fichier cible (planet.json)
            time++;
        }
        struct Vector *nextPosition = additionVector(pathway->l->tail->r,multiplyVectorByScalar(pathway->l->tail->v, deltaTime)); // création du vecteur position du point suivant avec la méthode de calcul d'Euler Asymétrique
        struct Vector *nextSpeed = createNewVector(pathway->l->tail->v->x -((G * Msoleil / pow(normVector(nextPosition), 3)) *deltaTime * nextPosition->x), pathway->l->tail->v->y -((G * Msoleil / pow(normVector(nextPosition), 3)) *deltaTime *nextPosition->y), 0);// création du vecteur vitesse du point suivant avec la méthode de calcul d'Euler Asymétrique
        enqueue(pathway, nextPosition, nextSpeed, time, &valid);// création du point suivant de la trajectoire
        //deleteVector(&nextPosition);
        //deleteVector(&nextSpeed);
        fprintf(file, "[[%e, %e, %e],[%e, %e, %e], %d]", pathway->l->tail->r->x, pathway->l->tail->r->y,pathway->l->tail->r->z, pathway->l->tail->v->x, pathway->l->tail->v->y, pathway->l->tail->v->z,pathway->l->tail->time); // affichage du point qui vient d'être crée
        if (time != (limitTime-1)) {
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

void energyConservation(struct Queue* pathway, double mass){
    struct Point* iter = pathway->l->head;
    double Ep = ((G*Msoleil*mass)/pow(normVector(iter->r),2)); // calcul de l'energie potentielle du premier point avec les formules données
    double Ec = (mass/(2*pow(normVector(iter->v),2))); // calcul de l'energie cinétique du premier point avec les formules données
    double E = Ep+Ec; //calcul de l'energie Mécanique du premier point avec les formules données
    double sum = 0;
    iter = iter->next;
    for(unsigned int point = 1;point<queueSize(pathway);point++){
        Ep = ((G*Msoleil*mass)/pow(normVector(iter->r),2));
        Ec = (mass/(2*pow(normVector(iter->v),2)));
        sum= sum + ((Ep+Ec)/E); // somme de Et+1/E, donc la somme de l'énergie mécanique d'un point sur l'énergie mécanique du point précédent
        E = Ep+Ec;
        iter = iter->next;
    }
    printf("Il y a conservation d'énergie si le résultat est aux environs de 1 (10.00000e-01 ici): %e\n",sum/queueSize(pathway)); // (sum(Et+1/E))/n avec n points, donc la somme de l'énergie mécanique d'un point sur l'énergie mécanique du point précédent le tout divisé par le nombre de points
}
