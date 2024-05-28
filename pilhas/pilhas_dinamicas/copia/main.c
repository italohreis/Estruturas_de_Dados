#include <stdio.h>
#include "Stack.h"
#include <string.h>

void print(Stack *stack) {
    Stack *aux = Stack_create();
    int value;

    while (!Stack_is_empty(stack)) {    //printa os elementos da pilha
        Stack_pop(stack, &value);
        Stack_push(aux, value);
        printf("%d, ", value);
    }

    while (!Stack_is_empty(aux)) {  //coloca os elementos de volta na pilha original
        Stack_pop(aux, &value);
        Stack_push(stack, value);
    }

    Stack_destroy(aux);
}

void Stack_copy(Stack *stack1, Stack *stack2) {
    Stack *aux1 = Stack_create();
    int value;

    while (!Stack_is_empty(stack1)) {
        Stack_pop(stack1, &value);
        Stack_push(aux1, value);
    }

    while (!Stack_is_empty(aux1)) {
        Stack_pop(aux1, &value);
        Stack_push(stack2, value);
        Stack_push(stack1, value);
    }
}

int main() {

    Stack *stack1 = Stack_create();
    Stack *stack2 = Stack_create();

    int i;
    for (i = 0; i <= 10; i++) {
        Stack_push(stack1, i+1);
    }  

    Stack_copy(stack1, stack2);

    print(stack1);
    printf("\n");
    print(stack2);

    Stack_destroy(stack1);

    return 0;
}