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

typedef struct ChainOfMove{
    Coordonnee moveCoordonnee;
    int numberPlay;
    int nomberOfTimeModify;
    struct ChainOfMove* nextLink;
}ChainOfMove;

int securityInputInt(int, int);

char securityInputChar(char, char);

void printMatrice(TakuzuGrid);
void printMatriceWithMask(TakuzuGrid, TakuzuGrid);
void printUserMatrice(TakusuGrid);

TakuzuGrid createTakuzu(int);

void fillMatrixRand(int **, int);
void fillMatrix(int **, int);
void fillMaskRandom(int **, int, int);
void fillMaskManual(int **, int, int);

TakuzuGrid createdUserTakuzuGrid(TakuzuGrid, TakuzuGrid);

Coordonnee askAndCheckUserCoordonnee(int);
void playAMove(TakuzuGrid, Coordonnee);

#endif //TAKUSU_BASICFUNCTION_H