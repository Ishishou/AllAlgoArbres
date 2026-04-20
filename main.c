#include "include/AB.h"

int main(int argc, char** argv){
    char file[256] = "arbreComplet.txt";
    Arbre arbre, arbre2;
    arbre = genereArbrePrefixe(file);
    affichePrefixe(arbre);
    printf("\n");
    int a = est_HG(arbre);
    printf("%d\n", a);
    affiche_arbre(arbre, 2);
    arbre2 = recherche(arbre, 4);
    printf("%d\n", arbre2->valeur);
    return 0;
}
