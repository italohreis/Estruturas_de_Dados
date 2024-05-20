#include "Doubly_Linked_List.h"
#include <stdio.h>

int main () {
    DLinkedList *list = DLinkedList_create();

    int i;
    for (i = 0; i < 5; i++) {
        DLinkedList_insert(list, i);
    }

    DLinkedList_print(list);
    DLinkedList_print_reverse(list);
}