#include "menu.h"
#include "basicFunction.h"

int main() {
    srand(time(NULL));
    allmenu();
    int size = 4;
    TakuzuGrid mat, masque, userGrid;
    mat = createTakuzu(size);
    masque = createTakuzu(size);

    fillMatrixRand(mat.matrice, mat.size);
    fillMatrixRand(masque.matrice, masque.size);


    userGrid = createdUserTakuzuGrid(mat, masque);

    printMatrice(masque);
    printMatrice(mat);

    printMatriceWithMask(mat, masque);
    printMatrice(userGrid);
    askAndCheckUserCoordonnee(mat.size);
    return 0;
}
