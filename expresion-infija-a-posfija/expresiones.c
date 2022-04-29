#include "expresiones.h"
#include "Stack.h"

int obtenerJerarquia(char operador)
{
    if(operador == '(' || operador == ')')
        return 4;
    if(operador == '^')
        return 3;
    else if(operador == '*' || operador == '/'|| operador == '%')
        return 2;
    else if(operador == '+' || operador == '-')
        return 1;
    else
        return 0;
}
char* infijaAPosfija(char expresionInfija[])
{
    static char expresionPosfija[26];
    struct Stack stackDeOperaciones = stackInicializado();
    int i = 0;
    int indicePosfija = 0;
    while(expresionInfija[i])
    {
        int jerarquiaDelOperador = obtenerJerarquia(expresionInfija[i]);
        if(jerarquiaDelOperador == 0)
            expresionPosfija[indicePosfija++] = expresionInfija[i];
        else if(stackDeOperaciones.elements[stackDeOperaciones.top] == '(' || isStackEmpty(&stackDeOperaciones))
        {
            push(&stackDeOperaciones, expresionInfija[i]);
        }
        else if(expresionInfija[i] == ')')
        {
            popToArrayUntilElement(&stackDeOperaciones, &expresionPosfija[indicePosfija], '(');
            while(expresionPosfija[++indicePosfija]) {}
            expresionPosfija[indicePosfija] = ' ';
        }
        else if(obtenerJerarquia(stackDeOperaciones.elements[stackDeOperaciones.top]) >= jerarquiaDelOperador)
        {
            expresionPosfija[indicePosfija++] = pop(&stackDeOperaciones);
            push(&stackDeOperaciones, expresionInfija[i]);
        }
        else
        {
            push(&stackDeOperaciones, expresionInfija[i]);
        }
        i++;
    }

    popAll(&stackDeOperaciones, &expresionPosfija[indicePosfija]);
    return expresionPosfija;
}
