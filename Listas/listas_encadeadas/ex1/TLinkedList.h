#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
typedef struct _no TNo;
typedef struct list TLinkedList;

TLinkedList *TLinkedList_create();
bool TLinkedList_insert_begin(TLinkedList *, int);
bool TLinkedList_insert_end(TLinkedList *, int);

void TLinkedList_print(TLinkedList *);

#endif