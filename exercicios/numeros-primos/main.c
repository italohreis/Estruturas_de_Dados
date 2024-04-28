#include <stdio.h>
#include "linked_list.h"
#include <stdbool.h>

bool verificar_primalidade(int val);

int main() {

    int num = 0;
    LinkedList *list = LinkedList_create();
    while (1) {
        scanf("%d", &num);

        if (num == 0)
            break;  
        
        if (verificar_primalidade(num))
            LinkedList_insert_end(list, num);
    }

    LinkedList_print(list);

    return 0;
}


bool verificar_primalidade(int val) {
    if (val <= 1)
        return false;

    int i = 2;
    while (i != val) {
        if ((val % i) == 0)
            return false;
        i++;
    }
    return true;
}