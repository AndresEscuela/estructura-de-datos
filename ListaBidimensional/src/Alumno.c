#include <stdio.h>
#include <string.h>
#include "../Empleado.h"
#include "../ListaSimple.h"

void imprimirAlumno(Alumno* alumno)
{
    printf("\nNumero De Alumno: %i", alumno->numCuenta);
    printf("\nNombre: %s", alumno->nombre);
    printf("\nPromedio: %f", alumno->promedio);
}
