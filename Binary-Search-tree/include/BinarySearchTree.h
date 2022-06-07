#pragma once
#include <stdbool.h>
#include "../include/BST_Node.h"

typedef struct BinarySearchTreeStructure
{
    BST_Node* ptr_root;
} BinarySearchTree;

BinarySearchTree getInitializedBST();
bool isTreeEmpty(BinarySearchTree*);
BST_Node* getPtr_ToElement(BinarySearchTree*, int);
void addNode(BinarySearchTree*, int);
void removeElement(BinarySearchTree*, int);
bool isElementInTree(BinarySearchTree*, int);
void printPreOrder(BinarySearchTree*);
void printInOrder(BinarySearchTree*);
void printPostOrder(BinarySearchTree*);
void destroyBST(BinarySearchTree*);

