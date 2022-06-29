#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Planete.h"

int main(){
    FILE* file = NULL;
    file = fopen("planet.json","w"); // ouverture et définition du fichier cible et son style d'ouverture
    if (file != NULL) {
        int planetChoice;
        int first = 0;
        do{
            printf("\nQuelle planète voulez-vous choisir ? (à savoir que l'on ne peux choisir qu'une planète à la fois)\n"); // partie de l'interface menu
            printf("1 -> Mercure\n");
            printf("2 -> Venus\n");
            printf("3 -> Terre\n");
            printf("4 -> Mars\n");
            printf("5 -> Jupiter\n");
            printf("6 -> Saturne\n");
            printf("7 -> Uranus\n");
            printf("8 -> Neptune\n");
            printf("9 -> Planète customisée\n");
            printf("0 -> exit\n");
            printf("Choix: ");
            scanf("%d",&planetChoice);
            switch(planetChoice) {
                case 1 : first = createPlanete("mercury", file, MasseMe, exentriciteMe, demigrandAxeMe,first); // création de la planète concerné (ici Mercure)
                    break;
                case 2 : first = createPlanete("venus", file, MasseV, exentriciteV, demigrandAxeV,first);
                    break;
                case 3 : first = createPlanete("earth",file, MasseT, exentriciteT, demigrandAxeT,first);
                    break;
                case 4 : first = createPlanete("mars",file, MasseMa, exentriciteMa, demigrandAxeMa,first);
                    break;
                case 5 : first = createPlanete("jupiter",file, MasseJ, exentriciteJ, demigrandAxeJ,first);
                    break;
                case 6 : first = createPlanete("saturn",file, MasseS, exentriciteS, demigrandAxeS,first);
                    break;
                case 7 : first = createPlanete("uranus",file, MasseU, exentriciteU, demigrandAxeU,first);
                    break;
                case 8 : first = createPlanete("neptune",file, MasseN, exentriciteN, demigrandAxeN,first);
                    break;
                case 9 :
                    printf("Entrer les informations demandé :\n\n");
                    double MassC;
                    double eccentricityC;
                    double semiMajorAxisC;
                    printf("Masse : ");
                    scanf("%le",&MassC);
                    printf("Exentricité (doit être entre 0 et 1) : ");
                    scanf("%le",&eccentricityC);
                    printf("Demi-grand Axe : ");
                    scanf("%le",&semiMajorAxisC);
                    first = createPlanete("Planète Customisée",file, MassC, eccentricityC, semiMajorAxisC,first); // création de la planète customiséé
                    break;


            }
        }
        while(planetChoice > 0);
        if(first == 1){
            fprintf(file,"}\n");
        }
    }
    fclose(file); // fermeture du fichier cible
    return 0;
}