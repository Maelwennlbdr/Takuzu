#include <stdbool.h>
#include "basicFunction.h"

#ifndef TAKUZU_VERIFCOUP_H
#define TAKUZU_VERIFCOUP_H

bool sameNumberOf0And1InLig(TakuzuGrid);

bool sameNumberOf0And1InCol(TakuzuGrid);

bool ligAlreadyExisting(TakuzuGrid, int);

bool colAlreadyExisting(TakuzuGrid, int);

int validityMove();

bool Only2SameNumberInLig(TakuzuGrid);

bool Only2SameNumberInCol(TakuzuGrid);


#endif //TAKUZU_VERIFCOUP_H
