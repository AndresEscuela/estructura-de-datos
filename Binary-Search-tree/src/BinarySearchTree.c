#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
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
BST_Node* getPtr_ToElement(BinarySearchTree* BST, int elemento)
{

}
void addNode(BinarySearchTree* BST, int elemento)
{
    BST_Node* nuevoNodo = getPtr_InitializedNode(elemento);
    if(!isTreeEmpty(BST))
    {
        BST_Node* nodoPadre = NULL;
        BST_Node* nodoActual = BST->ptr_root;
        while(nodoActual)
        {
            nodoPadre = nodoActual;
            if(elemento >= nodoActual->element)
                nodoActual = nodoActual->ptr_rigthNode;
            else
                nodoActual = nodoActual->ptr_leftNode;
        }
        if(elemento >= nodoPadre->element)
            nodoPadre->ptr_rigthNode = nuevoNodo;
        else
            nodoPadre->ptr_leftNode = nuevoNodo;
    }
    else
        BST->ptr_root = nuevoNodo;
}
void removeElement(BinarySearchTree* BST, int elemento)
{

}
bool isElementInTree(BinarySearchTree* BST, int elemento)
{

}
void printPreOrder(BinarySearchTree* BST)
{

}
void printInOrder(BinarySearchTree* BST)
{
    if(!isTreeEmpty(BST))
    {
        imprimirTodoEnOrden(BST->ptr_root);
    }
    else
        printf("\nEl arbol esta vacio, no hay nada que imprimir");
}
void imprimirTodoEnOrden(BST_Node* nodoActual)
{
    if(nodoActual->ptr_leftNode)
        imprimirTodoEnOrden(nodoActual->ptr_leftNode);
    printf("%i, ", nodoActual->element);
    if(nodoActual->ptr_rigthNode)
       imprimirTodoEnOrden(nodoActual->ptr_rigthNode);
}
void printPostOrder(BinarySearchTree* BST)
{

}
void destroyBST(BinarySearchTree* BST)
{

}
