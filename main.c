#include "include/AB.h"
#include "include/AL.h"
#include "include/Tas.h"
#include "include/utils.h"

int main(int argc, char** argv){
    Tas t;
    t.taille = 0;
    t.capacite = 10;
    t.arbre = NULL;

    ajoute(&t, 5);
    ajoute(&t, 8);
    ajoute(&t, 1);
    ajoute(&t, 2);
    ajoute(&t, 6);
    ajoute(&t, 7);
    ajoute(&t, 9);
    ajoute(&t, 10);
    printf("%d\n", t.taille);
    afficheTableau(t.arbre, t.taille);
    int a = fils_min_Tas(&t, 0);
    printf("%d\n", a);
    return 0;
}
