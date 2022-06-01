#include <stdlib.h>
#include <stdio.h>
#include "../ListaDeMaterias.h"

bool materiasEstaVacia(ListaDeMaterias* list)
{
    return (list->root == NULL) ? true : false;
}
void pushBack(ListaDeMaterias* list, Materia materia)
{
    NodoListaMaterias* nuevoNodo = (NodoListaMaterias*)malloc(sizeof(NodoListaMaterias));
    nuevoNodo->elemento = materia;
    nuevoNodo->siguienteNodo = NULL;
    if(!materiasEstaVacia(list))
    {
        NodoListaMaterias* nodoActual = list->root;
        while(nodoActual->siguienteNodo)
            nodoActual = nodoActual->siguienteNodo;
        nodoActual->siguienteNodo = nuevoNodo;
    }
    else
        list->root = nuevoNodo;
}
void eliminarMateria(ListaDeMaterias* list, int idMateria)
{

}
void imprimirMaterias(ListaDeMaterias* list)
{
    if(!materiasEstaVacia(list))
    {
        NodoListaMaterias* nodoActual = list->root;
        while(nodoActual)
        {
            printf("\n");
            imprimirInfoMateria(&nodoActual->elemento);
            nodoActual = nodoActual->siguienteNodo;
        }
    }
    else
        printf("\nLa lista esta vacia, no hay nodos que imprimir");

}
