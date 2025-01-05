#include <stdio.h>
#include <stdlib.h>

#include "neurone.h"
#include "reseau.h"

int main(void) {
    int nbCouches;
    printf("Combien de couches il y aura ?\n");
    scanf("%d",&nbCouches);
    int listeNeurones[nbCouches];
    for (int i = 0; i < nbCouches; i++) {
        printf("Nombre de neurones sur la %d-eme couche ?\n",i+1);
        scanf("%d",&listeNeurones[i]);
    }
    printf("Construction du reseau...\n");
    Reseau reseau = CreerResNeur(nbCouches,listeNeurones);

    char refaire='N';
    do {
        printf("Donnez l'entree sur laquelle vous voulez effectuer une propagation avant\n");
        int listeEntrees[reseau->neurone->nbEntrees];
        for (int i = 0; i < reseau->neurone->nbEntrees; i++) {
            printf("Saisissez la %d-eme entree\n",i+1);
            scanf("%d",&listeEntrees[i]);
        }
        printf("Resultat:\n");
        PropagationAvant(reseau,listeEntrees);
        printf("Voulez vous refaire une propagation avant ? O/N\n");
        scanf(" %c", &refaire);
    } while (refaire=='O');

    return 0;
}
