#include <stdio.h>
#include <stdlib.h>

#include "neurone.h"
#include "reseau.h"

int main(void) {

    //Paramétrage des différentes entrées possibles
    int listeEntrees1[]={1,0,0};
    int listeEntrees2[]={0,1,0};
    int listeEntrees3[]={0,0,1};
    int listeEntrees4[]={1,1,0};
    int listeEntrees5[]={1,0,1};
    int listeEntrees6[]={0,1,1};
    int listeEntrees7[]={0,0,0};
    int listeEntrees8[]={1,1,1};

    //Liste des neurones sur chaque couche
    int listeNeurones[]={4,2,1};

    //On créé le réseau, en définissant le nombre de couches, et la liste de neurones
    Reseau reseau = CreerResNeur(3,listeNeurones);

    //On fait la propagation avant sur le réseau, pour chaque entrée, et on observe le résultat
    printf("---- Entree = [1,0,0] :\n");
    PropagationAvant(reseau,listeEntrees1);
    printf("---- Entree = [0,1,0] :\n");
    PropagationAvant(reseau,listeEntrees2);
    printf("---- Entree = [0,0,1] :\n");
    PropagationAvant(reseau,listeEntrees3);
    printf("---- Entree = [1,1,0] :\n");
    PropagationAvant(reseau,listeEntrees4);
    printf("---- Entree = [1,0,1] :\n");
    PropagationAvant(reseau,listeEntrees5);
    printf("---- Entree = [0,1,1] :\n");
    PropagationAvant(reseau,listeEntrees6);
    printf("---- Entree = [0,0,0] :\n");
    PropagationAvant(reseau,listeEntrees7);
    printf("---- Entree = [1,1,1] :\n");
    PropagationAvant(reseau,listeEntrees8);

    return 0;
}
