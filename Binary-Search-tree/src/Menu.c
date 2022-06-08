#include <stdio.h>
#include "../include/Menu.h"
#include "../include/BinarySearchTree.h"

void initMenu()
{
    BinarySearchTree myBST = getInitializedBST();
    while(1 == 1)
    {
        printOptions();
        processInput(&myBST);
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
void processInput(BinarySearchTree* myBST)
{
    int input;
    scanf("%i", &input);
    switch(input)
    {
    case 1:
        printf("\nEscribe el elemento: ");
        int elemento;
        scanf("%i", &elemento);
        addNode(myBST, elemento);
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        printInOrder(myBST);
        break;
    case 6:

        break;
    case 0:

        break;
    default:
        printf("\nSeleccione una opcion valida");
    }
}
