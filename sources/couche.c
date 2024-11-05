//
// Created by mathi on 04/11/2024.
//

#include "couche.h"

#include <stdio.h>

#include "neurone.h"
Couche initCouche(int nbNeurones, int nbEntrees) {
    neurone* tmp;
    printf("---- premier neurone \n");
    neurone* premier = initNeur(nbEntrees);
    tmp = premier;
    for (int i=1; i<nbNeurones; i++) {
        printf("---- %deme neurone \n",i+1);
        neurone* newNeurone = initNeur(nbEntrees);
        tmp->next=newNeurone;
    }
    return premier;
}
