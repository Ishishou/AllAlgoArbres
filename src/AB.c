#include "../include/AB.h"
#include "../include/utils.h"

//création d'arbre
Arbre alloueNoeudAVL(int val, int hauteur, int balance){
    /*on initialise un pointeur ici noeud avec Arbre puis on le 
    déréférence avec * pour avoir la structure en elle même mais ça revient à 
    mettre le nom de la structure */
    Arbre noeud = malloc(sizeof(*noeud));

    assert(noeud != NULL);
    
    noeud->valeur = val;
    noeud->balance = balance;
    noeud->hauteur = hauteur;
    noeud->fd = NULL;
    noeud->fg = NULL;
    return noeud;
}
void genereArbrePrefixe_Aux(FILE* file, Arbre* arbre){
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
Arbre genereArbrePrefixe(char* fichier){
   FILE* file = NULL;
   file = fopen(fichier, "r");
   Arbre arbre;
   assert(fichier != NULL);
   genereArbrePrefixe_Aux(file, &arbre);
   fclose(file);
   return arbre;
}
//caractéristique d'un arbre
int hauteurArbre(Arbre arbre){
    if(arbre == NULL) return -1;
    return 1 + max(hauteurArbre(arbre->fg), hauteurArbre(arbre->fd));
}
int hauteurNoeud(Arbre arbre){
    if(arbre == NULL) return 0;
    return 1 + max(hauteurArbre(arbre->fg), hauteurArbre(arbre->fd));
}
int feuilles(Arbre arbre){
    if(arbre == NULL) return 0;
    if(arbre->fd == NULL && arbre->fg == NULL) return 1;
    return feuilles(arbre->fg) + feuilles(arbre->fg);
}
int noeuds(Arbre arbre){
    if(arbre == NULL) return 0;
    return 1 + noeuds(arbre->fg) + noeuds(arbre->fd);
}
int noeudsInterne(Arbre arbre){
    if(arbre == NULL) return 0;
    if(arbre->fg == NULL && arbre->fd == NULL) return 0;
    return 1 + noeudsInterne(arbre->fg) + noeudsInterne(arbre->fd);
}
int noeudsDeuxFils(Arbre arbre){
    if(arbre == NULL) return 0;
    if(arbre->fg != NULL && arbre->fd != NULL)
        return 1 + noeudsInterne(arbre->fg) + noeudsInterne(arbre->fd);
    return noeudsInterne(arbre->fg) + noeudsInterne(arbre->fd);
}
int estFeuille(Arbre arbre){
    if(arbre->fg == NULL && arbre->fd == NULL) return 1;
    return 0;
}
//affichage d'un arbre
void affichePrefixe(Arbre arbre){
    if(arbre != NULL){
        printf("%d ", arbre->valeur);
        affichePrefixe(arbre->fg);
        affichePrefixe(arbre->fd);
    }
}
void afficheInfixe(Arbre arbre){
    if(arbre != NULL){
        affichePrefixe(arbre->fg);
        printf("%d ", arbre->valeur);
        affichePrefixe(arbre->fd);
    }
}
void afficheSuffixe(Arbre arbre){
    if(arbre != NULL){
        affichePrefixe(arbre->fg);
        affichePrefixe(arbre->fd);
        printf("%d ", arbre->valeur);
    }
}
void afficheLargeur(Arbre arbre){
    if(arbre == NULL) return;
    ListeArbre file = NULL;
    ajouterFile(arbre, &file);
    while(!estVideFile(file)){
        Arbre tmp = sortirFile(&file);
        printf("%d ", tmp->valeur);
        if(tmp->fg) ajouterFile(tmp->fg, &file);
        if(tmp->fd) ajouterFile(tmp->fd, &file);
    }
}
void affiche_arbre(Arbre a, int profondeur){
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
void affiche_chemins_aux(Arbre a, int buffer[], int indice){
    if(a == NULL) return;
    buffer[indice] = a->valeur;
    if(estFeuille(a)){
        afficheTableau(buffer, indice + 1);
        return;
    }
    affiche_chemins_aux(a->fg, buffer, indice + 1);
    affiche_chemins_aux(a->fd, buffer, indice + 1);
}
void affiche_chemins(Arbre a){
    if(a == NULL){
        printf("nique ta mere\n");
        return;
    }
    int* buffer = malloc(sizeof(int) * noeuds(a));
    affiche_chemins_aux(a, buffer, 0);
    free(buffer);
}
//vérification sur un arbre
int est_HG(Arbre arbre){
    int n;
    return est_HG_Aux(arbre, &n);
}
int est_HG_Aux(Arbre arbre, int* n){
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
int est_abr_naif(Arbre a, int min, int max){
    if (!a){
        return 1;
    }

    if (a->valeur < min || a->valeur > max){
        return 0;
    }
    return est_abr_naif(a->fg, abr_min(a), abr_max(a)) && est_abr_naif(a->fd, abr_min(a), abr_max(a)); 
}
int est_abr_definition_aux(Arbre a, int *min, int *max){
    if (!a){
        return 1;
    }

    int minG, maxG, minD, maxD; //deux cases mémoire vides
    
    if (a->fg) {  //sous-arbre gauche
        if (!est_abr_definition_aux(a->fg, &minG, &maxG)){
            return 0;
        }
        if (maxG >= a->valeur){
            return 0;
        }
    } else {
        minG = a->valeur;
    }
    if (a->fd) {  //sous-arbre droit
        if (!est_abr_definition_aux(a->fd, &minD, &maxD)){
            return 0;
        }
        if (minD <= a->valeur){
            return 0;
        }
    } else {
        maxD = a->valeur;
    }

    if (a->fg) {
        *min = minG;
    } else {
        *min = a->valeur;
    }
    if (a->fd) {
        *max = maxD;
    } else {
        *max = a->valeur;
    }
    return 1;
}
int est_abr_definition(Arbre a){
    int min, max;
    return est_abr_definition_aux(a, &min, &max);
} //renvoie soit 1 ou 0
int infixe_croissant(Arbre a, Arbre* dernier_noeud){
    if(!a){
        return 1;
    }
    if(!infixe_croissant(a->fg, dernier_noeud)){
        return 0;
    }

    if(*dernier_noeud != NULL && (*dernier_noeud)->valeur > a->valeur){
        return 0;
    }

    *dernier_noeud = a;

    if(!infixe_croissant(a->fd, dernier_noeud)){
        return 0;
    }
    return 1;
}
int est_abr_infixe(Arbre a, Arbre* dernier_noeud){
    *dernier_noeud = NULL;
    return infixe_croissant(a, dernier_noeud);
} //renvoie soit 1 ou 0
//gestion d'un arbre
Arbre recherche(Arbre a, int n){
    if(a == NULL) return NULL;
    if(a->valeur == n) return a;
    else if(a->valeur > n) return recherche(a->fg, n);
    else return recherche(a->fd, n);
}
void ajout(Arbre *a, int n){
    if(*a == NULL){
        *a = alloueNoeudAVL(n, 0, 0);
        return;
    }
    if((*a)->valeur > n) ajout(&(*a)->fg, n);
    else if ((*a)->valeur <= n) ajout(&(*a)->fd, n);
}
Arbre extrait_min(Arbre a){
    if(a == NULL) return NULL;
    if(a->fg == NULL) return a;
    else return extrait_min(a->fg);
}
Arbre extrait_max(Arbre a){
    if(a == NULL) return NULL;
    if(a->fd == NULL) return a;
    else return extrait_min(a->fd);
}
Arbre extraitSupprime_min(Arbre *a){
    if(*a == NULL) return NULL;
    if((*a)->fg == NULL){
        Arbre min = *a;
        *a = (*a)->fd;
        return min;
    } 
    return extraitSupprime_min(&(*a)->fg);
}
Arbre extraitSupprime_max(Arbre *a){
    if(*a == NULL) return NULL;
    if((*a)->fd == NULL){
        Arbre min = *a;
        *a = (*a)->fg;
        return min;
    } 
    return extraitSupprime_min(&(*a)->fd);
}
Arbre extraitSupprime(Arbre *a, int n){
    if(*a == NULL) return NULL;
    else if((*a)->valeur < n) return extraitSupprime(&(*a)->fd, n);
    else if((*a)->valeur > n) return extraitSupprime(&(*a)->fg, n);
    else{
        Arbre tmp = *a;
        if((*a)->fg == NULL){
            *a = (*a)->fd;
        }else if((*a)->fd == NULL){
            *a = (*a)->fg;
        }
        else{
            Arbre min = extraitSupprime_min(&(*a)->fd);
            min->fg = tmp->fg;
            min->fd = tmp->fd;
            *a = min;
        }
        return tmp;
    }
}

