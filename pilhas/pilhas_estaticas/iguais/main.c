#include <stdio.h>
#include "Stack.h"
#include <string.h>
#include <stdbool.h>

bool is_equal(Stack *stack1, Stack *stack2) {
    char value1, value2;

    if (Stack_size(stack1) != Stack_size(stack2)) {
        return false;
    }

    while (!Stack_is_empty(stack1)) {
        Stack_pop(stack1, &value1);
        Stack_pop(stack2, &value2);

        if (value1 != value2) {
            return false;
        }
    }

    return true;
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