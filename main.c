#include "include/AB.h"

int main(int argc, char** argv){
    char file[256] = "arbreComplet.txt";
    Arbre_avl arbre;
    arbre = genereArbrePrefixe(file);
    affichePrefixe(arbre);
    printf("\n");
    int a = est_HG(arbre);
    printf("%d\n", a);
    affiche_arbre(arbre, 2);
    return 0;
}
