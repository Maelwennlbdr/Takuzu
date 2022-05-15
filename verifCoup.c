#include "verifCoup.h"

bool sameNumberOf0And1InLig(TakuzuGrid takuzuGrid) {
    int numberOf0 = 0, numberOf1 = 0;
    int **index;
    index = takuzuGrid.matrice;
    for (int i = 0; i < takuzuGrid.size; i++) {
        for (int j = 0; j < takuzuGrid.size; j++) {
            if (index[i][j] == 0) {
                numberOf0++;
            } else if (index[i][j] == 1) {
                numberOf1++;
            }
        }
        if (numberOf1 > takuzuGrid.size / 2) {
            printf("Il y a plus de 1 que de 0 dans la ligne %d \n", i+1);
            return false;
        } else if (numberOf0 > takuzuGrid.size / 2) {
            printf("Il y a plus de 0 que de 1 dans la ligne %d \n", i+1);
            return false;
        }
        numberOf1 = numberOf0 = 0;
    }
    return true;
}

bool sameNumberOf0And1InCol(TakuzuGrid takuzuGrid) {
    int numberOf0 = 0, numberOf1 = 0;
    int **index;
    index = takuzuGrid.matrice;
    for (int i = 0; i < takuzuGrid.size; i++) {
        for (int j = 0; j < takuzuGrid.size; j++) {
            if (index[j][i] == 0) {
                numberOf0++;
            } else if (index[j][i] == 1) {
                numberOf1++;
            }
        }
        if (numberOf1 > takuzuGrid.size / 2) {
            printf("Il y a plus de 1 que de 0 dans la colonne %d.\n", i+1);
            return false;
        } else if (numberOf0 > takuzuGrid.size / 2) {
            printf("Il y a plus de 0 que de 1 dans la colonne %d.\n", i+1);
            return false;
        }
        numberOf1 = numberOf0 = 0;
    }
    return true;
}


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
        printf("La ligne %d existe déjà.\n", indexOfLig+1);
        return true;
    }
    return false;
}


bool colAlreadyExisting(TakuzuGrid takuzuGrid, int indexOfCol) {
    int size, i, j, **grid, counter = 0;
    grid = takuzuGrid.matrice;
    size = takuzuGrid.size;
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
        printf("La colonne %d existe déjà.\n", indexOfCol+1);
        return true;
    }
    return false;
}

bool only2SameNumberInLig(TakuzuGrid takuzuGrid) {
    int i, j;
    int **index;
    index = takuzuGrid.matrice;
    for (i = 0; i < takuzuGrid.size; i++) {
        for (j = 2; j < takuzuGrid.size; j++) {
            if ((index[i][j] == 1) && (index[i][j - 1] == 1) && (index[i][j - 2] == 1)) {
                printf("Il ne peux y avoir trois 1 a la suite (ligne %d).\n", j+1);
                return false;
            }
            if (index[i][j] == 0) {
                if (index[i][j - 1] == 0) {
                    if (index[i][j - 2] == 0) {
                        printf("Il ne peux y avoir trois 0 a la suite (ligne %d).\n", j+1);
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool only2SameNumberInCol(TakuzuGrid takuzuGrid) {
    int i, j;
    int **index;
    index = takuzuGrid.matrice;
    for (i = 2; i < takuzuGrid.size; i++) {
        for (j = 0; j < takuzuGrid.size; j++) {
            if ((index[i][j] == 1) && (index[i - 1][j] == 1) && (index[i - 2][j] == 1)) {
                printf("Il ne peux y avoir trois 1 a la suite (colonne %d).\n", i+1);
                return false;
            }
            if ((index[i][j] == 0) && (index[i - 1][j] == 0) && (index[i - 2][j] == 0)) {
                printf("Il ne peux y avoir trois 0 a la suite  (colonne %d).\n", i+1);
                return false;
            }
        }
    }
    return true;
}


int validityMove(TakuzuGrid takuzuGrid, TakuzuGrid originMask) {
    int size = takuzuGrid.size, counter = 0, **matrice = takuzuGrid.matrice, **mask = originMask.matrice;
    Coordonnee currentMove;

    printf("Saisir une coordonnee : \n");
    currentMove = askAndCheckUserCoordonnee(size);
    int indexCol = currentMove.numberCol, indexLig = currentMove.numberLig, oldContent = matrice[indexLig][indexCol];


    if (mask[indexLig][indexCol] == 1) {
        return -1;
    }

    playAMove(takuzuGrid, currentMove);

    if ((!colAlreadyExisting(takuzuGrid, indexCol)) && (!ligAlreadyExisting(takuzuGrid, indexLig))) {
        counter++;
    }
    if ((sameNumberOf0And1InCol(takuzuGrid)) && (sameNumberOf0And1InLig(takuzuGrid))) {
        counter++;
    }
    if ((only2SameNumberInLig(takuzuGrid)) && (only2SameNumberInCol(takuzuGrid))) {
        counter++;
    }

    if (counter == 3) {
        return 1;
    }
    matrice[indexLig][indexCol] = oldContent;
    return 0;
}
