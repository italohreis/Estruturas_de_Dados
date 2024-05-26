#include <stdio.h>
#include "Stack.h"
#include <string.h>

bool verificar_palindromo(Stack *stack, char *palavra) {
    int len = strlen(palavra);
    char value = 0;

    for (int i = 0; i < strlen(palavra); i++) {
        Stack_pop(stack, &value);
        if (value != palavra[i]) {
            return false;
        }
    }

    return true;
}

int main() {

    char *str = "bob";

    Stack *stack = Stack_create(100);
    int i;
    int aux = strlen(str);
    
    for (i = 0; i < strlen(str); i++) {
        Stack_push(stack, str[i]);
    }

    printf("\ne um palindromo ? %d\n", verificar_palindromo(stack, str));

    return 0;
}