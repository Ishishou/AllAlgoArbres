#ifndef UTILS_H
#define UTILS_H

#include "AB.h"
#include <stdio.h>

typedef struct File{
    Arbre valeur;
    struct File *suivant;
}File, *ListeArbre;

int max(int a, int b);
//pour la fonction afficheLargeur
void ajouterFile(Arbre arbre, ListeArbre *ptr_lst);
Arbre sortirFile(ListeArbre *ptr_lst);
int estVideFile(ListeArbre lst);
//pour récuppérer le min et le max
int abr_min(Arbre a);
int abr_max(Arbre a);
//contrôle technique
void verifieABR(Arbre arbre);

#endif
