//
// Created by mathi on 04/11/2024.
//

#include "neurone.h"

#include <stdio.h>
#include <stdlib.h>

void affichagePoids(Neurone* neurone) {
    if (neurone !=NULL) {
        Poids* tmp= neurone->poids;
        while(tmp != NULL) {
            printf("%d-->",tmp->mass);
            tmp=tmp->next;
        }
    }
    printf("\n");
}

Neurone* initNeur(int nbEntrees) {
    Poids* tmp;
    int mass;
    printf("Renseignez le premier poids\n");
    scanf("%d",&mass);
    Poids* premier = (Poids*) malloc (sizeof (Poids));
    premier->mass=mass;
    premier->next=NULL;
    tmp=premier;
    for (int i=1; i<nbEntrees; i++) {

        printf("Renseignez le %dème poids\n",i+1);
        scanf("%d",&mass);
        Poids* newPoids = (Poids*) malloc (sizeof (Poids));
        newPoids->mass=mass;
        newPoids->next=NULL;
        tmp->next=newPoids;
        tmp=newPoids;
    }
    printf("Veuillez définir le seuil du neurone\n"); // Seuil unique pour chaque neurone ?
    int seuil;
    scanf("%d",&seuil);
    Neurone* newNeurone;
    newNeurone = (Neurone *) malloc (sizeof (Neurone));
    newNeurone->seuil = seuil;
    newNeurone->poids = premier;
    newNeurone->nbEntrees=nbEntrees;
    return newNeurone;
}

int outNeurone(Neurone* neurone, int listeEntiers[]) {
    int size = neurone->nbEntrees;
    int somme = 0;
    Poids* tmp = neurone->poids;
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