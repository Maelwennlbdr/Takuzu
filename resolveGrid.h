#ifndef TAKUSU_RESOLVEGRID_H
#define TAKUSU_RESOLVEGRID_H
#include "verifCoup.h"
#include "basicFunction.h"
#include "gameMatrix.h"


typedef struct {
    Coordonnee moveCoordonnee;
    int numberPlay;
} OneMove;

typedef struct ChainOfMove {
    OneMove movePlay;
    char forceOrRandomMove;
    int numberOfTimeModify;
    struct ChainOfMove *nextLink;
} ChainOfMove;

OneMove afterTwoFollowingSameNumberInLig(TakuzuGrid);
OneMove afterTwoFollowingSameNumberInCol(TakuzuGrid);
OneMove beforeTwoFollowingSameNumberInLig(TakuzuGrid);
OneMove beforeTwoFollowingSameNumberInCol(TakuzuGrid);

OneMove betweenTwoSameNumberInLig(TakuzuGrid);
OneMove betweenTwoSameNumberInCol(TakuzuGrid);

OneMove completeLigIfANumberIsTheRightNumberOfTime(TakuzuGrid);
OneMove completeColIfANumberIsTheRightNumberOfTime(TakuzuGrid);


void fillTakuzuGridWithAMove(TakuzuGrid, OneMove);
int forceMove(TakuzuGrid, ChainOfMove**);
void randomMove(TakuzuGrid, ChainOfMove**);

bool validityGrid(TakuzuGrid);
bool validityCompleteGrid(TakuzuGrid);

ChainOfMove *returnToLastRandomMove(ChainOfMove*, TakuzuGrid);

ChainOfMove *createLink(OneMove, char);
ChainOfMove *createHeadLink(OneMove, char, ChainOfMove *);

#endif //TAKUSU_RESOLVEGRID_H
