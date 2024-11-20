#include <stdio.h>
#include <stdlib.h>

#include "neurone.h"
#include "reseau.h"

int main(void) {
    int listeEntrees1[]={1,0,0};
    int listeEntrees2[]={0,1,0};
    int listeEntrees3[]={0,0,1};
    int listeEntrees4[]={1,1,0};
    int listeEntrees5[]={1,0,1};
    int listeEntrees6[]={0,1,1};
    int listeEntrees7[]={0,0,0};
    int listeEntrees8[]={1,1,1};
    int listeNeurones[]={4,2,1};
    Reseau reseau = CreerResNeur(3,listeNeurones);
    printf("---- Entrée = [1,0,0] :\n");
    PropagationAvant(reseau,listeEntrees1);
    printf("---- Entrée = [0,1,0] :\n");
    PropagationAvant(reseau,listeEntrees2);
    printf("---- Entrée = [0,0,1] :\n");
    PropagationAvant(reseau,listeEntrees3);
    printf("---- Entrée = [1,1,0] :\n");
    PropagationAvant(reseau,listeEntrees4);
    printf("---- Entrée = [1,0,1] :\n");
    PropagationAvant(reseau,listeEntrees5);
    printf("---- Entrée = [0,1,1] :\n");
    PropagationAvant(reseau,listeEntrees6);
    printf("---- Entrée = [0,0,0] :\n");
    PropagationAvant(reseau,listeEntrees7);
    printf("---- Entrée = [1,1,1] :\n");
    PropagationAvant(reseau,listeEntrees8);

    return 0;
}
