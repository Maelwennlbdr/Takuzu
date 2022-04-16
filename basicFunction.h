#ifndef TAKUSU_BASICFUNCTION_H
#define TAKUSU_BASICFUNCTION_H

#include "basicFunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int **matrice;
    int size;
} TakuzuGrid;

typedef struct {
    int numberLig;
    int numberCol;
} Coordonnee;

int securityInputInt(int, int);

char securityInputChar(char, char);

void printMatrice(TakuzuGrid);

void printMatriceWithMask(TakuzuGrid, TakuzuGrid);

TakuzuGrid createTakuzu(int);

void fillMatrixRand(int **, int);

void fillMatrix(int **, int);

TakuzuGrid createdUserTakuzuGrid(TakuzuGrid, TakuzuGrid);

Coordonnee askAndCheckUserCoordonnee(int);

#endif //TAKUSU_BASICFUNCTION_H
