#include "../include/BST_Node.h"
#include <stdlib.h>

BST_Node* getPtr_InitializedNode(int element)
{
    BST_Node* newNode = (BST_Node*) malloc(sizeof(BST_Node));
    newNode->element = element;
    newNode->ptr_leftNode = NULL;
    newNode->ptr_rigthNode= NULL;
    return newNode;
}
