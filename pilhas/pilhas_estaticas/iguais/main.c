#include <stdio.h>
#include "Stack.h"
#include <string.h>
#include <stdbool.h>

bool is_equal(Stack *stack1, Stack *stack2) {
    char value1, value2;

    if (Stack_size(stack1) != Stack_size(stack2)) {
        return false;
    }

    Stack *aux1 = Stack_create(Stack_size(stack1));
    Stack *aux2 = Stack_create(Stack_size(stack1));
    bool isEqual = true;

    while (!Stack_is_empty(stack1) && isEqual) {
        Stack_pop(stack1, &value1);
        Stack_pop(stack2, &value2);

        Stack_push(aux1, value1);
        Stack_push(aux2, value2);

        if (value1 != value2) {
            isEqual = false;
        }
    }

    //coloca os elementos de volta para as pilhas originais
    while (!Stack_is_empty(aux1)) {
        Stack_pop(aux1, &value1);
        Stack_push(stack1, value1);

        Stack_pop(aux2, &value2);
        Stack_push(stack2, value2);
    }

    return isEqual;
}

int main() {

    Stack *stack1 = Stack_create(10);
    Stack *stack2 = Stack_create(10);

    int i;
    for (i = 0; i < 10; i++) {
        Stack_push(stack1, i+1);
        Stack_push(stack2, i);
    }

    if (is_equal(stack1, stack2)) 
        printf("Iguais\n");
    else 
        printf("Diferentes\n");
    
    
    return 0;
}