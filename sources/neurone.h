//
// Created by mathi on 04/11/2024.
//


#ifndef NEURONE_H
#define NEURONE_H
#include "structures.h"
void affichagePoids(Neurone* neurone);
Neurone* initNeur(int nbEntrees);

int outNeurone(Neurone* neurone, int listeEntiers[]);
#endif //NEURONE_H
