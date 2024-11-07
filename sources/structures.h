//
// Created by mathi on 04/11/2024.
//

#ifndef STRUCTURES_H
#define STRUCTURES_H


typedef struct Poids {
    int mass;
    struct Poids* next;
} Poids;

typedef Poids* ListePoids;

typedef struct Neurone {
    int seuil;
    int nbEntrees;
    Poids* poids;
    struct Neurone* next;
} Neurone;

typedef struct Couche {
    Neurone* neurone;
    int nbNeurone;
    struct Couche* next;
} Couche;

typedef Couche* Reseau;


#endif //STRUCTURES_H
