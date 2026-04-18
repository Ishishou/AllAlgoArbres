#include "../include/AB.h"
#include "../include/utils.h"

//création d'arbre
Arbre_avl alloueNoeudAVL(int val, int hauteur, int balance){
    /*on initialise un pointeur ici noeud avec Arbre puis on le 
    déréférence avec * pour avoir la structure en elle même mais ça revient à 
    mettre le nom de la structure */
    Arbre_avl noeud = malloc(sizeof(*noeud));

    assert(noeud != NULL);
    
    noeud->valeur = val;
    noeud->balance = balance;
    noeud->hauteur = hauteur;
    noeud->fd = NULL;
    noeud->fg = NULL;
    return noeud;
}
void genereArbrePrefixe_Aux(FILE* file, Arbre_avl* arbre){
    int valeur;
    fscanf(file, "%d", &valeur);
    if(valeur == 0){
        (*arbre) = NULL;
        return;
    }
    (*arbre) = alloueNoeudAVL(valeur, 0, 0);
    genereArbrePrefixe_Aux(file, &(*arbre)->fg);
    genereArbrePrefixe_Aux(file, &(*arbre)->fd);
}
Arbre_avl genereArbrePrefixe(char* fichier){
   FILE* file = NULL;
   file = fopen(fichier, "r");
   Arbre_avl arbre;
   assert(fichier != NULL);
   genereArbrePrefixe_Aux(file, &arbre);
   fclose(file);
   return arbre;
}
//caractéristique d'un arbre
int hauteurArbre(Arbre_avl arbre){
    if(arbre == NULL) return -1;
    return 1 + max(hauteurArbre(arbre->fg), hauteurArbre(arbre->fd));
}
int hauteurNoeud(Arbre_avl arbre){
    if(arbre == NULL) return 0;
    return 1 + max(hauteurArbre(arbre->fg), hauteurArbre(arbre->fd));
}
int feuilles(Arbre_avl arbre){
    if(arbre == NULL) return 0;
    if(arbre->fd == NULL && arbre->fg == NULL) return 1;
    return feuilles(arbre->fg) + feuilles(arbre->fg);
}
int noeuds(Arbre_avl arbre){
    if(arbre == NULL) return 0;
    return 1 + noeuds(arbre->fg) + noeuds(arbre->fd);
}
int noeudsInterne(Arbre_avl arbre){
    if(arbre == NULL) return 0;
    if(arbre->fg == NULL && arbre->fd == NULL) return 0;
    return 1 + noeudsInterne(arbre->fg) + noeudsInterne(arbre->fd);
}
int noeudsDeuxFils(Arbre_avl arbre){
    if(arbre == NULL) return 0;
    if(arbre->fg != NULL && arbre->fd != NULL)
        return 1 + noeudsInterne(arbre->fg) + noeudsInterne(arbre->fd);
    return noeudsInterne(arbre->fg) + noeudsInterne(arbre->fd);
}
//affichage d'un arbre
void affichePrefixe(Arbre_avl arbre){
    if(arbre != NULL){
        printf("%d ", arbre->valeur);
        affichePrefixe(arbre->fg);
        affichePrefixe(arbre->fd);
    }
}
void afficheInfixe(Arbre_avl arbre){
    if(arbre != NULL){
        affichePrefixe(arbre->fg);
        printf("%d ", arbre->valeur);
        affichePrefixe(arbre->fd);
    }
}
void afficheSuffixe(Arbre_avl arbre){
    if(arbre != NULL){
        affichePrefixe(arbre->fg);
        affichePrefixe(arbre->fd);
        printf("%d ", arbre->valeur);
    }
}
void afficheLargeur(Arbre_avl arbre){
    if(arbre == NULL) return;
    ListeArbre file = NULL;
    ajouterFile(arbre, &file);
    while(!estVideFile(file)){
        Arbre_avl tmp = sortirFile(&file);
        printf("%d ", tmp->valeur);
        if(tmp->fg) ajouterFile(tmp->fg, &file);
        if(tmp->fd) ajouterFile(tmp->fd, &file);
    }
}
void affiche_arbre(Arbre_avl a, int profondeur){
    if(a == NULL){
        return;
    }

    // on affiche d'abord le sous-arbre droit
    affiche_arbre(a->fd, profondeur + 1);

    // indentation
    for(int i = 0; i < profondeur; i++){
        printf("          ");
    }

    printf("%d H=%d B=%d\n", a->valeur, a->hauteur, a->balance);

    // puis le sous-arbre gauche
    affiche_arbre(a->fg, profondeur + 1);
}
//vérification sur un arbre
int est_HG(Arbre_avl arbre){
    int n;
    return est_HG_Aux(arbre, &n);
}
int est_HG_Aux(Arbre_avl arbre, int* n){
    if(!arbre){
        *n = 0;
        return 1;
    }
    int ng, nd;
    int rg = est_HG_Aux(arbre->fg, &ng);
    int rd = est_HG_Aux(arbre->fd, &nd);
    *n = ng + nd + 1;
    return rg && rd && (ng >= nd);
}
