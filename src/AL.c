#include "../include/AL.h"

void ajouter_mot(ArbreT *a, char m[]){
    if(*a == NULL){
        *a = malloc(sizeof(*(*a)));
        assert(*a != NULL);
        (*a)->lettre = *m;
        (*a)->fg = NULL;
        (*a)->fd = NULL;
        (*a)->fils = NULL;
        if(*m == '\0') return;
    }
    if(*m == (*a)->lettre){
        //on met deux if consécutif au lieu d'un && parce que si la condition est fausse 
        //on rentre dans les else et c'est pas ce qu'on veut
        if(*m != '\0'){
            ajouter_mot(&(*a)->fils, m + 1);
        }
    }
    else if(*m < (*a)->lettre){
        ajouter_mot(&(*a)->fg, m);
    }
    else if(*m > (*a)->lettre){
        ajouter_mot(&(*a)->fd, m);
    }
}
int atr_recherche(ArbreT a, char m[]){
    if(a == NULL){
        return 0;
    }
    else if(*m < a->lettre){
        return atr_recherche(a->fg, m);
    }
    else if(*m > a->lettre){
        return atr_recherche(a->fd, m);
    }
    else{
        if(*m == '\0') return 1;
        return atr_recherche(a->fils, m + 1);
    }
}
int nombre_mots(ArbreT a){
    if(a == NULL) return 0;
    int ce_mot = (a->lettre == '\0') ? 1 : 0;
    return ce_mot + nombre_mots(a->fg) + nombre_mots(a->fils) + nombre_mots(a->fd);
}
void affiche_lexique_rec(ArbreT a, char buffer[], int index){
    if(a == NULL) return;

    affiche_lexique_rec(a->fg, buffer, index);
    buffer[index] = a->lettre;
    
    if(a->lettre == '\0'){
        printf("%s\n", buffer);
    }else{
        affiche_lexique_rec(a->fils, buffer, index + 1);
    }
    affiche_lexique_rec(a->fd, buffer, index);
}
void affiche_lexique(ArbreT a) {
    char buffer[256];
    affiche_lexique_rec(a, buffer, 0);
}
