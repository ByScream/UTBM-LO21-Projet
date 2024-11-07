//
// Created by mathi on 04/11/2024.
//

#include "couche.h"

#include <stdio.h>

#include "neurone.h"
Couche* initCouche(int nbNeurones, int nbEntrees) {
    printf("---- premier neurone \n");
    Neurone* premier = initNeur(nbEntrees);
    premier->next=NULL;
    Neurone* tmp = premier;
    for (int i=1; i<nbNeurones; i++) {
        printf("---- %deme neurone \n",i+1);
        Neurone* newNeurone = initNeur(nbEntrees);
        newNeurone->next=NULL;
        tmp->next=newNeurone;
    }
    Couche* couche;
    couche->next=NULL;
    couche->neurone=premier;
    return couche;
}

void outCouche(Couche couche, int listeEntiers[], int listeSortie[]) {
    Neurone* tmp = couche.neurone;
    listeSortie[0]=outNeurone(tmp,listeEntiers);
    int i=1;
    while (tmp->next != NULL) {
        tmp=tmp->next;
        listeSortie[i]=outNeurone(tmp,listeEntiers);
        ++i;
    }
}