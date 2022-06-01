#pragma once
#include "Materia.h"
#include <stdbool.h>

typedef struct nodoListaSimpleMaterias
{
    Materia elemento;
    struct nodoListaSimpleMaterias* siguienteNodo;
} NodoListaMaterias;

typedef struct ListaSimpleDeMaterias
{
    NodoListaMaterias* root;
} ListaDeMaterias;

bool materiasEstaVacia(ListaDeMaterias*);
void pushBack(ListaDeMaterias*, Materia);
void eliminarMateria(ListaDeMaterias*, int);
void imprimirMaterias(ListaDeMaterias*);

