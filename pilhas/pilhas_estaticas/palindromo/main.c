#include <stdio.h>
#include "Stack.h"
#include <string.h>

bool verificar_palindromo(Stack *stack, char *palavra) {
    char value = 0;

    int i;
    for (i = 0; i < strlen(palavra); i++) {
        Stack_pop(stack, &value);
        if (value != palavra[i]) {
            return false;
        }
    }

    return true;
}

int main() {

    char *str = "mirim";
    Stack *stack = Stack_create(100);

    int i;
    for (i = 0; i < strlen(str); i++) {
        Stack_push(stack, str[i]);
    }

    puts("");
    printf("e um palindromo ? %d\n", verificar_palindromo(stack, str));

    return 0;
}