#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>


struct _stack {
    unsigned int size;
    int *data;
    unsigned int qty;  //quantidade, controle da pilha
};


Stack *Stack_create(unsigned int size) {

    Stack *stack = (Stack*) malloc(sizeof(Stack));

    stack->data = malloc(sizeof(int) * size);
    stack->size = size;
    stack->qty = 0;

    return stack; 
}

bool Stack_push(Stack *stack, int data) {

    if (!Stack_is_full(stack)) {
        stack->data[stack->qty++] = data;
        return true;
    }

    return false;
}

bool Stack_pop(Stack *stack, int *value) {

    if (!Stack_is_empty(stack)) {
        *value = stack->data[--stack->qty];

        return true;
    } 

    return false;
}

uint Stack_size(Stack *stack) {
    return stack->qty;
}

bool Stack_is_empty(Stack *stack) {
    return stack->qty == 0;
}

bool Stack_is_full(Stack *stack) {
    return stack->qty == stack->size;
}
