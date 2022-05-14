#include "resolveGrid.h"

OneMove afterTwoFollowingSameNumberInLig(TakuzuGrid takuzuGrid) {
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 0; (i < size) && (contentOfMove == -1); i++) {
        for (j = 2; j < size; j++) {
            if ((grid[i][j] == -1) && (grid[i][j - 1] == 1) && (grid[i][j - 2] == 1)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 0;
            }
            if ((grid[i][j] == -1) && (grid[i][j - 1] == 0) && (grid[i][j - 2] == 0)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 1;
            }
        }
    }
    nextMove.moveCoordonnee = placeOfMove;
    nextMove.numberPlay = contentOfMove;
    return nextMove;
}


OneMove afterTwoFollowingSameNumberInCol(TakuzuGrid takuzuGrid) {
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 2; (i < size) && (contentOfMove == -1); i++) {
        for (j = 0; j < size; j++) {
            if ((grid[i][j] == -1) && (grid[i - 1][j] == 1) && (grid[i - 2][j] == 1)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 0;
            }
            if ((grid[i][j] == -1) && (grid[i - 1][j] == 0) && (grid[i - 2][j] == 0)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 1;
            }
        }
    }
    nextMove.moveCoordonnee = placeOfMove;
    nextMove.numberPlay = contentOfMove;
    return nextMove;
}

OneMove beforeTwoFollowingSameNumberInLig(TakuzuGrid takuzuGrid) {
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 0; (i < size) && (contentOfMove == -1); i++) {
        for (j = 0; j < size - 2; j++) {
            if ((grid[i][j] == -1) && (grid[i][j + 1] == 1) && (grid[i][j + 2] == 1)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 0;
            }
            if ((grid[i][j] == -1) && (grid[i][j + 1] == 0) && (grid[i][j + 2] == 0)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 1;
            }
        }
    }
    nextMove.moveCoordonnee = placeOfMove;
    nextMove.numberPlay = contentOfMove;
    return nextMove;
}

OneMove beforeTwoFollowingSameNumberInCol(TakuzuGrid takuzuGrid) {
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 0; (i < size - 2) && (contentOfMove == -1); i++) {
        for (j = 0; j < size; j++) {
            if ((grid[i][j] == -1) && (grid[i + 1][j] == 1) && (grid[i + 2][j] == 1)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 0;
            }
            if ((grid[i][j] == -1) && (grid[i + 1][j] == 0) && (grid[i + 2][j] == 0)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 1;
            }
        }
    }
    nextMove.moveCoordonnee = placeOfMove;
    nextMove.numberPlay = contentOfMove;
    return nextMove;
}

OneMove betweenTwoSameNumberInLig(TakuzuGrid takuzuGrid) {
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 0; (i < size) && (contentOfMove == -1); i++) {
        for (j = 1; j < size - 1; j++) {
            if ((grid[i][j] == -1) && (grid[i][j + 1] == 1) && (grid[i][j - 1] == 1)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 0;
            }
            if ((grid[i][j] == -1) && (grid[i][j + 1] == 0) && (grid[i][j - 1] == 0)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 1;
            }
        }
    }
    nextMove.moveCoordonnee = placeOfMove;
    nextMove.numberPlay = contentOfMove;
    return nextMove;
}

OneMove betweenTwoSameNumberInCol(TakuzuGrid takuzuGrid) {
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 1; (i < size - 1) && (contentOfMove == -1); i++) {
        for (j = 0; j < size; j++) {
            if ((grid[i][j] == -1) && (grid[i + 1][j] == 1) && (grid[i - 1][j] == 1)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 0;
            }
            if ((grid[i][j] == -1) && (grid[i + 1][j] == 0) && (grid[i - 1][j] == 0)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 1;
            }
        }
    }
    nextMove.moveCoordonnee = placeOfMove;
    nextMove.numberPlay = contentOfMove;
    return nextMove;
}

OneMove completeLigIfANumberIsTheRightNumberOfTime(TakuzuGrid takuzuGrid) {
    int i, j, cpt0 = 0, cpt1 = 0, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 0; (i < size) && (contentOfMove == -1); i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                cpt1++;
            } else if (grid[i][j] == 0) {
                cpt0++;
            } else if (grid[i][j] == -1) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
            }
        }
        if ((cpt0 == size / 2) && (cpt1 < size / 2)) {
            contentOfMove = 1;
        } else if ((cpt1 == size / 2) && (cpt0 < size / 2)) {
            contentOfMove = 0;
        }
        cpt0 = 0;
        cpt1 = 0;
    }
    nextMove.moveCoordonnee = placeOfMove;
    nextMove.numberPlay = contentOfMove;
    return nextMove;
}

OneMove completeColIfANumberIsTheRightNumberOfTime(TakuzuGrid takuzuGrid) {
    int i, j, cpt0 = 0, cpt1 = 0, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 0; (i < size) && (contentOfMove == -1); i++) {
        for (j = 0; j < size; j++) {
            if (grid[j][i] == 1) {
                cpt1++;
            } else if (grid[j][i] == 0) {
                cpt0++;
            } else if (grid[j][i] == -1) {
                placeOfMove.numberCol = i;
                placeOfMove.numberLig = j;
            }
        }
        if ((cpt0 == size / 2) && (cpt1 < size / 2)) {
            contentOfMove = 1;
        } else if ((cpt1 == size / 2) && (cpt0 < size / 2)) {
            contentOfMove = 0;
        }
        cpt0 = 0;
        cpt1 = 0;
    }
    nextMove.moveCoordonnee = placeOfMove;
    nextMove.numberPlay = contentOfMove;
    return nextMove;
}

void fillTakuzuGridWithAMove(TakuzuGrid takuzuGrid, OneMove playMove) {
    int **grid = takuzuGrid.matrice, numberToPlay = playMove.numberPlay;
    int indexLig = (playMove.moveCoordonnee).numberLig, indexCol = (playMove.moveCoordonnee).numberCol;
    grid[indexLig][indexCol] = numberToPlay;
}

int forceMove(TakuzuGrid takuzuGrid, ChainOfMove **headList) {
    OneMove nextMove;

    nextMove = afterTwoFollowingSameNumberInLig(takuzuGrid);
    if (nextMove.numberPlay != -1) {
        fillTakuzuGridWithAMove(takuzuGrid, nextMove);
        *headList = createHeadLink(nextMove, 'f', *headList);
        return 1;
    }

    nextMove = afterTwoFollowingSameNumberInCol(takuzuGrid);
    if (nextMove.numberPlay != -1) {
        fillTakuzuGridWithAMove(takuzuGrid, nextMove);
        *headList = createHeadLink(nextMove, 'f', *headList);
        return 1;
    }

    nextMove = beforeTwoFollowingSameNumberInLig(takuzuGrid);
    if (nextMove.numberPlay != -1) {
        fillTakuzuGridWithAMove(takuzuGrid, nextMove);
        *headList = createHeadLink(nextMove, 'f', *headList);
        return 1;
    }

    nextMove = beforeTwoFollowingSameNumberInCol(takuzuGrid);
    if (nextMove.numberPlay != -1) {
        fillTakuzuGridWithAMove(takuzuGrid, nextMove);
        *headList = createHeadLink(nextMove, 'f', *headList);
        return 1;
    }

    nextMove = betweenTwoSameNumberInLig(takuzuGrid);
    if (nextMove.numberPlay != -1) {
        fillTakuzuGridWithAMove(takuzuGrid, nextMove);
        *headList = createHeadLink(nextMove, 'f', *headList);
        return 1;
    }

    nextMove = betweenTwoSameNumberInCol(takuzuGrid);
    if (nextMove.numberPlay != -1) {
        fillTakuzuGridWithAMove(takuzuGrid, nextMove);
        *headList = createHeadLink(nextMove, 'f', *headList);
        return 1;
    }

    nextMove = completeLigIfANumberIsTheRightNumberOfTime(takuzuGrid);
    if (nextMove.numberPlay != -1) {
        fillTakuzuGridWithAMove(takuzuGrid, nextMove);
        *headList = createHeadLink(nextMove, 'f', *headList);
        return 1;
    }

    nextMove = completeColIfANumberIsTheRightNumberOfTime(takuzuGrid);
    if (nextMove.numberPlay != -1) {
        fillTakuzuGridWithAMove(takuzuGrid, nextMove);
        *headList = createHeadLink(nextMove, 'f', *headList);
        return 1;
    }

    return 0;
}

void randomMove(TakuzuGrid takuzuGrid, ChainOfMove **headList) {
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    int indexLig, indexCol;
    do {
        indexLig = rand() % size;
        indexCol = rand() % size;
    } while (grid[indexLig][indexCol] != -1);
    grid[indexLig][indexCol] = rand() % 2;
    OneMove currentMove;
    currentMove.numberPlay = grid[indexLig][indexCol];
    currentMove.moveCoordonnee.numberCol = indexCol;
    currentMove.moveCoordonnee.numberLig = indexLig;
    *headList = createHeadLink(currentMove, 'r', *headList);
}

bool validityGrid(TakuzuGrid takuzuGrid) {
    int counter = 0, i;

    for (i = 0; i < takuzuGrid.size; i++) {
        if ((!colAlreadyExisting(takuzuGrid, i)) && (!ligAlreadyExisting(takuzuGrid, i))) {
            counter++;
        }
    }

    if ((sameNumberOf0And1InCol(takuzuGrid)) && (sameNumberOf0And1InLig(takuzuGrid))) {
        counter++;
    }
    if ((only2SameNumberInLig(takuzuGrid)) && (only2SameNumberInCol(takuzuGrid))) {
        counter++;
    }

    if (counter == takuzuGrid.size + 2) {
        return true;
    }
    return false;
}

bool validityCompleteGrid(TakuzuGrid takuzuGrid) {
    if (!isGridComplete(takuzuGrid)) {
        return false;
    }
    return validityGrid(takuzuGrid);
}

bool isGridComplete(TakuzuGrid takuzuGrid) {
    int counter = 0, i, j;
    for (i = 0; i < takuzuGrid.size; i++) {
        for (j = 0; j < takuzuGrid.size; j++) {
            if ((takuzuGrid.matrice)[i][j] != -1) {
                counter++;
            }
        }
    }
    if (counter == takuzuGrid.size * takuzuGrid.size) {
        return true;
    }
    return false;
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
    }
    switch (headOfList->movePlay.numberPlay) {
        case 1: {
            headOfList->movePlay.numberPlay = 0;
            fillTakuzuGridWithAMove(takuzuGrid, headOfList->movePlay);
            break;
        }
        case 0: {
            headOfList->movePlay.numberPlay = 1;
            fillTakuzuGridWithAMove(takuzuGrid, headOfList->movePlay);
            break;
        }
    }
    headOfList->numberOfTimeModify++;
}


ChainOfMove *createHeadLink(OneMove currentMove, char randomOrForce, ChainOfMove *firstHead) {
    ChainOfMove *new = (ChainOfMove *) malloc(sizeof(ChainOfMove));
    new->forceOrRandomMove = randomOrForce;
    new->movePlay = currentMove;
    new->nextLink = firstHead;
    return new;
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

int taille_liste(ChainOfMove *list) {
    ChainOfMove *temp = list;
    int i = 0;
    while (temp != NULL) {
        i++;
        temp = temp->nextLink;
    }
    return i;
}