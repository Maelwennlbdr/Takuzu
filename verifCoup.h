#ifndef TAKUSU_VERIFCOUP_H
#define TAKUSU_VERIFCOUP_H
#include <stdbool.h>
#include "basicFunction.h"

bool sameNumberOf0And1InLig(TakuzuGrid);
bool sameNumberOf0And1InCol(TakuzuGrid);
bool ligAlreadyExisting(TakuzuGrid, int);
bool colAlreadyExisting(TakuzuGrid, int);
bool only2SameNumberInLig(TakuzuGrid); //Not in master
bool only2SameNumberInCol(TakuzuGrid); //Not in master

int validityMove(TakuzuGrid, TakuzuGrid); //Not in master

#endif //TAKUSU_VERIFCOUP_H
