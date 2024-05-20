#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>

typedef struct _dnode Dnode;
typedef struct _dlinked_list DLinkedList;

DLinkedList *DLinkedList_create();

Dnode *Dnode_create(int val);

bool DLinkedList_insert(DLinkedList *list, int val);

void DLinkedList_print(DLinkedList *list);

void DLinkedList_print_reverse(DLinkedList *list);


#endif