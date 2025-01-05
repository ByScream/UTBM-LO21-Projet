//
// Created by mathi on 04/11/2024.
//

#include "couche.h"

#include <stdio.h>
#include <stdlib.h>

#include "neurone.h"
Couche* InitCouche(const int nbNeurones, const int nbEntrees) {

    //On créé la liste de neurones vide
    Neurone* listeNeurones = NULL;

    //On initialise la liste de neurone en demandant au client
    Neurone* tmp;
    for (int i=0; i<nbNeurones; i++) {
        printf("---- %d-eme neurone \n",i+1);
        Neurone* newNeurone = InitNeur(nbEntrees);
        newNeurone->next=NULL;
        if (i==0) { //On initialise la tête de la liste avec le neurone créé
            listeNeurones = newNeurone;
        } else { //On ajoute en queue de la liste le neurone créé
            tmp->next=newNeurone;
        }

        tmp=newNeurone;
    }

    //On créé la couche
    Couche* couche = (Couche*) malloc (sizeof (Couche));

    //On affecte à la couche sa liste de neurones, et son nombre de neurones
    couche->next=NULL;
    couche->neurone=listeNeurones;
    couche->nbNeurone=nbNeurones;
    return couche;
}

void OutCouche(const Couche* couche, int listeEntiers[], int listeSortie[]) {
    Neurone* tmp = couche->neurone;
    for (int i=0; i<(couche->nbNeurone); ++i) {
        listeSortie[i]=OutNeurone(tmp,listeEntiers);
        tmp=tmp->next;
    }
}