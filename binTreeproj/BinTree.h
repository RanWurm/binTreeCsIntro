#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <stdio.h>
#include <stdlib.h>

#define START_AGE -5

#define GERSHON "Gershon"
#define KEHAT "Kehat"
#define MERARI "Merari"

#define GERSHON_PART "wraps."
#define KEHAT_PART "the best important."
#define MERARI_PART "conectors."

typedef enum {Gershon, Kehat, Merari} Levi;

typedef void (*GenericFunc)(void *);

typedef struct BinTree BinTree;


void generic_function(BinTree* root, GenericFunc task);

void newLeviIsBorn(BinTree** youngsTree);
void removeLevi(BinTree* youngsTree, BinTree** workingTree);
void sendToWork(BinTree* workingTree);
void printBothTrees(BinTree *workingTree, BinTree *youngsTree);
void countLevis(BinTree* youngsTree, BinTree* workingTree);
void clearTree(BinTree* root);

void addAndTransfer(BinTree** youngsTree, BinTree** workingTree);

#endif // BIN_TREE_H