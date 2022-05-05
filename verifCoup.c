#include "verifCoup.h"


bool sameNumberOf0And1InLig(TakuzuGrid takuzuGrid){
    int numberOf0=0,numberOf1=0;
    int**index;
    index = takuzuGrid.matrice;
    for(int i =0; i < takuzuGrid.size; i++){
        for(int j=0; j < takuzuGrid.size; j++){
            if(index[i][j]==0){
                numberOf0++;
            } else if(index[i][j]==1){
                numberOf1++;
            }
        }
        if(numberOf1 > takuzuGrid.size / 2){
            printf("il y a plus de 1 que de 0 dans la ligne %d \n", i);
            return false;
        }else if(numberOf0 > takuzuGrid.size / 2){
            printf("il y a plus de 0 que de 1 dans la ligne %d \n", i);
            return false;
        }
        numberOf1=numberOf0=0;
    }
    return true;
}

bool sameNumberOf0And1InCol(TakuzuGrid takuzuGrid){
    int numberOf0=0,numberOf1=0;
    int**index;
    index = takuzuGrid.matrice;
    for(int i =0; i < takuzuGrid.size; i++){
        for(int j=0; j < takuzuGrid.size; j++){
            if(index[j][i]==0){
                numberOf0++;
            } else if(index[j][i]==1){
                numberOf1++;
            }
        }
        if(numberOf1 > takuzuGrid.size / 2){
            printf("il y a plus de 1 que de 0 dans la colonne %d \n", i);
            return false;
        }else if(numberOf0 > takuzuGrid.size / 2){
            printf("il y a plus de 0 que de 1 dans la colonne %d \n", i);
            return false;
        }
        numberOf1=numberOf0=0;
    }
    return true;
}

bool ligAlreadyExisting(TakuzuGrid takuzuGrid, int indexOfLig) {
    int size, i, j, **grid, counter = 0;
    grid = takuzuGrid.matrice;
    size = takuzuGrid.size;
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
bool colAlreadyExisting(TakuzuGrid takuzuGrid, int indexOfCol) {
    int size, i, j, **grid, counter = 0;
    grid = takuzuGrid.matrice;
    size = takuzuGrid.size;
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

/* test if a move in correct or not:
// correct -> true
// incorrect -> false*/
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
    if ((sameNumberOf0And1InCol(takuzuGrid)) && (sameNumberOf0And1InLig(takuzuGrid))) {
        counter++;
    }

    if (counter == 2) {
        return 1;
    }
    matrice[indexLig][indexCol] = -1;
    return 0;
}

/*
à tester en condition réel
 */

bool Only2SameNumberInLig(TakuzuGrid takuzuGrid){
    int i, j;
    int** index;
    index=takuzuGrid.matrice;
    for(i=0; i<takuzuGrid.size; i++){
        for(j=2; j< takuzuGrid.size; j++){
            if(index[i][j-1]==1){
                if(index[i][j-2]==1){
                    printf("coup incorrect \n");
                    printf("Il ne peux y avoir trois 1 a la suite.");
                    return false;
                }
            }
            if(index[i][j-1]==0){
                if(index[i][j-2]==0){
                    printf("coup incorrect \n");
                    printf("Il ne peux y avoir trois 0 a la suite.");
                    return false;
                }
            }
        }
    }
    return true;
}
/*
 à tester en condition réel
 */
bool Only2SameNumberInCol(TakuzuGrid takuzuGrid){
    int i, j;
    int** index;
    index=takuzuGrid.matrice;
    for(i=2; i<takuzuGrid.size; i++){
        for(j=0; j< takuzuGrid.size; j++){
            if(index[i-1][j]==1){
                if(index[i-2][j]==1){
                    printf("coup incorrect \n");
                    printf("Il ne peux y avoir trois 1 a la suite.");
                    return false;
                }
            }
            if(index[i-1][j]==0){
                if(index[i-2][j]==0){
                    printf("coup incorrect \n");
                    printf("Il ne peux y avoir trois 0 a la suite.");
                    return false;
                }
            }
        }
    }
    return true;
}