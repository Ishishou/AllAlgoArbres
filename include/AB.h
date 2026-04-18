#ifndef AB_H 
#define AB_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct noeud_avl{
    int valeur;
    int balance;
    int hauteur;
    struct noeud_avl *fd;
    struct noeud_avl *fg;
}noeud_avl, *Arbre_avl;

//création d'arbre
Arbre_avl alloueNoeudAVL(int val, int hauteur, int balance);
void genereArbrePrefixe_Aux(FILE* file, Arbre_avl* arbre);
Arbre_avl genereArbrePrefixe(char* fichier);
//caractéristiques d'un arbre
int hauteurArbre(Arbre_avl arbre);
int hauteurNoeud(Arbre_avl arbre);
int feuilles(Arbre_avl arbre);
int noeuds(Arbre_avl arbre);
int noeudsInterne(Arbre_avl arbre);
int noeudsDeuxFils(Arbre_avl arbre);
//vérfication sur un arbre
int est_HG(Arbre_avl arbre);
int est_HG_Aux(Arbre_avl arbre, int* n);
//affichage
void affichePrefixe(Arbre_avl arbre);
void afficheInfixe(Arbre_avl arbre);
void afficheSuffixe(Arbre_avl arbre);
void afficheLargeur(Arbre_avl arbre);
void affiche_arbre(Arbre_avl a, int profondeur);

#endif
