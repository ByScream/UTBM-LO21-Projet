//
// Created by mathi on 07/11/2024.
//

#include "reseau.h"

#include <stdio.h>
#include <stdlib.h>

#include "couche.h"

Reseau CreerResNeur(const int nbCouche, int listeNbNeuroneParCouche[]) {
    printf("---- premiere couche \nNombre d'entrées première couche?\n");
    int nbEntrees;
    scanf("%d",&nbEntrees);
    Couche* premier = InitCouche(listeNbNeuroneParCouche[0],nbEntrees);
    premier->next=NULL;
    Couche* tmp = premier;
    for (int i=1; i<nbCouche; i++) {
        printf("---- %deme couche \n",i+1);
        Couche* newCouche = InitCouche(listeNbNeuroneParCouche[i],listeNbNeuroneParCouche[i-1]);
        newCouche->next=NULL;
        tmp->next=newCouche;
        tmp = newCouche;
    }
    return premier;
}


void PropagationAvant(const Reseau reseau, int listeEntrees[]) {
    Couche* premiere_couche = reseau;
    // Tableau pour stocker les sorties de la couche précédente
    int* listeSortiesNeuronesPrev = (int*)malloc(premiere_couche->nbNeurone * sizeof(int));

    // Calcul des sorties de la première couche
    OutCouche(premiere_couche, listeEntrees, listeSortiesNeuronesPrev);

    Couche* couche = premiere_couche->next;
    while (couche != NULL) {
        // Tableau pour les sorties de la couche actuelle
        int* listeSortiesNeurones = (int*)malloc(couche->nbNeurone * sizeof(int));

        // Calcul des sorties pour la couche actuelle
        OutCouche(couche, listeSortiesNeuronesPrev, listeSortiesNeurones);

        // Libération de l'ancien tableau des sorties
        free(listeSortiesNeuronesPrev);

        // Mise à jour pour la prochaine itération
        listeSortiesNeuronesPrev = listeSortiesNeurones;

        // Si c'est la dernière couche, afficher les sorties
        if (couche->next == NULL) {
            for (int i = 0; i < couche->nbNeurone; ++i) {
                printf("Sortie du réseau %d: %d\n", i + 1, listeSortiesNeurones[i]);
            }
        }
        // Passer à la couche suivante
        couche = couche->next;
    }

}