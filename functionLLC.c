#include "functionLLC.h"

ChainOfMove *createLink(OneMove currentMove, char randomOrForce) {
    ChainOfMove *new;
    new = (ChainOfMove *) malloc(sizeof(ChainOfMove));
    new->forceOrRandomMove = randomOrForce;
    new->movePlay = currentMove;
    new->nextLink = NULL;
    new->numberOfTimeModify = 1;
    return new;
}

ChainOfMove *createHeadLink(OneMove currentMove, char randomOrForce, ChainOfMove* firstHead){
    ChainOfMove *new= createLink(currentMove, randomOrForce);
    new->nextLink= firstHead;
    return new;
}

int taille_liste(ChainOfMove* list) {
    ChainOfMove *temp = list;
    int i = 0;
    while (temp != NULL) {
        i++;
        temp = temp->nextLink;
    }
    return i;
}

 void afficher_liste(ChainOfMove *list) {
    ChainOfMove* temp = list;
    int size = taille_liste(list), i;
    for (i = 0; i < size - 1; i++) {
        printf("%c - ", temp->forceOrRandomMove);
        temp = temp->nextLink;
    }
    printf("%c\n", temp->forceOrRandomMove);
}

void returnToLastRandomMove(ChainOfMove *headOfList, TakuzuGrid takuzuGrid) {
    int **grid = takuzuGrid.matrice;
    int indexCol, indexLig;
    ChainOfMove *temp = headOfList;
    while ((headOfList->forceOrRandomMove == 'f') || (headOfList->numberOfTimeModify >= 2)) {
        indexCol = (headOfList->movePlay).moveCoordonnee.numberCol;
        indexLig = (headOfList->movePlay).moveCoordonnee.numberLig;
        grid[indexLig][indexCol] = -1;
        headOfList = headOfList->nextLink;
        free(temp);
        ChainOfMove *temp = headOfList;
    }
    switch (headOfList->movePlay.numberPlay) {
        case 1: {
            headOfList->movePlay.numberPlay = 0;
            break;
        }
        case 0: {
            headOfList->movePlay.numberPlay = 1;
            break;
        }
    }
    headOfList->numberOfTimeModify++;
}