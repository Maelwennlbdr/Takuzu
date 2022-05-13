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
        for (j = 0; j < size-2; j++) {
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

OneMove beforeTwoFollowingSameNumberInCol(TakuzuGrid takuzuGrid){
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 0; (i < size-2) && (contentOfMove == -1); i++) {
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

OneMove betweenTwoSameNumberInLig(TakuzuGrid takuzuGrid){
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 0; (i < size) && (contentOfMove == -1); i++) {
        for (j = 1; j < size-1; j++) {
            if ((grid[i][j] == -1) && (grid[i][j + 1] == 1) && (grid[i][j -1] == 1)) {
                placeOfMove.numberCol = j;
                placeOfMove.numberLig = i;
                contentOfMove = 0;
            }
            if ((grid[i][j] == -1) && (grid[i][j + 1] == 0) && (grid[i][j -1] == 0)) {
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

OneMove betweenTwoSameNumberInCol(TakuzuGrid takuzuGrid){
    int i, j, contentOfMove = -1;
    int size = takuzuGrid.size, **grid = takuzuGrid.matrice;
    OneMove nextMove;
    Coordonnee placeOfMove;
    for (i = 1; (i < size-1) && (contentOfMove == -1); i++) {
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

void fillTakuzuGridWithAMove(TakuzuGrid takuzuGrid, OneMove playMove) {
    int **grid = takuzuGrid.matrice, numberToPlay = playMove.numberPlay;
    int indexLig = (playMove.moveCoordonnee).numberLig, indexCol = (playMove.moveCoordonnee).numberCol;
    grid[indexLig][indexCol] = numberToPlay;
}
