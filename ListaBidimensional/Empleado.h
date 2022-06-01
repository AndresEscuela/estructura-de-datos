#pragma once

typedef struct AlumnoStructure
{
    int numCuenta;
    char nombre[31];
    float promedio;
} Alumno;

void imprimirAlumno(Alumno*);
