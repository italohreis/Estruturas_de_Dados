#include <stdio.h>
#include "linked_list.h"


int main() {

    int val;
    char operacao;

    LinkedList *list = LinkedList_create();

    while (operacao != 'q') {
        scanf("%d %c", &val, &operacao);

        LinkedList_insert_end(list, val, operacao);    
    }
    
    LinkedList_print(list);
    return 0;
}