#include <stdio.h>
#include <stdbool.h>

// Stack(Pila)
struct Stack
{
    // Tope
    int top;
    // largo
    const int length;
    char elements[25];
};
struct Stack stackInicializado();
void push(struct Stack* stack, char elemento);
char pop(struct Stack* stack);
void popToArrayUntilElement(struct Stack* stack, char arreglo[], char elemento);
void popAll(struct Stack* stack, char arreglo[]);
bool isStackFull(struct Stack* stack);
bool isStackEmpty(struct Stack* stack);
int obtenerGerarquia(char operador);
char* infijaAPosfija(char expresionInfija[]);

int main()
{
    char expresion[15] = {'(', '(', '5', '+', '5', ')','*', '2', '/', '2',  ')',  '^',  '2', '\0'};
    printf("\n%s", infijaAPosfija(expresion));
}
struct Stack stackInicializado()
{
    struct Stack stack = {-1, 25};
    return stack;
}
void push(struct Stack* stack, char elemento)
{
    if(!isStackFull(stack))
        stack->elements[++stack->top] = elemento;
    else
        printf("\nStack Lleno");
}
char pop(struct Stack* stack)
{
    if(!isStackEmpty(stack))
        return stack->elements[stack->top--];
    else
        printf("\nStack Vacio");
}
void popToArrayUntilElement(struct Stack* stack, char arreglo[], char elemento)
{
    int i = 0;
    while(!isStackEmpty(stack) && stack->elements[stack->top] != elemento)
    {
        arreglo[i] = stack->elements[stack->top--];
        i++;
    }
    arreglo[++i] = '\0';
    if(!isStackEmpty(stack))
        stack->top--;
}
void popAll(struct Stack* stack, char arreglo[])
{
    int i = 0;
    while(!isStackEmpty(stack))
    {
        arreglo[i++] = stack->elements[stack->top--];
    }
    arreglo[i] = '\0';
}
bool isStackFull(struct Stack* stack)
{
    return (stack->top >= stack->length-1) ? true : false;
}
bool isStackEmpty(struct Stack* stack)
{
    return (stack->top == -1) ? true : false;
}
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
            //printf("\nstackDeOperaciones.top: %c", stackDeOperaciones.top);
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
