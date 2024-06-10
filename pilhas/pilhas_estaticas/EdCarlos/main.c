#include <stdio.h>
#include "Stack.h"
#include <string.h>

int main() {
    char action;
    int id, value;

    Stack *primaria = Stack_create(10);
    Stack *secundaria = Stack_create(10);

    do {
        scanf("%c %d", &action, &id);
        
        switch(action) {
            case 'i':
                if (!Stack_push(primaria, id)) {
                    printf("overflow\n");
                }
                break;
            case 'r':
                while (Stack_pop(primaria, &value)) {
                    printf("%d,", value);
                    if (value == id) {
                        break;
                    }
                    Stack_push(secundaria, value);
                }

                if (value != id) {
                    printf("underflow");
                }

                while (Stack_pop(secundaria, &value)) {
                    Stack_push(primaria, value);
                }

                printf("\n");
                break;
            case '0':
                break;
        }

    } while (action != '0');


    return 0;
}