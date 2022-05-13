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