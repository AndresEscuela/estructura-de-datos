#include <stdio.h>
#include <stdbool.h>
#include "expresiones.h"

int main()
{
    char expresion[15] = {'(', '(', '5', '+', '5', ')','*', '2', '/', '2',  ')',  '^',  '2', '\0'};
    printf("\n%s", infijaAPosfija(expresion));
}


