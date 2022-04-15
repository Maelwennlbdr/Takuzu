# Takuzu

X-afficher matrice
X-afficher matrice avec calque

X-saisie sécurisée

X-Dans une ligne, il doit y avoir autant de 0 que de 1
X-Dans une colonne, il doit y avoir autant de 0 que de 1
X-Il ne peut pas y avoir deux lignes identiques dans une grille
X-Il ne peut pas y avoir deux colonnes identiques dans une grille

-coup valide ou correct


Si coup correct mais matrice pas remplie on fait quoi ?
Qu'est ce qu'on explique quand on dit expliquer pourquoi le coup est correct?


coup (liste chainée):
    - position
    - valeur
    - type du coup (forcé / hypothèse)
    - combien d'hypothèse



typedef struct {
    int** matrice;
    int size;
}TakusuGrid;
