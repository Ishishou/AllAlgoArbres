#ifndef AL_H
#define AL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct noeud_tern {
    char lettre ;
    struct noeud_tern * fg; /* fils gauche */
    struct noeud_tern * fd; /* fils droit */
    struct noeud_tern * fils; /* fils principal */
} NoeudT , * ArbreT;

void ajouter_mot(ArbreT *a, char m[]);
int atr_recherche(ArbreT a, char m[]);
int nombre_mots(ArbreT a);
void affiche_lexique_rec(ArbreT a, char buffer[], int index);
void affiche_lexique(ArbreT a);

#endif
