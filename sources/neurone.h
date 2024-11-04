//
// Created by mathi on 04/11/2024.
//


#ifndef NEURONE_H
#define NEURONE_H
#include "structures.h"
void affichagePoids(neurone* neurone);
neurone* initNeur(int nbEntrees);

int outNeurone(neurone* neurone, int listeEntiers[]);
#endif //NEURONE_H
