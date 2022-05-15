#include "menu.h"

int allmenu() {
    int choiceUser;
    do {
        printf("Fait votre choix :\n");
        printf("\t1- Résoudre une grille manuellement\n");
        printf("\t2- Résolution automatique d'une grille\n");
        printf("\t3- Génération d'une grille\n");
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
                printf("\tDans cette partie pour que le programme joue un nouveau coup, appuyer sur entrée.\n");
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
    } while (choiceUser != 4);
    return 0;
}

int menuPartI(int sizeGrid) {
    int choiceUser;
    do {

        printf("Fait votre choix :\n");
        printf("\t1- Saisir manuellement un masque\n");
        printf("\t2- Générer automatiquement un masque\n");
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
                do {
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
                } while ((life < 3) && (!isMatriceFull(userGrid)));
                break;
            }
        }
    } while (choiceUser != 4);
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
    do {
        printf("\nFait votre choix :\n");
        printf("\t1- Afficher l'ensemble des lignes valides\n");
        printf("\t2- Generer une grille de Takuzu \n");
        printf("\t3- Quitter \n");
        choiceUser = securityInputInt(1, 3);
        switch (choiceUser) {
            case 1: {
                if (sizeGrid == 4) {
                    printf("1010\n"
                           "0110\n"
                           "0011\n"
                           "1001\n"
                           "1100\n"
                           "0101\n");
                } else if (sizeGrid == 8) {
                    printf("00101101\n"
                           "00110011\n"
                           "00110101\n"
                           "00110110\n"
                           "01001011\n"
                           "01001101\n"
                           "01010011\n"
                           "01010101\n"
                           "01010110\n"
                           "01011001\n"
                           "01011010\n"
                           "01100101\n"
                           "01100110\n"
                           "01101001\n"
                           "01101010\n"
                           "10010011\n"
                           "10010101\n"
                           "10010110\n"
                           "10011010\n"
                           "10100101\n"
                           "10100110\n"
                           "10101001\n"
                           "10101010\n"
                           "10101100\n"
                           "10110010\n"
                           "10110100\n"
                           "11001001\n"
                           "11001010\n"
                           "11001100\n"
                           "11010010\n"
                           "11010100\n");
                } else {
                    printf("Valeur non prise en compte.\n");
                }
                break;
            }
            case 2: {
                TakuzuGrid newGrid = createTakuzu(sizeGrid);
                fillMatrix(newGrid.matrice, newGrid.size);
                int canAMoveBePlay = 1;
                char timeBetween2Move = ' ';
                ChainOfMove *list = NULL;
                while ((!validityCompleteGrid(newGrid)) && (!isMatriceFull(newGrid))) {
                    do {
                        while (canAMoveBePlay == 1) {
                            canAMoveBePlay = forceMove(newGrid, &list);
                            scanf("%c", &timeBetween2Move);
                            if (canAMoveBePlay == 1) {
                                printUserMatrice(newGrid);
                            }
                        }
                        canAMoveBePlay = 1;
                        if (!validityGrid(newGrid)) {
                            list = returnToLastRandomMove(list, newGrid);
                        }

                        if (!isMatriceFull(newGrid)) {
                            randomMove(newGrid, &list);
                            printUserMatrice(newGrid);
                        }
                        if (!validityGrid(newGrid)) {
                            list = returnToLastRandomMove(list, newGrid);
                        }
                    } while (!isMatriceFull(newGrid));

                    if (!validityCompleteGrid(newGrid)) {
                        printf("La matrice n'est pas correct\n");
                        list = returnToLastRandomMove(list, newGrid);
                        printUserMatrice(newGrid);
                    } else {
                        printf("Voila, cette matrice est correcte.\n");
                    }
                }
                break;
            }
        }
    } while (choiceUser != 3);
}