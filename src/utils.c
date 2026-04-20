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
