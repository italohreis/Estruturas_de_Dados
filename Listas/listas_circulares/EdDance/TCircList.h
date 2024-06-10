#ifndef LINKED_CIRC_LIST_H
#define LINKED_CIRC_LIST_H
#include <stdbool.h>

typedef struct _no TNo;
typedef struct list TCircList;

TCircList *TCircList_create();

TNo *TNo_create(int val);

bool TCircList_insert(TCircList *, int);

int Ed_Dance(TCircList *list, TCircList *sec);


void TCircList_print(TCircList *);

#endif