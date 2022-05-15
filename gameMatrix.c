#include "gameMatrix.h"

void createGrid4(int **grid) {
    int matrice1[4][4] = {{1, 0, 0, 1},
                         {1, 0, 1, 0},
                         {0, 1, 1, 0},
                         {0, 1, 0, 1}};
    int matrice2[4][4] = {{0, 1, 1, 0},
                         {0, 1, 0, 1},
                         {1, 0, 1, 0},
                         {1, 0, 0, 1}};

    int random = rand() % 2;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            switch (random) {
                case 0:{
                    grid[i][j] = matrice1[i][j];
                    break;
                }
                case 1:{
                    grid[i][j] = matrice2[i][j];
                    break;
                }
            }
        }
    }
}

void createGrid8(int **grid) {
    int matrice1[8][8] = {{1, 0, 1, 1, 0, 1, 0, 0},
                          {1, 0, 1, 0, 1, 0, 0, 1},
                          {0, 1, 0, 1, 1, 0, 1, 0},
                          {0, 1, 0, 1, 0, 1, 1, 0},
                          {1, 0, 1, 0, 0, 1, 0, 1},
                          {0, 1, 0, 0, 1, 0, 1, 1},
                          {0, 0, 1, 1, 0, 1, 1, 0},
                          {1, 1, 0, 0, 1, 0, 0, 1}};
    int matrice2[8][8] = {
            {0, 0, 1, 0, 1, 0, 1, 1},
            {1, 0, 0, 1, 0, 1, 0, 1},
            {0, 1, 0, 1, 1, 0, 1, 0},
            {0, 1, 1, 0, 0, 1, 1, 0},
            {1, 0, 1, 0, 0, 1, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 1},
            {0, 1, 1, 0, 1, 0, 1, 0},
            {1, 1, 0, 1, 0, 1, 0, 0},};
    int random = rand() % 2;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (random) {
                case 0:{
                    grid[i][j] = matrice1[i][j];
                    break;
                }
                case 1:{
                    grid[i][j] = matrice2[i][j];
                    break;
                }
            }
        }
    }
}
