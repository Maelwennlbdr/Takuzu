#ifndef TAKUSU_BASICFUNCTION_H
#define TAKUSU_BASICFUNCTION_H

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

int securityInputSize(); // Not in master
char securityInputChar(char, char);

void printMatrice(TakuzuGrid);

void printMatriceWithMask(TakuzuGrid, TakuzuGrid);

void printUserMatrice(TakuzuGrid);//Not in master

TakuzuGrid createTakuzu(int);

void fillMatrixRand(int **, int);

void fillMatrix(int **, int);

void fillMaskRandom(int **, int, int); //Not in master
void fillMaskManual(int **, int, int); //Not in master

TakuzuGrid createdUserTakuzuGrid(TakuzuGrid, TakuzuGrid);

TakuzuGrid createGameTakuzuGrid(int); //Not in master
TakuzuGrid createMaskTakuzuGrid(int, int, int); //Not in master

Coordonnee askAndCheckUserCoordonnee(int);

void playAMove(TakuzuGrid, Coordonnee); //Not in master
bool isMatriceFull(TakuzuGrid); //Not in master

#endif //TAKUSU_BASICFUNCTION_H