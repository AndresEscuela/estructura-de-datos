#include <stdio.h>
#include <stdlib.h>
#include "../ListaSimple.h"
#include "../Empleado.h"
#include "../Materia.h"

bool estaVacia(ListaSimple* list)
{
    return (list->root == NULL) ? true : false;
}
void pushFront(ListaSimple* list, Alumno alumno, ListaDeMaterias* materiasDelAlumno)
{
    nodoLista* primerNodo = list->root;
    list->root = (nodoLista*)malloc(sizeof(nodoLista));
    list->root->elemento = alumno;
    list->root->siguienteNodo = primerNodo;
    list->root->materias = materiasDelAlumno;
}
void eliminar(ListaSimple* list, int numCuenta)
{
    if(!estaVacia(list))
    {
        nodoLista* nodoActual = list->root;
        nodoLista* nodoAnterior = NULL;
        int numCuentaActual = nodoActual->elemento.numCuenta;
        while(nodoActual && numCuentaActual != numCuenta)
        {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->siguienteNodo;
            if(nodoActual)
                numCuentaActual = nodoActual->elemento.numCuenta;
        }
        if(nodoActual != NULL && nodoAnterior != NULL)
        {
            nodoAnterior->siguienteNodo = nodoActual->siguienteNodo;
            free(nodoActual);
        }
        else if(nodoActual != NULL)
            list->root = nodoActual->siguienteNodo;
        else
            printf("\nNo se encontro el numero de cuenta %i", numCuenta);
    }
    else
        printf("\nLa lista esta vacia, Nada que eliminar");
}
void imprimir(ListaSimple* list)
{
    nodoLista* nodoActual = list->root;
    while(nodoActual)
    {
        printf("\n");
        imprimirAlumno(&nodoActual->elemento);
        nodoActual = nodoActual->siguienteNodo;
    }
    if(estaVacia(list))
        printf("\nLa lista esta vacia, no hay ningun elemento que imprimir");
}
