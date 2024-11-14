//
// Created by mathi on 04/11/2024.
//

#ifndef COUCHE_H
#define COUCHE_H

#include "structures.h"
Couche* InitCouche(const int nbNeurones, const int nbEntrees);
void OutCouche(const Couche* couche, int listeEntiers[], int listeSortie[]);

#endif //COUCHE_H
