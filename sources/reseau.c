//
// Created by mathi on 07/11/2024.
//

#include "reseau.h"

#include <stdio.h>
#include <stdlib.h>

#include "couche.h"

Reseau CreerResNeur(const int nbCouche, int listeNbNeuroneParCouche[]) {

    //On créé la liste de couche vide
    Couche* listeCouches = NULL;

    //On initialise la liste des couches en demandant au client
    Couche* tmp;
    for (int i=0; i<nbCouche; i++) {
        printf("---- %deme couche \n",i+1);
        Couche* newCouche;
        if (i==0) { //On initialise la tête de la liste
            printf("Quel est le nombre d'entrées première couche?\n"); // Comme c'est la première couche, on demande le nb d'entrée
            int nbEntrees;
            scanf("%d",&nbEntrees);
            newCouche = InitCouche(listeNbNeuroneParCouche[0],nbEntrees);
            listeCouches = newCouche;
        } else { //On ajoute en queue la nouvelle couche
            newCouche = InitCouche(listeNbNeuroneParCouche[i],listeNbNeuroneParCouche[i-1]); // Nb d'entrée égale au nombre de neurone de la couche précédente
            tmp->next=newCouche;
        }

        newCouche->next=NULL;
        tmp = newCouche;
    }

    //On retourne la liste de couche, ce qui correspond au réseau
    return listeCouches;
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