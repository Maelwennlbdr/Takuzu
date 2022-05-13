#include "functionLLC.h"

ChainOfMove *creer_maillon(OneMove currentMove, char radomOrForce) {
    ChainOfMove *nouveau;
    nouveau = (ChainOfMove *) malloc(sizeof(ChainOfMove));
    nouveau->forceOrRandomMove = radomOrForce;
    nouveau->movePlay = currentMove;
    nouveau->nextLink = NULL;
    return nouveau;
}

