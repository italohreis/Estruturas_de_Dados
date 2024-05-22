#include <stdio.h>
#include "Stack.h"
#include <string.h>

void limpa_e_imprime(Stack *stack) {
    while (!Stack_is_empty(stack)) {
        int c;
        Stack_pop(stack, &c);
        printf("%c", c);
    }
}

int main() {

    char *str = "ESSE EXERCICIO E MUITO FACIL.";
    
    Stack *stack = Stack_create(strlen(str));

    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '.') {
            limpa_e_imprime(stack);
            printf(" ");
        } else {
            Stack_push(stack, str[i]);
        }    
    }

    return 0;
}