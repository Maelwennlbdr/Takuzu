#include "menu.h"
#include "basicFunction.h"
#include "verifCoup.h"
#include <stdlib.h>

int main() {
    srand(time(NULL));
    allmenu();
    int size = 4;
    TakuzuGrid mat, masque, userGrid;
    mat = createTakuzu(size);
    masque = createTakuzu(size);

    int game = 1;

    //fillMatrixRand(mat.matrice, mat.size);
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
    fillMatrixRand(masque.matrice, masque.size);


    userGrid = createdUserTakuzuGrid(mat, masque);

    printf("Masque :\n");
    printMatrice(masque);
    printf("Matrice :\n");
    printMatrice(mat);

    printMatriceWithMask(mat, masque);

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
