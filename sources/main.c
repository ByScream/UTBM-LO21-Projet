#include <stdio.h>
#include <stdlib.h>

#include "reseau.h"

int main(void) {
    int listeEntrees[]={2,8,9,-2,4,3};
    int listeNeurones[]={1};
    Reseau reseau = CreerResNeur(1,listeNeurones);
    propagationAvant(reseau,listeEntrees);
    return 0;
}
