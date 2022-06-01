#include <stdio.h>
#include "../Materia.h"

void imprimirInfoMateria(Materia* materia)
{
    printf("\nNombre: %s", materia->nombre);
    for(int i = 0; i < 3; i++)
        printf("\nParcial %i: %f", i, materia->calificacion[i]);
}
