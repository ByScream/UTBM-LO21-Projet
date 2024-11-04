//
// Created by mathi on 04/11/2024.
//

#include "couche.h"

#include <stdio.h>

#include "neurone.h"
Couche initCouche(int nbNeurones, int nbEntrees) {
    for (int i=0; i<nbNeurones; i++) {
        printf("---- %deme neurone \n",i+1);
        neurone* newNeurone = initNeur(nbEntrees);
    }
}
