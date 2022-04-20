#include "verifCoup.h"

bool sameNumberOf0And1InLig(TakuzuGrid takusuGrid, int indexLig) {
    return true;
}

bool sameNumberOf0And1InCol(TakuzuGrid takusuGrid, int indexCol) {
    return true;
}

bool ligAlreadyExisting(TakuzuGrid takusuGrid, int indexOfLig) {
    int size, i, j, **grid, counter = 0;
    grid = takusuGrid.matrice;
    size = takusuGrid.size;
    for (i = 0; (i < size) && (counter != size); i++) {
        if (i != indexOfLig) {
            for (j = 0; j < size; j++) {
                if ((grid[i][j] == grid[indexOfLig][j])&& (grid[i][j] != -1)) {
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

bool colAlreadyExisting(TakuzuGrid takusuGrid, int indexOfCol) {
    int size, i, j, **grid, counter = 0;
    grid = takusuGrid.matrice;
    size = takusuGrid.size;
    for (j = 0; (j < size) && (counter != size); j++) {
        if (j != indexOfCol) {
            for (i = 0; i < size; i++) {
                if ((grid[i][j] == grid[i][indexOfCol]) && (grid[i][j] != -1)){
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
