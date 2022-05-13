#ifndef TAKUSU_RESOLVEGRID_H
#define TAKUSU_RESOLVEGRID_H

#include "verifCoup.h"
#include "basicFunction.h"
#include "gameMatrix.h"
#include "functionLLC.h"

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

void returnToLastRandomMove(ChainOfMove*, TakuzuGrid);


ChainOfMove *createHeadLink(OneMove, char, ChainOfMove *);
void afficher_liste(ChainOfMove *);
int taille_liste(ChainOfMove *);

#endif //TAKUSU_RESOLVEGRID_H
