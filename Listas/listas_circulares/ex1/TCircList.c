#include "TCircList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct _no {
    int val;
    struct _no *next;
};

struct list {
    TNo *begin;
};


TCircList *TCircList_create(){
    TCircList *list = (TCircList *) malloc(sizeof(TCircList));

    if (list == NULL) 
        return NULL;
    
    list->begin = NULL;

    return list;
}

TNo *TNo_create(int val) {
    TNo *no = (TNo *) malloc(sizeof(TNo));

    no->val = val;
    no->next = NULL;

    return no;
}

bool TCircList_insert(TCircList *list, int val){
    TNo *no = TNo_create(val);
    if (list->begin == NULL) {
        list->begin = no;
    } 
    else {
        TNo *aux = list->begin;
        while(aux->next != list->begin) {
            aux = aux->next;
        }
        aux->next = no;
    }

    no->next = list->begin;
    return true;
}

void TCircList_print(TCircList *list) {
  if (list->begin != NULL) {
    TNo *aux = list->begin;
    do {
      printf("[%d]->", aux->val);
      aux = aux->next;
    } while (aux != list->begin);
  }
}
