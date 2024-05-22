#include <stdio.h>
#include "Stack.h"
#include <string.h>

int main() {

    char *str = "pablo";

    Stack *stack = Stack_create(100);
    int i;
    int aux = strlen(str);
    
    for (i = 0; i < strlen(str); i++) {
        Stack_push(stack, str[i]);
    }

    while (!Stack_is_empty(stack)) {
        char c;
        Stack_pop(stack, &c);
        printf("%c", c);
    }

    printf("\ne um palindromo ? %d\n", verificar_palindromo(stack, str));


    return 0;
}