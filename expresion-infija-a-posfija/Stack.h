#pragma once
#include <stdbool.h>

struct Stack
{
    int top;
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
