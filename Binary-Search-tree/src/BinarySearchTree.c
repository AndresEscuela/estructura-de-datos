#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/BinarySearchTree.h"
#include "../include/BST_Node.h"

BinarySearchTree* getInitializedBST()
{
    BinarySearchTree* newBST = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    newBST->ptr_root = NULL;
    return newBST;
}
bool isTreeEmpty(BinarySearchTree* BST)
{
    return ( BST->ptr_root == NULL ) ? true : false;
}
BST_Node* getPtr_ToElement(BinarySearchTree* BST, int elemento)
{
    BST_Node* nodoActual = BST->ptr_root;
    while(nodoActual && nodoActual->element != elemento)
    {
        if(elemento > nodoActual->element)
            nodoActual = nodoActual->ptr_rigthNode;
        else
            nodoActual = nodoActual->ptr_leftNode;
    }
    return nodoActual;
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
BST_Node* get_susesorEnOrden(BST_Node* subArbol)
{
    BST_Node* nodoActual = subArbol->ptr_leftNode;
    while(nodoActual && nodoActual->ptr_leftNode)
        nodoActual = nodoActual->ptr_leftNode;
    return nodoActual;
}
BST_Node* eliminarElemento(BST_Node* raiz, int elemento)
{
    if(raiz)
    {
        if(elemento > raiz->element)
            raiz->ptr_rigthNode = eliminarElemento(raiz->ptr_rigthNode, elemento);
        else if(elemento < raiz->element)
            raiz->ptr_leftNode = eliminarElemento(raiz->ptr_leftNode, elemento);
        else
        {
            if(raiz->ptr_leftNode == NULL)
            {
                BST_Node* subArbol = raiz->ptr_rigthNode;
                free(raiz);
                return subArbol;
            }
            else if(raiz->ptr_rigthNode == NULL)
            {
                BST_Node* subArbol = raiz->ptr_leftNode;
                free(raiz);
                return subArbol;
            }
            BST_Node* susesorEnOrden = get_susesorEnOrden(raiz->ptr_rigthNode);
            raiz->element = susesorEnOrden->element;
            raiz->ptr_rigthNode = eliminarElemento(raiz->ptr_rigthNode, susesorEnOrden->element);
        }
    }
    else
        return raiz;
}/*
void removeElement(BinarySearchTree* BST, int elemento)
{
    if(!isTreeEmpty(BST))
    {
        BST_Node** nodoActual = &BST->ptr_root;
        //BST_Node** nodoPadre = NULL;
        while(*nodoActual && (*nodoActual)->element != elemento)
        {
            //nodoPadre = nodoActual;
            if(elemento > (*nodoActual)->element)
                nodoActual = &( (*nodoActual)->ptr_rigthNode );
            else
                nodoActual = &( (*nodoActual)->ptr_leftNode );
        }
        if(*nodoActual)
        {
            if((*nodoActual)->ptr_leftNode && (*nodoActual)->ptr_rigthNode)
            {
                BST_Node** padreSusesorEnOrden = &( (*nodoActual)->ptr_rigthNode );
                while( (*padreSusesorEnOrden)->ptr_leftNode->ptr_leftNode )
                    padreSusesorEnOrden = &( (*padreSusesorEnOrden)->ptr_leftNode->ptr_leftNode );
                BST_Node* nodoSuelto;
                if((*nodoActual)->ptr_rigthNode != *padreSusesorEnOrden)
                {
                    (*nodoActual)->element = (*padreSusesorEnOrden)->ptr_leftNode->element;
                    nodoSuelto = (*padreSusesorEnOrden)->ptr_leftNode;
                    (*padreSusesorEnOrden)->ptr_leftNode = (*padreSusesorEnOrden)->ptr_leftNode->ptr_rigthNode;
                }
                else
                {
                    nodoSuelto = (*nodoActual)->ptr_rigthNode;
                    *nodoActual = (*nodoActual)->ptr_rigthNode;
                }
                free(nodoSuelto);
            }
            else if((*nodoActual)->ptr_leftNode)
            {
                BST_Node* nodoAEliminar = *nodoActual;
                *nodoActual = (*nodoActual)->ptr_leftNode;
                free(nodoAEliminar);
            }
            else if((*nodoActual)->ptr_rigthNode)
            {
                BST_Node* nodoAEliminar = *nodoActual;
                *nodoActual = (*nodoActual)->ptr_rigthNode;
                free(nodoAEliminar);
            }
            else
            {
                free(*nodoActual);
                *nodoActual = NULL;
            }
        }
        else
            printf("\nEl elemento: %i, NO se pudo encontrar en el arbol", elemento);
    }
    else
        printf("\nEl arbol esta vacio, no hay nada que eliminar");
}*/
bool isElementInTree(BinarySearchTree* BST, int elemento)
{
    if(!isTreeEmpty(BST))
    {
        if(getPtr_ToElement(BST, elemento))
            return true;
        else
            return false;
    }
    else
        printf("\nEl arbol esta vacio, no hay nada que buscar");
    return false;
}
void printPreOrder(BinarySearchTree* BST)
{
    if(!isTreeEmpty(BST))
        imprimirSubArbolPreOrden(BST->ptr_root);
    else
        printf("\nEl arbol esta vacio, no hay nada que imprimir");
}
void imprimirSubArbolPreOrden(BST_Node* raiz)
{
    printf("%i, ", raiz->element);
    if(raiz->ptr_leftNode)
        imprimirSubArbolPreOrden(raiz->ptr_leftNode);
    if(raiz->ptr_rigthNode)
       imprimirSubArbolPreOrden(raiz->ptr_rigthNode);
}
void printInOrder(BinarySearchTree* BST)
{
    if(!isTreeEmpty(BST))
        imprimirTodoEnOrden(BST->ptr_root);
    else
        printf("\nEl arbol esta vacio, no hay nada que imprimir");
}
void imprimirTodoEnOrden(BST_Node* raiz)
{
    if(raiz->ptr_leftNode)
        imprimirTodoEnOrden(raiz->ptr_leftNode);
    printf("%i, ", raiz->element);
    if(raiz->ptr_rigthNode)
       imprimirTodoEnOrden(raiz->ptr_rigthNode);
}
void printPostOrder(BinarySearchTree* BST)
{
    if(!isTreeEmpty(BST))
        imprimirSubArbolPostOrden(BST->ptr_root);
    else
        printf("\nEl arbol esta vacio, no hay nada que imprimir");
}
void imprimirSubArbolPostOrden(BST_Node* raiz)
{
    if(raiz->ptr_leftNode)
        imprimirSubArbolPostOrden(raiz->ptr_leftNode);
    if(raiz->ptr_rigthNode)
        imprimirSubArbolPostOrden(raiz->ptr_rigthNode);
    printf("%i, ", raiz->element);
}
void destroyBST(BinarySearchTree* BST)
{
    if(!isTreeEmpty(BST))
    {
        destruirSubArbol(BST->ptr_root);
    }
    free(BST);
}
void destruirSubArbol(BST_Node* raiz)
{
    if(raiz)
    {
        if(raiz->ptr_leftNode)
            destruirSubArbol(raiz->ptr_leftNode);
        if(raiz->ptr_rigthNode)
            destruirSubArbol(raiz->ptr_rigthNode);
        free(raiz);
    }
}
