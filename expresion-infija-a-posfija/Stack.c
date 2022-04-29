#include <stdio.h>
#include "Stack.h"

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
    return ' ';
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
