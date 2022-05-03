#include "verifCoup.h"

bool sameNumberOf0And1InLig(TakuzuGrid takusuGrid, int indexLig) {
    return true;
}

bool sameNumberOf0And1InCol(TakuzuGrid takusuGrid, int indexCol) {
    return true;
}

// test if a line already exist
// exist -> true
// don't exist -> false
bool ligAlreadyExisting(TakuzuGrid takusuGrid, int indexOfLig) {
    int size, i, j, **grid, counter = 0;
    grid = takusuGrid.matrice;
    size = takusuGrid.size;
    for (i = 0; (i < size) && (counter != size); i++) {
        if (i != indexOfLig) {
            for (j = 0; j < size; j++) {
                if ((grid[i][j] == grid[indexOfLig][j]) && (grid[i][j] != -1)) {
                    counter++;
                }
            }
            if (counter != size) {
                counter = 0;
            }
        }
    }
    if (counter == size) {
        return true;
    }
    return false;
}

// test if a column already exist
// exist -> true
// don't exist -> false
bool colAlreadyExisting(TakuzuGrid takusuGrid, int indexOfCol) {
    int size, i, j, **grid, counter = 0;
    grid = takusuGrid.matrice;
    size = takusuGrid.size;
    for (j = 0; (j < size) && (counter != size); j++) {
        if (j != indexOfCol) {
            for (i = 0; i < size; i++) {
                if ((grid[i][j] == grid[i][indexOfCol]) && (grid[i][j] != -1)) {
                    counter++;
                }
            }
            if (counter != size) {
                counter = 0;
            }
        }
    }
    if (counter == size) {
        return true;
    }
    return false;
}

// test if a move in correct or not:
// correct -> true
// incorrect -> false
bool validityMove(TakuzuGrid takuzuGrid) {
    int size = takuzuGrid.size, counter = 0, **matrice = takuzuGrid.matrice;
    Coordonnee currentMove;
    currentMove = askAndCheckUserCoordonnee(size);
    playAMove(takuzuGrid, currentMove);
    int indexCol = currentMove.numberCol, indexLig = currentMove.numberLig;

    if ((!colAlreadyExisting(takuzuGrid, indexCol)) && (!ligAlreadyExisting(takuzuGrid, indexLig))) {
        counter++;
    }
    if ((sameNumberOf0And1InCol(takuzuGrid, indexCol)) && (sameNumberOf0And1InLig(takuzuGrid, indexLig))) {
        counter++;
    }
    if (counter == 2) {
        return true;
    }
    matrice[indexLig][indexCol] = -1;
    return false;
}