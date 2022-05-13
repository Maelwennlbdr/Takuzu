#include "functionLLC.h"

ChainOfMove *creer_maillon(OneMove currentMove, char randomOrForce){
    ChainOfMove *nouveau;
    nouveau=(ChainOfMove*) malloc(sizeof(ChainOfMove) );
    nouveau->forceOrRandomMove=randomOrForce;
    nouveau->movePlay=currentMove;
    nouveau->nextLink=NULL;
    return nouveau;
}