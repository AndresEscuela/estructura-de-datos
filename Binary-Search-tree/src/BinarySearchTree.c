#include <stdlib.h>
#include <stdbool.h>
#include "../include/BinarySearchTree.h"
#include "../include/BST_Node.h"

BinarySearchTree getInitializedBST()
{
    BinarySearchTree newBST;
    newBST.ptr_root = NULL;
    return newBST;
}
bool isTreeEmpty(BinarySearchTree* BST)
{
    return ( BST->ptr_root == NULL ) ? true : false;
}
BST_Node* getPtr_ToElement(BinarySearchTree* BST, int element)
{

}
void addNode(BinarySearchTree* BST, int element)
{
    if(!isTreeEmpty())
    {
        BST_Node* newNode =
    }
}
void removeElement(BinarySearchTree* BST, int element)
{

}
bool isElementInTree(BinarySearchTree* BST, int element)
{

}
void printPreOrder(BinarySearchTree* BST)
{

}
void printInOrder(BinarySearchTree* BST)
{

}
void printPostOrder(BinarySearchTree* BST)
{

}
void destroyBST(BinarySearchTree* BST)
{

}
