#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"
#include "ListaDeMaterias.h"
#include "Empleado.h"

int main()
{
    ListaDeMaterias misMaterias;
    misMaterias.root = NULL;
    Materia dbAndres = {1, {'B', 'a', 's', 'e', 's', 'D', '\0'}, {9.0, 9.0, 10} };
    Materia mateAndres = {2, {'M', 'a', 't', 'e', 's', '(', '\0'}, {9.5, 9.5, 4.5} };
    Materia disenoAndres = {2, {'D', 'i', 's', 'e', 'n', 'o', '\0'}, {8.5, 8.5, 8} };
    pushBack(&misMaterias, dbAndres);
    pushBack(&misMaterias, mateAndres);
    pushBack(&misMaterias, disenoAndres);

    imprimirMaterias(&misMaterias);

    /*
    ListaSimple miLista;
    miLista.root = NULL;
    Alumno andres = {123, {'A', 'n', 'd', 'r', 'e', 's', '\0'}, 9.0};
    Alumno paul = {246, {'P', 'a', 'u', 'l', '\0'}, 8.5};
    Alumno roa = {567, {'R', 'o', 'a', '1', '\0'}, 9.5};
    pushFront(&miLista, andres);
    pushFront(&miLista, paul);
    pushFront(&miLista, roa);
    imprimir(&miLista);
    printf("\n");
    printf("\n--------------Elimino Paul------------");
    eliminar(&miLista, 246);
    imprimir(&miLista);
    printf("\n--------------Elimino Paul 2------------");
    pushFront(&miLista, paul);
    eliminar(&miLista, 246);
    imprimir(&miLista);
    printf("\n--------------Elimino Andres------------");
    eliminar(&miLista, 123);
    imprimir(&miLista);
    printf("\n--------------Elimino Andres 2------------");
    eliminar(&miLista, 123);
    imprimir(&miLista);
    printf("\n--------------Elimino Roa------------");
    eliminar(&miLista, 567);
    pushFront(&miLista, paul);
    imprimir(&miLista);
    printf("\n");
    */
    return 0;
}
