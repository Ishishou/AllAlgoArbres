#include "include/AB.h"
#include "include/utils.h"

int main(int argc, char** argv){
    char file[256] = "arbreComplet.txt";
    Arbre arbre;
    
    arbre = genereArbrePrefixe(file);
    affiche_arbre(arbre, 3);

    verifieABR(arbre);

    return 0;
}
