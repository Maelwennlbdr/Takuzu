#include "menu.h"

int allmenu() {
    int choiceUser;
    printf("Fait votre choix :\n");
    printf("\t1- Resoudre une grille manuellement\n");
    printf("\t2- Resolution automatique d'une grille\n");
    printf("\t3- Generation d'une grille\n");
    printf("\t4- Quitter\n");
    choiceUser = securityInputInt(1, 4);

    switch (choiceUser) {
        case 1: {
            printf("Part I-\n");
            int size;
            size = securityInputSize();
            menuPartI(size);
            break;
        }
        case 2: {
            printf("Part II-\n");
            int size;
            size = securityInputSize();
            menuPartII(size);
            break;
        }
        case 3: {
            printf("Part III-\n");
            int size;
            size = securityInputSize();
            menuPartIII(size);
            break;
        }
    }
    return 0;
}

int menuPartI(int sizeGrid) {
    int choiceUser;
    printf("\nFait votre choix :\n");
    printf("\t1- Saisir manuellement un masque\n");
    printf("\t2- Generer automatiquement un masque\n");
    printf("\t3- Jouer\n");
    printf("\t4- Quitter\n");
    choiceUser = securityInputInt(1, 4);

    TakuzuGrid gameGrid = createGameTakuzuGrid(sizeGrid);

    switch (choiceUser) {
        case 1: {
            TakuzuGrid mask;
            printf("Combien de case voulez-vous afficher :\n");
            int numberOfCellShow = securityInputInt(1, sizeGrid * sizeGrid);
            mask = createMaskTakuzuGrid(sizeGrid, numberOfCellShow, 2);
            printMatrice(mask);
            printMatriceWithMask(gameGrid, mask);
            break;
        }
        case 2: {
            TakuzuGrid mask;
            printf("Combien de case voulez-vous afficher :\n");
            int numberOfCellShow = securityInputInt(1, sizeGrid * sizeGrid);
            mask = createMaskTakuzuGrid(sizeGrid, numberOfCellShow, 1);
            printMatrice(mask);
            printMatriceWithMask(gameGrid, mask);
            break;
        }
        case 3: {
            int life = 0, move;
            TakuzuGrid mask, userGrid;
            printf("Combien de case voulez-vous afficher : ");
            int numberOfCellShow = securityInputInt(1, sizeGrid * sizeGrid);
            mask = createMaskTakuzuGrid(sizeGrid, numberOfCellShow, 1);
            printMatriceWithMask(gameGrid, mask);
            userGrid = createdUserTakuzuGrid(gameGrid, mask);
            while (life < 3) {
                move = validityMove(userGrid, mask);
                if (move == 1) {
                    printf("Le coup est valide.\n");
                } else if (move == -1) {
                    printf("La case n'est pas modifiable.\n");
                } else {
                    printf("Le coup n'est pas valide.\n");
                    life++;
                }
                printUserMatrice(userGrid);
                printf("Il vous reste %d vies.\n", 3 - life);
            }
            break;
        }
    }
    return 0;
}


int menuPartII(int sizeGrid) {
    int canAMoveBePlay = 1;
    char timeBetween2Move = ' ';
    TakuzuGrid gameGrid = createGameTakuzuGrid(sizeGrid);
    TakuzuGrid mask = createMaskTakuzuGrid(sizeGrid, sizeGrid, 1);
    TakuzuGrid userGrid = createdUserTakuzuGrid(gameGrid, mask);
    ChainOfMove *list = NULL;
    while ((!validityCompleteGrid(userGrid)) && (!isMatriceFull(userGrid))) {
        do {
            while (canAMoveBePlay == 1) {
                canAMoveBePlay = forceMove(userGrid, &list);
                scanf("%c", &timeBetween2Move);
                if (canAMoveBePlay == 1) {
                    printUserMatrice(userGrid);
                }
            }
            canAMoveBePlay = 1;
            if (!validityGrid(userGrid)) {
                list = returnToLastRandomMove(list, userGrid);
            }

            if (!isMatriceFull(userGrid)) {
                randomMove(userGrid, &list);
                printUserMatrice(userGrid);
            }
        } while (!isMatriceFull(userGrid));

        if (!validityCompleteGrid(userGrid)) {
            printf("La matrice n'est pas correct\n");
            list = returnToLastRandomMove(list, userGrid);
            printUserMatrice(userGrid);
        } else {
            printf("Voila, cette matrice est correcte.\n");
        }
    }
}

int menuPartIII(int sizeGrid) {
    int choiceUser;
    printf("\nFait votre choix :\n");
    printf("\t1- afficher l'ensemble des lignes valides\n");
    printf("\t2- generer une grille de Takuzu \n");
    printf("\t3-quitter \n");
    choiceUser = securityInputInt(1, 3);
    TakuzuGrid gameGrid = createGameTakuzuGrid(sizeGrid);
    switch (choiceUser) {
        case 1: {
            if (sizeGrid == 4) {
                printf("1010"
                       "0110"
                       "0011"
                       "1001"
                       "1100"
                       "0101");
            } else if (sizeGrid == 8) {
                printf("00101101"
                       "00110011"
                       "00110101"
                       "00110110"
                       "01001011"
                       "01001101"
                       "01010011"
                       "01010101"
                       "01010110"
                       "01011001"
                       "01011010"
                       "01100101"
                       "01100110"
                       "01101001"
                       "01101010"
                       "10010011"
                       "10010101"
                       "10010110"
                       "10011010"
                       "10100101"
                       "10100110"
                       "10101001"
                       "10101010"
                       "10101100"
                       "10110010"
                       "10110100"
                       "11001001"
                       "11001010"
                       "11001100"
                       "11010010"
                       "11010100");
            }else{
                printf("valeur non prise en compte");
            }
        }
        case 2: {
            TakuzuGrid newGrid = createTakuzu(sizeGrid);
            fillMatrix(newGrid.matrice, newGrid.size);
            int counter = 0, canAMoveBePlay = 1;
            char timeBetween2Move = 'f';
            printMatriceWithMask(gameGrid, mask);
            while (canAMoveBePlay == 1) {
                canAMoveBePlay = forceMove(userGrid);
                scanf("%c", &timeBetween2Move);
                printUserMatrice(userGrid);
            }
            break;
        }
    }


}