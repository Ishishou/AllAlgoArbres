#include "include/AB.h"

int main(int argc, char** argv){
    char file[256] = "arbreComplet.txt";
    Arbre arbre, arbre2;
    arbre = genereArbrePrefixe(file);
    ajout(&arbre, 1);
    affiche_arbre(arbre, 3);
    arbre2 = extraitSupprime(&arbre, 5);
    printf("%d\n", arbre2->valeur);
    affiche_arbre(arbre, 3);
    return 0;
}
