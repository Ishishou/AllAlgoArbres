#ifndef UTILS_H
#define UTILS_H

#include "AB.h"

typedef struct File{
    Arbre valeur;
    struct File *suivant;
}File, *ListeArbre;

int max(int a, int b);
//pour la fonction afficheLargeur
void ajouterFile(Arbre arbre, ListeArbre *ptr_lst);
Arbre sortirFile(ListeArbre *ptr_lst);
int estVideFile(ListeArbre lst);


#endif
