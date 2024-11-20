#include <stdio.h>
#include <stdlib.h>

#include "neurone.h"
#include "reseau.h"

int main(void) {
    int listeEntreees[]={1};
    printf("%d\n",OutNeurone(InitNeur(1),listeEntreees));
    int listeEntrees1[]={1,0,0};
    int listeNeurones[]={4,2,1};
    Reseau reseau = CreerResNeur(3,listeNeurones);
    PropagationAvant(reseau,listeEntrees1);
    return 0;
}
