#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Planete.h"


int createPlanete(char* name, FILE* file, double mass, double eccentricity, double semiMajorAxis, int first) {
    printf("\nAvec quelle méthode ?\n"); // partie de l'interface menu
    printf("1 -> Euler\n");
    printf("2 -> Euler Asymétrique\n");
    printf("3 -> Les deux\n");
    printf("Choix: ");
    int methodChoice;
    scanf("%d", &methodChoice);
    if ((methodChoice >= 1) && (methodChoice <= 3)) {
        if (first == 0) {
            fprintf(file, "{");
        }
        if (first == 1) {
            fprintf(file, ",\n");
        }
        first = 1;
        printf("\n Afficher la conservation d'énergie ?\n");
        printf("1 -> Oui\n");
        printf("Autre nombre -> Non\n");
        printf("Choix: ");
        int energyChoice;
        scanf("%d", &energyChoice);
        if (methodChoice == 1) {
            struct Queue *fullPathwayEuler = createPathwayWithEuler(name, file, eccentricity, semiMajorAxis); // creation de la trajectoire avec la methode d'Euler
            if (energyChoice == 1) {
                printf("Test de la conservation d'énergie avec la méthode d'Euler;\n");
                energyConservation(fullPathwayEuler, mass); // test de la conservation d'énergie
            }

        }
        if (methodChoice == 2) {
            struct Queue *fullPathwayEulerAsymmetric = createPathwayWithEulerAsymmetric(name, file, eccentricity,semiMajorAxis); // creation de la trajectoire avec la methode d'Euler asymétrique
            if (energyChoice == 1) {
                printf("Test de la conservation d'énergie avec la méthode d'Euler Asymétrique;\n");
                energyConservation(fullPathwayEulerAsymmetric, mass); // test de la conservation d'énergie
            }
        }
        if (methodChoice == 3) {
            struct Queue *fullPathwayEuler = createPathwayWithEuler(name, file, eccentricity, semiMajorAxis); // creation de la trajectoire avec la methode d'Euler
            if (energyChoice == 1) {
                printf("Test de la conservation d'énergie avec la méthode d'Euler;\n");
                energyConservation(fullPathwayEuler, mass); // test de la conservation d'énergie
            }
            printf("\n");
            fprintf(file, ",\n");
            struct Queue *fullPathwayEulerAsymmetric = createPathwayWithEulerAsymmetric(name, file, eccentricity,semiMajorAxis); // creation de la trajectoire avec la methode d'Euler asymétrique
            if (energyChoice == 1) {
                printf("Test de la conservation d'énergie avec la méthode d'Euler Asymétrique;\n");
                energyConservation(fullPathwayEulerAsymmetric, mass); // test de la conservation d'énergie
            }
        }
    }
    else{
        printf("Mauvaise réponse...\n");
    }
    //deleteQueue(fullPathwayEuler);
    //deleteQueue(fullPathwayEulerAsymmetric);
    return first;

}
