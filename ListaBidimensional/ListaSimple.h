#pragma once
#include <stdbool.h>
#include "Empleado.h"
#include "ListaDeMaterias.h"

typedef struct nodoListaSimple
{
    Alumno elemento;
    struct nodoListaSimple* siguienteNodo;
    ListaDeMaterias* materias;
} nodoLista;

typedef struct ListaSimplementeEnlazada
{
    nodoLista* root;
} ListaSimple;


bool estaVacia(ListaSimple*);
void pushFront(ListaSimple*, Alumno, ListaDeMaterias*);
void eliminar(ListaSimple*, int);
void imprimir(ListaSimple*);
