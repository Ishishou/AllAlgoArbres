#ifndef TAS_H
#define TAS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 7

typedef struct{
    int* arbre;
    int taille;
    int capacite;
} Tas;

int ajoute(Tas *t, int x);
int est_tas(int tab[], int taille);
int fils_min_Tas(const Tas *t, int indice);
void change(Tas *t, int indice, int valeur);
int extrait_min_Tas(Tas *t);
void tri_tas(int tab[], int taille);
int pere(int i);
int filsG(int i);
int filsD(int i);

#endif
