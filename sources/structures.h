//
// Created by mathi on 04/11/2024.
//

#ifndef STRUCTURES_H
#define STRUCTURES_H
typedef struct poids {
    int mass;
    struct poids* next;
} poids;

typedef poids* ListePoids;

typedef struct neurone {
    int seuil;
    int nbEntrees;
    poids* poids;
    struct neurone* next;
} neurone;

typedef neurone* Couche;


#endif //STRUCTURES_H
