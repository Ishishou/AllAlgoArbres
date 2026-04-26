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
int estFeuille(Arbre arbre);
int noeuds(Arbre arbre);
int noeudsInterne(Arbre arbre);
int noeudsDeuxFils(Arbre arbre);
//vérfication sur un arbre
int est_HG(Arbre arbre);
int est_HG_Aux(Arbre arbre, int* n);
int est_abr_naif(Arbre a, int min, int max);
int est_abr_definition_aux(Arbre a, int *min, int *max);
int est_abr_definition(Arbre a);
int infixe_croissant(Arbre a, Arbre* dernier_noeud);
int est_abr_infixe(Arbre a, Arbre* dernier_noeud);
//affichage
void affichePrefixe(Arbre arbre);
void afficheInfixe(Arbre arbre);
void afficheSuffixe(Arbre arbre);
void afficheLargeur(Arbre arbre);
void affiche_arbre(Arbre a, int profondeur);
void affiche_chemins_aux(Arbre a, int buffer[], int indice);
void affiche_chemins(Arbre a);
//gestion d'un arbre
Arbre recherche(Arbre a, int n);
void ajout(Arbre *a, int n);
Arbre extrait_min(Arbre a);
Arbre extrait_max(Arbre a);
Arbre extraitSupprime_min(Arbre *a);
Arbre extraitSupprime_max(Arbre *a);
Arbre extraitSupprime(Arbre *a, int n);

#endif
