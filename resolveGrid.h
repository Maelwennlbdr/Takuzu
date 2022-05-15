#ifndef TAKUSU_RESOLVEGRID_H
#define TAKUSU_RESOLVEGRID_H
#include "verifCoup.h"
#include "basicFunction.h"
#include "gameMatrix.h"

//Not in master
typedef struct {
    Coordonnee moveCoordonnee;
    int numberPlay;
} OneMove;
//Not in master
typedef struct ChainOfMove {
    OneMove movePlay;
    char forceOrRandomMove;
    int numberOfTimeModify;
    struct ChainOfMove *nextLink;
} ChainOfMove;

OneMove afterTwoFollowingSameNumberInLig(TakuzuGrid); // Not in master
OneMove afterTwoFollowingSameNumberInCol(TakuzuGrid); // Not in master
OneMove beforeTwoFollowingSameNumberInLig(TakuzuGrid); // Not in master
OneMove beforeTwoFollowingSameNumberInCol(TakuzuGrid); // Not in master

OneMove betweenTwoSameNumberInLig(TakuzuGrid); // Not in master
OneMove betweenTwoSameNumberInCol(TakuzuGrid); // Not in master

OneMove completeLigIfANumberIsTheRightNumberOfTime(TakuzuGrid); // Not in master
OneMove completeColIfANumberIsTheRightNumberOfTime(TakuzuGrid); // Not in master


void fillTakuzuGridWithAMove(TakuzuGrid, OneMove); // Not in master
int forceMove(TakuzuGrid, ChainOfMove**); // Not in master
void randomMove(TakuzuGrid, ChainOfMove**); // Not in master

bool validityGrid(TakuzuGrid); // Not in master
bool validityCompleteGrid(TakuzuGrid); // Not in master

ChainOfMove *returnToLastRandomMove(ChainOfMove*, TakuzuGrid);

ChainOfMove *createLink(OneMove, char);
ChainOfMove *createHeadLink(OneMove, char, ChainOfMove *);

#endif //TAKUSU_RESOLVEGRID_H
