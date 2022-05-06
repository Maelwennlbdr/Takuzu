#include "gameMatrix.h"

void createGrid4(int** grid){
    int matrice[4][4] = {{1, 0, 0, 1},
                         {1, 0, 1, 0},
                         {0, 1, 1, 0},
                         {0, 1, 0, 1}};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = matrice[i][j];
        }
    }
}

void createGrid8(int** grid){
    int matrice[8][8] = {{1, 0, 1, 1, 0, 1, 0, 0},
                         {1, 0, 1, 0, 1, 0, 0, 1},
                         {0, 1, 0, 1, 1, 0, 1, 0},
                         {0, 1, 0, 1, 0, 1, 1, 0},
                         {1, 0, 1, 0, 0, 1, 0, 1},
                         {0, 1, 0, 0, 1, 0, 1, 1},
                         {0, 0, 1, 1, 0, 1, 1, 0},
                         {1, 1, 0, 0, 1, 0, 0, 1}};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            grid[i][j] = matrice[i][j];
        }
    }
}
