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

bool ligAlreadyExisting(TakuzuGrid takusuGrid, int indexOfLig){

    return true;
}

bool colAlreadyExisting(TakuzuGrid takusuGrid, int indexOfCol){

    return true;
}

int validityMove(){

    return 0;
}