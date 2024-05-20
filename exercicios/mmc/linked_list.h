#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _node Node;

typedef struct _list LinkedList;

LinkedList *LinkedList_create();

Node *Node_createNFill(int);

bool LinkedList_insert_end(LinkedList *, int);

void LinkedList_print(LinkedList *list);

#endif