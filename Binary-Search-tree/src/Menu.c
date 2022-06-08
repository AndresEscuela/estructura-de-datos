#include <stdio.h>
#include "../include/Menu.h"
#include "../include/BinarySearchTree.h"

void initMenu()
{
    BinarySearchTree* myBST = getInitializedBST();
    int input = 1;
    while(input != 0)
    {
        printOptions();
        scanf("%i", &input);
        processInput(myBST, input);
    }
}
void printOptions()
{
    printf("\n________________________________________________________");
    printf("\nSelecciona una opcion");
    printf("\n1. Agregar un Nodo");
    printf("\n2. Buscar un Elemento");
    printf("\n3. Eliminar un Nodo");
    printf("\n4. Imprimir Pre Order");
    printf("\n5. Imprimir In Order");
    printf("\n6. Imprimir Post Order");
    printf("\n0. Salir\n:");
}
void processInput(BinarySearchTree* myBST, int input)
{
    switch(input)
    {
    case 1:
        printf("\nEscribe el elemento: ");
        int elemento;
        scanf("%i", &elemento);
        addNode(myBST, elemento);
        break;
    case 2:
        printf("\nEscribe el elemento: ");
        scanf("%i", &elemento);
        if(isElementInTree(myBST, elemento))
            printf("\nEl elemento: %i, se encontro en el arbol", elemento);
        else
            printf("\nEl elemento: %i, NO se pudo encontrar en el arbol", elemento);
        break;
    case 3:
        if(!isTreeEmpty(myBST))
        {
            printf("\nEscribe el elemento: ");
            scanf("%i", &elemento);
            myBST->ptr_root = eliminarElemento(myBST->ptr_root, elemento);
        }
        else
            printf("El arbol esta vacio, no hay nada por eliminar");
        break;
    case 4:
        printPreOrder(myBST);
        break;
    case 5:
        printInOrder(myBST);
        break;
    case 6:
        printPostOrder(myBST);
        break;
    case 0:
        destroyBST(myBST);
        break;
    default:
        printf("\nSeleccione una opcion valida");
    }
}
