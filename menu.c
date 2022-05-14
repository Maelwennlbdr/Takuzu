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
                printf("\tDans cette partie pour que le programme joue un nouveau coup, appuyer sur une touche.\n");
                int size;
                size = securityInputSize();
                menuPartII(size);
                break;
            }
            case 3: {
                printf("Part III-\n");
                printf("\tFonction non existante pour le moment.\n");
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
    while ((!validityCompleteGrid(userGrid)) && (!isGridComplete(userGrid))) {
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
