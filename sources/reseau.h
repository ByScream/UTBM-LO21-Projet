//
// Created by mathi on 07/11/2024.
//

#ifndef RESEAU_H
#define RESEAU_H
#include "structures.h"
Reseau CreerResNeur(const int nbCouche, int listeNbNeuroneParCouche[]);

void PropagationAvant(const Reseau reseau, int listeEntrees[]);

#endif //RESEAU_H
