#include <stdio.h>
#include "BinTree.h"

void printMenu() {
printf("please choose action:\n"
       "(1) Add Levi\n"
       "(2) Remove Levi\n"
       "(3) Task All\n"
       "(4) Print All\n"
       "(5) Size of Levi family\n"
       "(6) Exit\n");
}

int main() {

    BinTree *youngsTree = NULL;
    BinTree *workingTree = NULL;

    int choose = 0;

    while (choose != 6) {
        printMenu();
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                newLeviIsBorn(&youngsTree);
                break;
            case 2:
                removeLevi(youngsTree, &workingTree);
                break;
            case 3:
                sendToWork(workingTree);
                break;
            case 4:
                printBothTrees(workingTree, youngsTree);
                break;
            case 5:
                countLevis(youngsTree, workingTree);
                break;
            case 6:
                clearTree(youngsTree);
                clearTree(workingTree);
                break;
            default:
                printf("wrong choose please choose again.\n");
                break;
        }
        if (choose != 6) {
            addAndTransfer(&youngsTree, &workingTree);
            printf("\n");
        }
    }
    return 0;
}
