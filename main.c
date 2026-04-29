#include "include/AB.h"
#include "include/AL.h"
#include "include/Tas.h"
#include "include/utils.h"

int main(int argc, char** argv){
    Tas t;
    t.taille = 0;
    t.capacite = 10;
    t.arbre = NULL;
    int tab[10] = {5, 4, 1, 2, 3, 7, 9, 8, 2, 8};
    ajoute(&t, 5);
    ajoute(&t, 8);
    ajoute(&t, 1);
    ajoute(&t, 2);
    ajoute(&t, 6);
    ajoute(&t, 7);
    ajoute(&t, 9);
    ajoute(&t, 10);
    

    afficheTableau(tab, 10);
    tri_tas(tab, 10);
    afficheTableau(tab, 10);

    return 0;
}
