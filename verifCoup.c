#include "verifCoup.h"

bool sameNumberOf0And1InLig(TakuzuGrid takusuGrid, int indexLig){
    int numberOf0=0,numberOf1=0;
    int**index;
    index = indexLig;
    for(int i =0; i<takusuGrid.size; i++){
        for(int j=0; j<takusuGrid.size; j++){
            if(index[i][j]==0){
                numberOf0++;
            } else{
                numberOf1++;
            }
        }
        if(numberOf1>numberOf0){
            printf("il y a plus de 1 que de 0 dans la ligne %d", i);
            return false;
        }else if(numberOf0>numberOf1){
            printf("il y a plus de 0 que de 1 dans la ligne %d", i);
            return false;
        }
        numberOf1=numberOf0=0;
    }
    return true;
}

bool sameNumberOf0And1InCol(TakuzuGrid takusuGrid, int indexCol){
    int numberOf0=0,numberOf1=0;
    int**index;
    index = indexCol;
    for(int i =0; i<takusuGrid.size; i++){
        for(int j=0; j<takusuGrid.size; j++){
            if(index[j][i]==0){
                numberOf0++;
            } else{
                numberOf1++;
            }
        }
        if(numberOf1>numberOf0){
            printf("il y a plus de 1 que de 0 dans la colonne %d", i);
            return false;
        }else if(numberOf0>numberOf1){
            printf("il y a plus de 0 que de 1 dans la colonne %d", i);
            return false;
        }
        numberOf1=numberOf0=0;
    }
    return true;
}

// test if a line already exist
// exist -> true
// don't exist -> false
bool ligAlreadyExisting(TakuzuGrid takusuGrid, int indexOfLig) {
    int size, i, j, **grid, counter = 0;
    grid = takusuGrid.matrice;
    size = takusuGrid.size;
    for (i = 0; (i < size) && (counter != size); i++) {
        if (i != indexOfLig) {
            for (j = 0; j < size; j++) {
                if ((grid[i][j] == grid[indexOfLig][j]) && (grid[i][j] != -1)) {
                    counter++;
                }
            }
            if (counter != size) {
                counter = 0;
            }
        }
    }
    if (counter == size) {
        return true;
    }
    return false;
}

// test if a column already exist
// exist -> true
// don't exist -> false
bool colAlreadyExisting(TakuzuGrid takusuGrid, int indexOfCol) {
    int size, i, j, **grid, counter = 0;
    grid = takusuGrid.matrice;
    size = takusuGrid.size;
    for (j = 0; (j < size) && (counter != size); j++) {
        if (j != indexOfCol) {
            for (i = 0; i < size; i++) {
                if ((grid[i][j] == grid[i][indexOfCol]) && (grid[i][j] != -1)) {
                    counter++;
                }
            }
            if (counter != size) {
                counter = 0;
            }
        }
    }
    if (counter == size) {
        return true;
    }
    return false;
}

// test if a move in correct or not:
// correct -> true
// incorrect -> false
int validityMove(TakuzuGrid takuzuGrid, TakuzuGrid originMask) {
    int size = takuzuGrid.size, counter = 0, **matrice = takuzuGrid.matrice, **mask = originMask.matrice;
    Coordonnee currentMove;
    //User enter the cell
    currentMove = askAndCheckUserCoordonnee(size);
    int indexCol = currentMove.numberCol, indexLig = currentMove.numberLig;

    //Test if the cell was already visible or not
    if (mask[indexLig][indexCol] == 1) {
        return -1;
    }
    //User play the move
    playAMove(takuzuGrid, currentMove);

    if ((!colAlreadyExisting(takuzuGrid, indexCol)) && (!ligAlreadyExisting(takuzuGrid, indexLig))) {
        counter++;
    }
    if ((sameNumberOf0And1InCol(takuzuGrid, indexCol)) && (sameNumberOf0And1InLig(takuzuGrid, indexLig))) {
        counter++;
    }

    if (counter == 2) {
        return 1;
    }
    matrice[indexLig][indexCol] = -1;
    return 0;
}
