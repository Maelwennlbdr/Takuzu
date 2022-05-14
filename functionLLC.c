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

ChainOfMove *createHeadLink(OneMove currentMove, char randomOrForce, ChainOfMove *firstHead) {
    ChainOfMove *new = (ChainOfMove *) malloc(sizeof(ChainOfMove));
    new->forceOrRandomMove = randomOrForce;
    new->movePlay = currentMove;
    new->nextLink = firstHead;
    return new;
}

ChainOfMove* freeHeadLink(ChainOfMove *headLink) {
    if (headLink != NULL) {
        ChainOfMove *tmp = headLink;
        headLink = headLink->nextLink;
        tmp->nextLink = NULL;
        free(tmp);
    }
    return headLink;
}

int taille_liste(ChainOfMove *list) {
    ChainOfMove *temp = list;
    int i = 0;
    while (temp != NULL) {
        i++;
        temp = temp->nextLink;
    }
    return i;
}

void afficher_liste(ChainOfMove *list) {
    ChainOfMove *temp = list;
    int size = taille_liste(list), i;
    for (i = 0; i < size - 1; i++) {
        printf("%c - ", temp->forceOrRandomMove);
        temp = temp->nextLink;
    }
    printf("%c\n", temp->forceOrRandomMove);
}

