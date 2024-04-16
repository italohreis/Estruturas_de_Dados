#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct _no {
  int info;
  struct _no *prox;
};

struct list {
  TNo *inicio;
};

TNo *TNo_createNFill(int);


TLinkedList *TLinkedList_create() {
  TLinkedList *nova = malloc(sizeof(TLinkedList));
  if (nova != NULL) {
    nova->inicio = NULL;
  }
  return nova;
}


TNo *TNo_createNFill(int info) {
  TNo *nova = malloc(sizeof(TNo));
  if (nova) {
    nova->info = info;  //valor a ser adicionado
    nova->prox = NULL;  //proximo elemento aponta pra nulo
  }
  return nova;
}

bool TLinkedList_insert_begin(TLinkedList *list, int value) {
  TNo *novo = TNo_createNFill(value);
  if (novo == NULL) //erro ao alocar
    return false;

  if (list->inicio != NULL)
    novo->prox = list->inicio;
  list->inicio = novo;  //caso a lista esteja vazia, o novo elemento é o inicio

  return true;
}

bool TLinkedList_insert_end(TLinkedList *list, int value) {
    TNo *novo = TNo_createNFill(value);
    if (list->inicio == NULL) {
        list->inicio = novo;
    } 
    else {
        TNo *aux = list->inicio;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;   //caso chegue no prox apontando pra nulo, então é o ultimo elemento.
    }
    return true;
}

void TLinkedList_print(TLinkedList *list) {
  TNo *aux;
  for (aux = list->inicio; aux != NULL; aux = aux->prox) {
    printf("%d->", aux->info);
  }
  putchar('\n');
}
