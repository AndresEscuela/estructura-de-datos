#include "RegistroDeAgenda.h"

void RegistroDeAgenda::registrarDatos()
{
    printf("Escribe el RFC: ");
    gets(agenda[i].RFC);
    printf("Escribe el Nombre: ");
    gets(agenda[i].nombre);
    printf("Escribe el telefono: ");
    gets(agenda[i].telefono);
    printf("Escribe el Correo: ");
    gets(agenda[i].correo);
}
void RegistroDeAgenda::imprimirRegistro()
{
    printf("%d. RFC: %s\n", i, agenda[i].RFC);
    printf("%d. Nombre: %s\n", i, agenda[i].nombre);
    printf("%d. Telefono: %s\n", i, agenda[i].telefono);
    printf("%d. Correo: %s\n", i, agenda[i].correo);
    printf("_________________________________________\n");
}
