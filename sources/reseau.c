//
// Created by mathi on 07/11/2024.
//

#include "reseau.h"

#include <stdio.h>

#include "couche.h"

Reseau CreerResNeur(const int nbCouche, int listeNbNeuroneParCouche[]) {
    printf("---- premiere couche \nNombre d'entrées première couche?\n");
    int nbEntrees;
    scanf("%d",&nbEntrees);
    Couche* premier = InitCouche(listeNbNeuroneParCouche[0],nbEntrees);
    premier->next=NULL;
    Couche* tmp = premier;
    for (int i=1; i<nbCouche; i++) {
        printf("---- %deme couche \n",i+1);
        Couche* newCouche = InitCouche(listeNbNeuroneParCouche[i],listeNbNeuroneParCouche[i-1]);
        newCouche->next=NULL;
        tmp->next=newCouche;
    }
    return premier;
}


void PropagationAvant(const Reseau reseau, int listeEntrees[]) {
    Couche* premiere_couche = reseau;
    int listeSortiesNeurones[premiere_couche->nbNeurone];
    OutCouche(premiere_couche,listeEntrees,listeSortiesNeurones);


    /*for (int i=0; i<premiere_couche->nbNeurone; ++i) {
        printf("Sortie première couche neurone %d: %d\n",i+1,listeSortiesNeurones[i]);
    }*/


    Couche* couche=premiere_couche;
    while ((couche->next) != NULL) {
        int listeSortiesNeuronesPrev[couche->nbNeurone];
        for (int i=0; i < (couche->nbNeurone); ++i) {
            listeSortiesNeuronesPrev[i]=listeSortiesNeurones[i];
        }
        couche=couche->next;
        int listeSortiesNeurones[couche->nbNeurone];
        OutCouche(couche,listeSortiesNeuronesPrev,listeSortiesNeurones);

        /*for (int i=0; i<couche->nbNeurone; ++i) {
            printf("Sortie couche neurone %d: %d\n",i+1,listeSortiesNeurones[i]);
        }*/
        if (couche->next == NULL) {
            printf("Sortie finale---\n");
            for (int i=0; i<couche->nbNeurone; ++i) {
                printf("Sortie %d: %d\n",i+1,listeSortiesNeurones[i]);
            }
        }
    }

}