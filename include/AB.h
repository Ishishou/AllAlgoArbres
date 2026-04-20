#ifndef AB_H 
#define AB_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct noeud{
    int valeur;
    int balance;
    int hauteur;
    struct noeud *fd;
    struct noeud *fg;
}noeud, *Arbre;

//création d'arbre
Arbre alloueNoeudAVL(int val, int hauteur, int balance);
void genereArbrePrefixe_Aux(FILE* file, Arbre* arbre);
Arbre genereArbrePrefixe(char* fichier);
//caractéristiques d'un arbre
int hauteurArbre(Arbre arbre);
int hauteurNoeud(Arbre arbre);
int feuilles(Arbre arbre);
int noeuds(Arbre arbre);
int noeudsInterne(Arbre arbre);
int noeudsDeuxFils(Arbre arbre);
//vérfication sur un arbre
int est_HG(Arbre arbre);
int est_HG_Aux(Arbre arbre, int* n);
//affichage
void affichePrefixe(Arbre arbre);
void afficheInfixe(Arbre arbre);
void afficheSuffixe(Arbre arbre);
void afficheLargeur(Arbre arbre);
void affiche_arbre(Arbre a, int profondeur);
//gestion d'un arbre
Arbre recherche(Arbre a, int n);
void ajout(Arbre *a, int n);
Arbre extrait_min(Arbre a);
Arbre extrait_max(Arbre a);
Arbre extraitSupprime_min(Arbre *a);
Arbre extraitSupprime_max(Arbre *a);
Arbre extraitSupprime(Arbre *a, int n);

#endif
