//
// Created by mathi on 04/11/2024.
//

#include "neurone.h"

#include <stdio.h>
#include <stdlib.h>



Neurone* InitNeur(const int nbEntrees) {

    //On créé la liste de Poids vide
    Poids* listePoids = NULL;

    //On initialise la liste de poids en demandant au client
    Poids* tmp;
    for (int i=0; i<nbEntrees; i++) {
        int mass;
        printf("Renseignez le %d-eme poids\n",i+1);
        scanf("%d",&mass);
        Poids* newPoids = (Poids*) malloc (sizeof (Poids));
        newPoids->mass=mass;
        newPoids->next=NULL;
        if (i==0) { //On initialise la tête de la liste avec le poids créé
            listePoids = newPoids;
        } else { //On ajoute en queue de la liste le poids créé
            tmp->next=newPoids;
        }
        tmp=newPoids;
    }

    //On demande le seuil du neurone
    printf("Veuillez definir le seuil du neurone\n");
    int seuil;
    scanf("%d",&seuil);

    //On créé le neurone
    Neurone* newNeurone = (Neurone *) malloc (sizeof (Neurone));

    //On affecte au neurone son seuil, sa liste de poids, et son nombre d'entrées
    newNeurone->seuil = seuil;
    newNeurone->poids = listePoids;
    newNeurone->nbEntrees=nbEntrees;

    //On retourne le neurone créé par InitNeur
    return newNeurone;
}

int OutNeurone(const Neurone* neurone, int listeEntiers[]) {
    const int size = neurone->nbEntrees;
    int somme = 0;

    //On récupère la tête de liste de Poids du neurone
    Poids* tmp = neurone->poids;

    //On calcule la somme de la liste d'entrée * le poids correspondant
    for (int i=0; i<size; i++) {
        somme += listeEntiers[i]*(tmp->mass);

        //On passe au poids suivant
        tmp = tmp->next;
    }
    if (somme >= (neurone->seuil)) {
        return 1;
    } else {
        return 0;
    }
}