#include "include/AB.h"
#include "include/AL.h"
#include "include/utils.h"

int main(int argc, char** argv){

    int n = 1;
    ArbreT a = NULL;

    ajouter_mot(&a, "salut");
    ajouter_mot(&a, "bon");
    ajouter_mot(&a, "yo");
    ajouter_mot(&a, "hello");
    ajouter_mot(&a, "salaud");

    n = nombre_mots(a);

    printf("resultat = %d\n", n);
    affiche_lexique(a);
    return 0;
}
