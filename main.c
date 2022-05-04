#include "menu.h"
#include "basicFunction.h"
#include "verifCoup.h"
#include <stdlib.h>

int main() {
    srand(time(NULL));

    int size = 4, game=1;
    TakuzuGrid mat, masque, userGrid;
    mat = createTakuzu(size);
    masque = createTakuzu(size);

    int matrice[4][4] = {{1, 0, 0, 1},
                         {1, 0, 1, 0},
                         {0, 1, 1, 0},
                         {0, 1, 0, 1}};
    int **grid;
    grid = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(int) * size);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = matrice[i][j];
        }
    }

    mat.matrice = grid;
    fillMask(masque.matrice, masque.size, 5);

    userGrid = createdUserTakuzuGrid(mat, masque);

    printUserMatrice(userGrid);
    while (game == 1) {
        if (validityMove(userGrid)) {
            printf("Le coup est valide.\n");
        } else {
            printf("Le coup n'est pas valide.\n");
        }
        printUserMatrice(userGrid);
        scanf("%d", &game);
    }

    return 0;
}
