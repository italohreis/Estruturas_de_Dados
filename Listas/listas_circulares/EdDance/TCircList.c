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
    int size;
};


TCircList *TCircList_create(){
    TCircList *list = (TCircList *) malloc(sizeof(TCircList));

    if (list == NULL) 
        return NULL;
    
    list->begin = NULL;
    list->size = 0;
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
        no->next = list->begin;
    }

    no->next = list->begin;
    list->size++;
    return true;
}


int Ed_Dance(TCircList *list, TCircList *sec) {
    TNo *current = list->begin;
    TNo *aux = NULL;
    TNo *time = sec->begin;

    while (list->size > 1){
        int i;
        for (i = 0; i < time->val; i++) {
            aux = current;
            current = current->next;
        }

        aux->next = current->next;
        free(current);
        list->size--;

        current = aux->next;

        time = time->next;
    }

    return current->val;
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
