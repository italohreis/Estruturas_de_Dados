#include <stdio.h>
#include "Stack.h"
#include <string.h>
#include <stdbool.h>

void inverte(Stack *stack) {
    Stack *aux1  = Stack_create(Stack_size(stack));
    Stack *aux2  = Stack_create(Stack_size(stack));

    char value;

    while (!Stack_is_empty(stack)) {
        Stack_pop(stack, &value);
    	Stack_push(aux1, value);
    }

    while (!Stack_is_empty(aux1)) {
        Stack_pop(aux1, &value);
    	Stack_push(aux2, value);
    }

    while (!Stack_is_empty(aux2)) {
        Stack_pop(aux2, &value);
    	Stack_push(stack, value);
    }
}

void print(Stack *stack) {
    char value;
    while (!Stack_is_empty(stack)) {
        Stack_pop(stack, &value);
        printf("%c", value);
    }
    printf("\n");
}

int main() {

    char c[250];
    
    scanf("%s", c);

    Stack *stack = Stack_create(strlen(c));

    int i;
    for (i = 0; i < strlen(c); i++) {
        Stack_push(stack, c[i]);
    }
    
    inverte(stack);

    print(stack);

    return 0;
}