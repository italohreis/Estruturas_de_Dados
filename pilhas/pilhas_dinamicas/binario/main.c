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

void binary(Stack *stack, int numero) {

    int resto;
    while (numero > 0) { 
        resto = numero % 2;
        numero = numero / 2;
        
        Stack_push(stack, resto);
    }
}

int main() {

    Stack *stack = Stack_create();

    int numero;

    scanf("%d", &numero);

    binary(stack, numero);
    print(stack);
    
    return 0;
}