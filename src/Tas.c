#include "../include/Tas.h"
#include "../include/utils.h"

int pere(int i){
    return (i - 1)/2;
}
int filsG(int i){
    return 2 * i + 1;
}
int filsD(int i){
    return 2 * i + 2;
}
int ajoute(Tas *t, int x){
    int enfant, parent;
    if(t->taille == 0){
        t->arbre = malloc(sizeof(int));
        assert(t->arbre != NULL);
    }
    if(t->taille == t->capacite) return 0;
    t->arbre = realloc(t->arbre, (t->taille + 1) * sizeof(int));
    t->arbre[t->taille] = x;
    enfant = t->taille;
    parent = pere(enfant);
    t->taille += 1;
    while((enfant > 0) && t->arbre[parent] < t->arbre[enfant]){
        echange(&(t->arbre[parent]), &(t->arbre[enfant]));
        enfant = parent;
        parent = (enfant - 1)/2;
    }
    return 1;
}
int est_tas(int tab[], int taille){
    for(int i = 1; i < taille; i++){
        if(tab[i] > tab[pere(i)]) return 0;
    }
    return 1;
}
int fils_min_Tas(const Tas *t, int indice){
    int g = filsG(indice), d = filsD(indice);
    if(g >= t->taille) return -1;
    else if(d >= t->taille) return g;
    else if(t->arbre[g] > t->arbre[d]) return d;
    return g;
}
