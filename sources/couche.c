//
// Created by mathi on 04/11/2024.
//

#include "couche.h"

#include <stdio.h>
#include <stdlib.h>

#include "neurone.h"
Couche* InitCouche(const int nbNeurones, const int nbEntrees) {
    printf("---- premier neurone \n");
    Neurone* premier = InitNeur(nbEntrees);
    premier->next=NULL;
    Neurone* tmp = premier;
    for (int i=1; i<nbNeurones; i++) {
        printf("---- %deme neurone \n",i+1);
        Neurone* newNeurone = InitNeur(nbEntrees);
        newNeurone->next=NULL;
        tmp->next=newNeurone;
        tmp=newNeurone;
    }
    Couche* couche = (Couche*) malloc (sizeof (Couche));
    couche->next=NULL;
    couche->neurone=premier;
    couche->nbNeurone=nbNeurones;
    return couche;
}

void OutCouche(const Couche* couche, int listeEntiers[], int listeSortie[]) {
    Neurone* tmp = couche->neurone;
    listeSortie[0]=OutNeurone(tmp,listeEntiers);
    int i=1;
    while (tmp->next != NULL) {
        tmp=tmp->next;
        listeSortie[i]=OutNeurone(tmp,listeEntiers);
        ++i;
    }
}