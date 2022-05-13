#include "functionLLC.h"

ChainOfMove *creer_link(OneMove currentMove, char randomOrForce) {
    ChainOfMove *new;
    new = (ChainOfMove *) malloc(sizeof(ChainOfMove));
    new->forceOrRandomMove = randomOrForce;
    new->movePlay = currentMove;
    new->nextLink = NULL;
    return new;
}

ChainOfMove *createHeadLink(OneMove currentMove, char randomOrForce, ChainOfMove* firstHead){
    ChainOfMove *new=(ChainOfMove*) malloc(sizeof (ChainOfMove));
    new->forceOrRandomMove=randomOrForce;
    new->movePlay=currentMove;
    new->nextLink= firstHead;
    return new;
}