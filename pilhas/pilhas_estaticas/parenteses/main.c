#include <stdio.h>
#include "Stack.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

    char exp[250] = "( ( ) ) - ( ( )( ) ) - ( )  )";
    char value;
    bool is_Correct = true;

    Stack *stack = Stack_create(strlen(exp));
    int i;
    for (i = 0; i < strlen(exp); i++) {
        if (!isspace(exp[i])) {
            if (exp[i] == '(') {
                Stack_push(stack, exp[i]);
            } else if (exp[i] == ')') {
                if (Stack_is_empty(stack)) {
                    printf("incorreto.\n");
                    is_Correct = false;
                    break;
                }
                Stack_pop(stack, &value);
            }
        }
    }

    if (is_Correct) {
        if (Stack_is_empty(stack)) {
            printf("sucesso.\n");
        }
        else {
            printf("incorreto.");
        } 
    }


    return 0;
}