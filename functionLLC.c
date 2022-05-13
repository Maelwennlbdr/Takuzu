#include "functionLLC.h"

ChainOfMove *createLink(OneMove currentMove, char randomOrForce) {
    ChainOfMove *new;
    new = (ChainOfMove *) malloc(sizeof(ChainOfMove));
    new->forceOrRandomMove = randomOrForce;
    new->movePlay = currentMove;
    new->nextLink = NULL;
    new->numberOfTimeModify = 1;
    return new;
}

ChainOfMove *createHeadLink(OneMove currentMove, char randomOrForce, ChainOfMove* firstHead){
    ChainOfMove *new=(ChainOfMove*) malloc(sizeof (ChainOfMove));
    new->forceOrRandomMove=randomOrForce;
    new->movePlay=currentMove;
    new->nextLink= firstHead;
    return new;
}