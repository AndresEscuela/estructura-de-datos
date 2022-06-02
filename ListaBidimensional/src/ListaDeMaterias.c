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
    NodoListaMaterias* nodoActual = list->root;
    NodoListaMaterias* NodoAnterior = NULL;
    if(!materiasEstaVacia(list))
    {
        while(nodoActual != NULL && nodoActual->elemento.idMateria != idMateria)
        {
            NodoAnterior = nodoActual;
            nodoActual = nodoActual->siguienteNodo;
        }
        if(nodoActual != NULL && NodoAnterior != NULL)
        {
            NodoAnterior->siguienteNodo = nodoActual->siguienteNodo;
            free(nodoActual);
        }
        if(nodoActual != NULL)
            list->root = nodoActual->siguienteNodo;
        else
            printf("\nNo se encontro el id de Materia: %i", idMateria);
    }
    else
        printf("La lista esta vacia, no hay nada que eliminar");
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
