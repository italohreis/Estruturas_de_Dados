#include <stdio.h>
#include "Stack.h"
#include <string.h>
#include <ctype.h>

bool verificar_palindromo(Stack *stack, char *palavra) {
    char value = 0;

    int i;
    for (i = 0; i < strlen(palavra); i++) {
        Stack_pop(stack, &value);
        printf("%c[%d]\n", value, i);
        printf("%c[%d]\n", palavra[i], i);
        if (value != palavra[i]) {
            return false;
        }
    }

    return true;
}

int main() {

    char str[250] = "roma me tem amor";
    Stack *stack = Stack_create(strlen(str));

    int i, j = 0;
    char aux[250] = {0};
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != '\n' && isalpha(str[i])) {
            aux[j] = str[i];
            Stack_push(stack, str[i]);  
            j++;  
        }
    }
    aux[j] = '\0';
    strcpy(str, aux);
    printf("e um palindromo ? %d\n", verificar_palindromo(stack, str));

    return 0;
}