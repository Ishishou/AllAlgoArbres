typedef struct noeud_tern {
    char lettre ;
    struct noeud_tern * fg ; /* fils gauche */
    struct noeud_tern * fd ; /* fils droit */
    struct noeud_tern * fils ; /* fils principal */
} NoeudT , * ArbreT ;