#ifndef TAKUSU_FUNCTIONLLC_H
#define TAKUSU_FUNCTIONLLC_H
#include "basicFunction.h"

// Not in master
typedef struct{
    Coordonnee moveCoordonnee;
    int numberPlay;
}OneMove;

//Not in master
typedef struct ChainOfMove{
    OneMove movePlay;
    char forceOrRandomMove;
    int numberOfTimeModify;
    struct ChainOfMove* nextLink;
}ChainOfMove;

ChainOfMove *createLink(OneMove, char);

void returnToLastRandomMove(ChainOfMove*, TakuzuGrid);

#endif //TAKUSU_FUNCTIONLLC_H
