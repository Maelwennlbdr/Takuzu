#ifndef TAKUSU_BASICFUNCTION_H
#define TAKUSU_BASICFUNCTION_H

#include "basicFunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameMatrix.h"
#include <stdbool.h>

typedef struct {
    int **matrice;
    int size;
} TakuzuGrid;

typedef struct {
    int numberLig;
    int numberCol;
} Coordonnee;

int securityInputInt(int, int);
int securityInputSize();
char securityInputChar(char, char);

void printMatrice(TakuzuGrid);
void printMatriceWithMask(TakuzuGrid, TakuzuGrid);
void printUserMatrice(TakusuGrid);

TakuzuGrid createTakuzu(int);

void fillMatrix(int **, int);
void fillMaskRandom(int **, int, int);
void fillMaskManual(int **, int, int);

TakuzuGrid createdUserTakuzuGrid(TakuzuGrid, TakuzuGrid);
TakuzuGrid createGameTakuzuGrid(int);
TakuzuGrid createMaskTakuzuGrid(int, int, int);

Coordonnee askAndCheckUserCoordonnee(int);
void playAMove(TakuzuGrid, Coordonnee);

bool isMatriceFull(TakuzuGrid);

#endif //TAKUSU_BASICFUNCTION_H
