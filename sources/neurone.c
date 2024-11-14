//
// Created by mathi on 04/11/2024.
//

#include "neurone.h"

#include <stdio.h>
#include <stdlib.h>



Neurone* InitNeur(const int nbEntrees) {
    int mass;
    printf("Renseignez le premier poids\n");
    scanf("%d",&mass);
    Poids* premier = (Poids*) malloc (sizeof (Poids));
    premier->mass=mass;
    premier->next=NULL;
    Poids* tmp = premier;
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
    Neurone* newNeurone = (Neurone *) malloc (sizeof (Neurone));
    newNeurone->seuil = seuil;
    newNeurone->poids = premier;
    newNeurone->nbEntrees=nbEntrees;
    return newNeurone;
}

int OutNeurone(const Neurone* neurone, int listeEntiers[]) {
    const int size = neurone->nbEntrees;
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