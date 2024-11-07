//
// Created by mathi on 04/11/2024.
//

#ifndef COUCHE_H
#define COUCHE_H

#include "structures.h"
Couche* initCouche(int nbNeurones, int nbEntrees);
void outCouche(Couche couche, int listeEntiers[], int listeSortie[]);

#endif //COUCHE_H
