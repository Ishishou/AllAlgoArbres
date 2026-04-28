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
        //percolation ascendante
        echange(&(t->arbre[parent]), &(t->arbre[enfant]));
        enfant = parent;
        parent = pere(enfant);
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
int fils_max_Tas(const Tas *t, int indice){
    int g = filsG(indice), d = filsD(indice);
    if(g >= t->taille) return -1;
    else if(d >= t->taille) return g;
    else if(t->arbre[g] <= t->arbre[d]) return d;
    return g;
}
void change(Tas *t, int indice, int valeur){
    if(indice > t->taille - 1) return;
    int ancienne_valeur = t->arbre[indice];
    t->arbre[indice] = valeur;
    if(valeur > ancienne_valeur){
        //percolation ascendante
        int enfant, parent;
        enfant = indice;
        parent = pere(enfant);
        while((enfant > 0) && t->arbre[parent] < t->arbre[enfant]){
            echange(&(t->arbre[parent]), &(t->arbre[enfant]));
            enfant = parent;
            parent = pere(enfant);
        }
    }else if(valeur < ancienne_valeur){
        //percolation descendante
        int i = indice;
        while(1){
            int f_max = fils_max_Tas(t, i);
            if(f_max == -1 || t->arbre[i] >= t->arbre[f_max]) break;
            echange(&(t->arbre[f_max]), &(t->arbre[i]));
            i = f_max;
        }
    }
}
int extrait_max_Tas(Tas *t){
    if(t->taille == 0) return -1;
    int max = t->arbre[0];
    t->arbre[0] = t->arbre[t->taille - 1];
    t->taille--;
    //percolation descendante
    int i = 0;
    while(1){
        int f_max = fils_max_Tas(t, i);
        if(f_max == -1 || t->arbre[i] >= t->arbre[f_max]) break;
        echange(&(t->arbre[f_max]), &(t->arbre[i]));
        i = f_max;
    }
    return max;
}
