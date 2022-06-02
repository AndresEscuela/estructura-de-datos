#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ListaSimple.h"
#include "../Empleado.h"
#include "../Materia.h"

bool estaVacia(ListaSimple* list)
{
    return (list->root == NULL) ? true : false;
}
void pushFront(ListaSimple* list, Alumno alumno)
{
    nodoLista* primerNodo = list->root;
    list->root = (nodoLista*)malloc(sizeof(nodoLista));
    list->root->elemento = alumno;
    list->root->siguienteNodo = primerNodo;
    list->root->materias = (ListaDeMaterias*)malloc(sizeof(ListaDeMaterias));
    list->root->materias->root = NULL;
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
        printf("\n__________________________________________________________________");
        imprimirAlumno(&nodoActual->elemento);
        printf("\nMaterias: ");
        imprimirMaterias(nodoActual->materias);
        nodoActual = nodoActual->siguienteNodo;
        printf("\n__________________________________________________________________");
    }
    if(estaVacia(list))
        printf("\nLa lista esta vacia, no hay ningun elemento que imprimir");
}

void agregarMateriaAAlumno(ListaSimple* list, char nombreAlumno[31], Materia nuevaMateria)
{
    if(!estaVacia(list))
    {
        nodoLista* nodoActual = list->root;
        while(nodoActual && strcmp(nodoActual->elemento.nombre, nombreAlumno) != 0)
            nodoActual = nodoActual->siguienteNodo;
        if(nodoActual)
            pushBack(nodoActual->materias, nuevaMateria);
        else
            printf("\nNo se encontro el alumno: %s", nombreAlumno);
    }
    else
        printf("\nLa lista esta vacia, no hay ningun alumno para asignarle la materia");
}
