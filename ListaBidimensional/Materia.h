#pragma once

typedef struct MateriaStructure
{
    int idMateria;
    char nombre[31];
    float calificacion[3];
} Materia;

void imprimirInfoMateria(Materia*);
