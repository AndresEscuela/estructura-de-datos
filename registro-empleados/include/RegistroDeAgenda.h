#pragma once

struct RegistroDeAgenda
{
    char RFC[11];
    char nombre[31];
    char telefono[11];
    char correo[31];

    void registrarDatos();
    void imprimirRegistro();
};
