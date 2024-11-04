//
// Created by mathi on 04/11/2024.
//

#include "neurone.h"

#include <stdio.h>
#include <stdlib.h>

void affichagePoids(neurone* neurone) {
    if (neurone !=NULL) {
        poids* tmp= neurone->poids;
        while(tmp != NULL) {
            printf("%d-->",tmp->mass);
            tmp=tmp->next;
        }
    }
    printf("\n");
}

neurone* initNeur(int nbEntrees) {
    poids* tmp;
    int mass;
    printf("Renseignez le premier poids\n");
    scanf("%d",&mass);
    poids* premier = (poids*) malloc (sizeof (poids));
    premier->mass=mass;
    premier->next=NULL;
    tmp=premier;
    for (int i=1; i<nbEntrees; i++) {

        printf("Renseignez le %dème poids\n",i+1);
        scanf("%d",&mass);
        poids* newPoids = (poids*) malloc (sizeof (poids));
        newPoids->mass=mass;
        newPoids->next=NULL;
        tmp->next=newPoids;
        tmp=newPoids;
    }
    printf("Veuillez définir le seuil du neurone\n"); // Seuil unique pour chaque neurone ?
    int seuil;
    scanf("%d",&seuil);
    neurone* newNeurone;
    newNeurone = (neurone *) malloc (sizeof (neurone));
    newNeurone->seuil = seuil;
    newNeurone->poids = premier;
    newNeurone->nbEntrees=nbEntrees;
    return newNeurone;
}

int outNeurone(neurone* neurone, int listeEntiers[]) {
    int size = neurone->nbEntrees;
    int somme = 0;
    poids* tmp = neurone->poids;
    for (int i=0; i<size; i++) {
        somme += listeEntiers[i]*(tmp->mass);
        tmp = tmp->next;
    }
    if (somme >= (neurone->seuil)) {
        return 1;
    } else {
        return 0;
    }
}