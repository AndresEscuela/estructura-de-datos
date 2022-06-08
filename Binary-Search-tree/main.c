#include <stdio.h>
#include <stdlib.h>
#include "include/Menu.h"
#include "BST_Node.h"
#include "BinarySearchTree.h"

int main()
{
    initMenu();

    return 0;
}

/*
    BST_Node* newNode = getPtr_InitializedNode(10);
    BinarySearchTree myTree = {NULL};
    BinarySearchTree* BST = &myTree;
    BST_Node** currentNode = &(BST->ptr_root);
    while(currentNode)
    {
        printf("Entro al while");
        break;
    }
    *currentNode = newNode;

    printf("\n%i", myTree.ptr_root->element);
    */
