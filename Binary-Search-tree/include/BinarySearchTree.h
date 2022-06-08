#pragma once
#include <stdbool.h>
#include "../include/BST_Node.h"

typedef struct BinarySearchTreeStructure
{
    BST_Node* ptr_root;
} BinarySearchTree;

BinarySearchTree* getInitializedBST();
bool isTreeEmpty(BinarySearchTree*);
BST_Node* getPtr_ToElement(BinarySearchTree*, int);
void addNode(BinarySearchTree*, int);
BST_Node* get_susesorEnOrden(BST_Node* subArbol);
BST_Node* eliminarElemento(BST_Node*, int );
void removeElement(BinarySearchTree*, int);
bool isElementInTree(BinarySearchTree*, int);
void printPreOrder(BinarySearchTree*);
void imprimirSubArbolPreOrden(BST_Node*);
void printInOrder(BinarySearchTree*);
void imprimirTodoEnOrden(BST_Node*);
void printPostOrder(BinarySearchTree*);
void imprimirSubArbolPostOrden(BST_Node* raiz);
void destroyBST(BinarySearchTree*);
void destruirSubArbol(BST_Node*);
