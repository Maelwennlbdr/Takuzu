#include "basicFunction.h"

int securityInputInt(int borneMin, int borneMax) {
    int userValue;
    do {
        printf("Rentrez un entier entre %d et %d : ", borneMin, borneMax);
        scanf("%d", &userValue);
    } while ((userValue < borneMin) || (userValue > borneMax));
    return userValue;
}

char securityInputChar(char borneMin, char borneMax) {
    char userChar;
    do {
        printf("Saisir un caractère : \n");
        scanf("%c", &userChar);
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
            mat[i][j] = 0;
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

Coordonnee askAndCheckUserCoordonnee(int size){
    Coordonnee numberCase;
    char indexCol;
    int indexLig;
    printf("Saisir une coordonnee : \n");
    indexCol = securityInputChar('A', 'A'+size-1);
    indexLig = securityInputInt(1, size);
    numberCase.numberLig = indexLig-1;
    numberCase.numberCol = indexCol-65;
    return numberCase;
}
