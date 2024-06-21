#include "Doubly_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
  int info;
  struct no *prox, *ant;
};

struct no *TNo_createnfill(int info) {
  struct no *novo = (struct no *)malloc(sizeof(struct no));
  if (novo) {
    novo->info = info;
    novo->prox = NULL;
    novo->ant = NULL;
  }
  return novo;
}
struct double_linked {
  struct no *inicio;
  struct no *fim;
};

TDList *TDList_create() {
  TDList *nova = (TDList *)malloc(sizeof(TDList));
  if (nova) {
    nova->inicio = NULL;
    nova->fim = NULL;
  }
  return nova;
}
void TDList_destroy(TDList *list) { return; }

int TDList_insert(TDList *list, int info) {
  struct no *novo = TNo_createnfill(info);
  if (novo == NULL || list == NULL)
    return 0;
  if (list->inicio == NULL) {
    list->inicio = novo;
    list->fim = novo;
  } else {
    // se o numero for menor do que o inicio
    if (info < list->inicio->info) {
      novo->prox = list->inicio;
      list->inicio->ant = novo;
      list->inicio = novo;
    } else {
      struct no *aux = list->inicio;
      while (aux != list->fim && aux->info < info)
        aux = aux->prox;
      // Se passei, eu retorno em um nó
      if (aux->info > info)
        aux = aux->ant;

      novo->prox = aux->prox;
      novo->ant = aux;
      if (aux->prox != NULL)
        aux->prox->ant = novo;
      aux->prox = novo;
      if (aux == list->fim)
        list->fim = novo;
    }
  }
  return 1;
}

//insert end
int TDList_insert_end(TDList *list, int info) {
  struct no *novo = TNo_createnfill(info);
  if (novo == NULL || list == NULL)
    return 0;
  if (list->inicio == NULL) {
    list->inicio = novo;
    list->fim = novo;
  } else {
    list->fim->prox = novo;
    novo->ant = list->fim;
    list->fim = novo;
  }
  return 1;
}
TNo *TDList_search(TDList *list, int info) {
  TNo *aux = list->inicio;
  while (aux != NULL && aux->info != info)
    aux = aux->prox;
  return aux;
}
int TDList_remove(TDList *list, int info) {
  if (list == NULL)
    return 0;
  struct no *aux = TDList_search(list, info);
  if (aux == NULL)
    return 0;

  if (aux->ant != NULL)
    aux->ant->prox = aux->prox;

  if (aux->prox != NULL)
    aux->prox->ant = aux->ant;

  if (aux == list->inicio)
    list->inicio = list->inicio->prox;

  if (aux == list->fim)
    list->fim = aux->ant;

  free(aux);
  return 1;
}
void TDList_print(TDList *list) {
  if (list) {
    struct no *aux = list->inicio;
    while (aux) {
      printf("%d", aux->info);
      aux = aux->prox;
    }
    puts("");
  }
}

void TDList_reverse_print(TDList *list) {
  if (list) {
    struct no *aux = list->fim;
    while (aux) {
      printf("%d", aux->info);
      aux = aux->ant;
    }
    puts("\n");
  }
}

TDList *soma(TDList *list1, TDList *list2) {
  TNo *aux1 = list1->fim;
  TNo *aux2 = list2->fim;
  TDList *list3 = TDList_create();

  int carry = 0;

  while (aux1 != NULL || aux2 != NULL) {
    int sum = carry;
    if (aux1 != NULL) {
      sum += aux1->info;
      aux1 = aux1->ant;
    }
    if (aux2 != NULL) {
      sum += aux2->info;
      aux2 = aux2->ant;
    }
    carry = sum / 10;
    sum = sum % 10;
    TDList_insert_end(list3, sum);
  }

  if (carry > 0) {
    TDList_insert_end(list3, carry);
  }

 

  return list3;
}
