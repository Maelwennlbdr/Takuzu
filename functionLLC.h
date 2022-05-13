
#ifndef TAKUSU_FUNCTIONLLC_H
#define TAKUSU_FUNCTIONLLC_H

#include "basicFunction.h"

//Not in master
typedef struct {
    Coordonnee moveCoordonnee;
    int numberPlay;
} OneMove;
//Not in master
typedef struct ChainOfMove {
    OneMove movePlay;
    char forceOrRandomMove;
    struct ChainOfMove *nextLink;
} ChainOfMove;

ChainOfMove *creer_link(OneMove, char);

ChainOfMove *createHeadLink(OneMove, char, ChainOfMove*);

ChainOfMove

#endif //TAKUSU_FUNCTIONLLC_H
