#include <stdio.h>
#include <stdlib.h>
#include "RegistroDeAgenda.h"

// Ordenamiento por el metodo de la burbuja
int main()
{
    const int numeroDeRegistros = 2;
    struct RegistroDeAgenda agenda[numeroDeRegistros];
    for(int i = 0; i < numeroDeRegistros; i++)
        agenda[i].registrarDatos();
    for(int i = 0; i < numeroDeRegistros; i++)
        agenda[i].imprimirRegistro();
}
