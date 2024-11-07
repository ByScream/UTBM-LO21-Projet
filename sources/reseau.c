//
// Created by mathi on 07/11/2024.
//

#include "reseau.h"

#include <stdio.h>

#include "couche.h"

Reseau CreerResNeur(int nbCouche, int listeNbNeuroneParCouche[]) {
    printf("---- premiere couche \nNombre d'entrées première couche?\n");
    int nbEntrees;
    scanf("%d",&nbEntrees);
    Couche* premier = initCouche(listeNbNeuroneParCouche[0],nbEntrees);
    premier->next=NULL;
    Couche* tmp = premier;
    for (int i=1; i<nbCouche; i++) {
        printf("---- %deme couche \n",i+1);
        Couche* newCouche = initCouche(listeNbNeuroneParCouche[i],listeNbNeuroneParCouche[i-1]);
        newCouche->next=NULL;
        tmp->next=newCouche;
    }
    return premier;
}
