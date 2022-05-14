#include "basicFunction.h"

int securityInputInt(int borneMin, int borneMax) {
    int userValue;
    do {
        printf("Rentrez un entier entre %d et %d : ", borneMin, borneMax);
        scanf("%d", &userValue);
    } while ((userValue < borneMin) || (userValue > borneMax));
    return userValue;
}

int securityInputSize() {
    int size;
    do {
        printf("Rentrez la taille souhaiter : ");
        scanf("%d", &size);
    } while ((size % 2 == 1) || (size > 9) || (size < 3));
    return size;
}

char securityInputChar(char borneMin, char borneMax) {
    char userChar;
    do {
        printf("Saisir un caractère : ");
        scanf("%c", &userChar);
        if (userChar > 90) {
            userChar -= 32;
        }
    } while ((userChar < borneMin) || (userChar > borneMax));
    return userChar;
}


void printMatrice(TakuzuGrid matrice) {
    int i, j, size;
    int **truc;
    truc = matrice.matrice;
    size = matrice.size;
    printf("\t");
    for (i = 'A'; i < ('A' + size); i++) {
        printf("%c\t", i);
    }
    printf("\n");
    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);
        for (j = 0; j < size; j++) {
            printf("%d\t", truc[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printMatriceWithMask(TakuzuGrid matrice, TakuzuGrid mask) {
    int i, j, size;
    size = matrice.size;

    int **masque, **mat;
    mat = matrice.matrice;
    masque = mask.matrice;

    printf("\t");
    for (i = 'A'; i < ('A' + size); i++) {
        printf("%c\t", i);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);
        for (j = 0; j < size; j++) {
            if (masque[i][j] == 1) {
                printf("%d\t", mat[i][j]);
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printUserMatrice(TakuzuGrid userGrid) {
    int i, j, size;
    size = userGrid.size;

    int **grid;
    grid = userGrid.matrice;

    printf("\t");
    for (i = 'A'; i < ('A' + size); i++) {
        printf("%c\t", i);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);
        for (j = 0; j < size; j++) {
            if (grid[i][j] != -1) {
                printf("%d\t", grid[i][j]);
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

TakuzuGrid createTakuzu(int size) {
    int i;
    TakuzuGrid matrice;
    matrice.matrice = (int **) malloc(sizeof(int *) * size);
    for (i = 0; i < size; i++) {
        matrice.matrice[i] = malloc(sizeof(int) * size);
    }
    matrice.size = size;
    return matrice;
}

void fillMatrixRand(int **mat, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mat[i][j] = (rand() % 2);
        }
    }
}

void fillMatrix(int **mat, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mat[i][j] = 1;
        }
    }
}

void fillMaskRandom(int **mat, int size, int numberOfCellShow) {
    int i, j, indexLig, indexCol;
    for (i = 0; i < numberOfCellShow; i++) {
        do {
            indexLig = rand() % size;
            indexCol = rand() % size;
        } while (mat[indexLig][indexCol] == 1);
        mat[indexLig][indexCol] = 1;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (mat[i][j] != 1) {
                mat[i][j] = 0;
            }
        }
    }
}

void fillMaskManual(int **mat, int size, int numberOfCellShow) {
    int i, j;
    Coordonnee coordonneeOfCell;
    for (i = 0; i < numberOfCellShow; i++) {
        do {
            printf("Saisir une coordonnee que vous souhaitez voir apparaitre: \n");
            coordonneeOfCell = askAndCheckUserCoordonnee(size);
        } while (mat[coordonneeOfCell.numberLig][coordonneeOfCell.numberCol] == 1);
        mat[coordonneeOfCell.numberLig][coordonneeOfCell.numberCol] = 1;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (mat[i][j] != 1) {
                mat[i][j] = 0;
            }
        }
    }
}

TakuzuGrid createdUserTakuzuGrid(TakuzuGrid solutionMatrix, TakuzuGrid maskMatrix) {
    TakuzuGrid userTakusuGrid;
    int **mask;
    mask = maskMatrix.matrice;
    userTakusuGrid = createTakuzu(solutionMatrix.size);
    int i, j;
    for (i = 0; i < solutionMatrix.size; i++) {
        for (j = 0; j < solutionMatrix.size; j++) {
            if (mask[i][j] == 1) {
                (userTakusuGrid.matrice[i][j]) = (solutionMatrix.matrice[i][j]);
            } else {
                (userTakusuGrid.matrice[i][j]) = -1;
            }
        }
    }
    return userTakusuGrid;
}

TakuzuGrid createGameTakuzuGrid(int size) {
    TakuzuGrid gameGrid;
    gameGrid = createTakuzu(size);
    int **grid;
    grid = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(int) * size);
    }

    switch (size) {
        case 4: {
            createGrid4(grid);
            break;
        }
        case 8: {
            createGrid8(grid);
            break;
        }
    }
    gameGrid.matrice = grid;
    return gameGrid;
}

TakuzuGrid createMaskTakuzuGrid(int size, int numberOfCellShow, int randOrManual) {
    TakuzuGrid mask = createTakuzu(size);
    if (randOrManual == 1) {
        fillMaskRandom(mask.matrice, size, numberOfCellShow);
    } else if (randOrManual == 2) {
        fillMaskManual(mask.matrice, size, numberOfCellShow);
    }
    return mask;
}

Coordonnee askAndCheckUserCoordonnee(int size) {
    Coordonnee numberCase;
    char indexCol;
    int indexLig;
    printf("Saisir une coordonnee : \n");
    indexCol = securityInputChar('A', 'A' + size - 1);
    indexLig = securityInputInt(1, size);
    numberCase.numberLig = indexLig - 1;
    numberCase.numberCol = indexCol - 65;
    return numberCase;
}


void playAMove(TakuzuGrid takuzuGrid, Coordonnee playMove) {
    int size = takuzuGrid.size, indexCol, indexLig;
    indexCol = playMove.numberCol;
    indexLig = playMove.numberLig;

    int **grid = takuzuGrid.matrice;
    grid[indexLig][indexCol] = securityInputInt(0, 1);
    takuzuGrid.matrice = grid;
}

bool isMatriceFull(TakuzuGrid takuzuGrid) {
    int **grid = takuzuGrid.matrice, size = takuzuGrid.size;
    int i, j, counter = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j] != -1) {
                counter++;
            }
        }
    }
    if (counter == size * size) {
        return true;
    }
    return false;
}