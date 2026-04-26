#include "../include/utils.h"

int max(int a, int b){
    return (a > b ? a : b); 
}
//pour la fonction afficherLargeur
void ajouterFile(Arbre arbre, ListeArbre *ptr_lst){
    //on crée un noeud indépendant et on l'initialise
    ListeArbre nouveau = malloc(sizeof(*nouveau));
    assert(nouveau != NULL);
    nouveau->valeur = arbre;
    nouveau->suivant = NULL;
    //on accroche ce noeud à la liste chainée
    if(*ptr_lst == NULL){
        *ptr_lst = nouveau;
    }else{
        //sinon on parcours la liste jusqu'à la queue
        ListeArbre temp = *ptr_lst;
        while(temp->suivant != NULL){
            temp = temp->suivant;
        }
        //on raccroche ce noeud à la queue de la liste
        temp->suivant = nouveau;
    }
}
Arbre sortirFile(ListeArbre *ptr_lst){
    //si la liste est vide l'arbre est considéré comme NULL
    if(*ptr_lst == NULL) return NULL;
    //l'arbre à traiter est le premier dans la liste c'est à dire *ptr_lst
    ListeArbre aSupprimer = *ptr_lst;
    //on réccupère la valeur de cet arbre
    Arbre valeur = aSupprimer->valeur;
    //on actualise la liste chainé en mettant le prechain à la tête
    *ptr_lst = aSupprimer->suivant;
    //on libère le noeud alloué
    free(aSupprimer);
    return valeur;
}
int estVideFile(ListeArbre lst){
    return (lst == NULL);
}
//fonctions pour récupérer le min et le max
int abr_min(Arbre a){
    if (a == NULL){
        return -1; //si arbre NULL
    }
    if (a->fg == NULL){
        return a->valeur;
    }
    return abr_min(a->fg);
}
int abr_max(Arbre a){
    if (a == NULL){
        return -1;
    }
    if (a->fd == NULL){
        return a->valeur;
    }
    return abr_max(a->fd);
}
//contrôle technique
void verifieABR(Arbre arbre){
    Arbre ptr_arbre = NULL;
    int a = est_abr_naif(arbre, abr_min(arbre), abr_max(arbre));
    printf("est arbre naïf : %d\n", a);
    a = est_abr_definition(arbre);
    printf("est arbre définition : %d\n", a);
    a = est_abr_infixe(arbre, &ptr_arbre);
    printf("est arbre infixe : %d\n", a);
}
//affichage de tableau
void afficheTableau(int* tab, int taille){
    for(int i = 0; i < taille; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}
