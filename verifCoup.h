#ifndef TAKUSU_VERIFCOUP_H
#define TAKUSU_VERIFCOUP_H
#include <stdbool.h>
#include "basicFunction.h"

bool sameNumberOf0And1InLig(TakuzuGrid, int);
bool sameNumberOf0And1InCol(TakuzuGrid, int);
bool ligAlreadyExisting(TakuzuGrid, int);
bool colAlreadyExisting(TakuzuGrid, int);

int validityMove(TakuzuGrid, TakuzuGrid); //Not in master

#endif //TAKUSU_VERIFCOUP_H
