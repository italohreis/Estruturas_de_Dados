#include "StaticList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

struct _list {
  unsigned int qty;
  int data[MAX];
};

StaticList *StaticList_create() {
  StaticList *list = (StaticList *)malloc(sizeof(StaticList));
  if (list != NULL) {
    list->qty = 0;
  }
  return list;
}

void StaticList_delete(StaticList **list) {
  free(*list);
  *list = NULL;
}

/**
 * Inserção de um elemento na lista;
 * @param list ponteiro para a lista estática
 * @param value valor a ser inserido
 * @return true se a inserção foi bem sucedida, false caso contrário
 */
bool StaticList_insert(StaticList *list, int novoItem) {
  if (!StaticList_is_full(list)) {
    list->data[list->qty++] = novoItem;
    return true;
  }
  return false;
}

/**
 * Busca de um elemento na lista;
 * @param list ponteiro para a lista estática
 * @param value valor a ser buscado
 * @param index ponteiro para a posição do elemento na lista
 * @return true se o elemento foi encontrado, false caso contrário
 */

bool StaticList_search(StaticList *list, int value, int *index) {
    int i;
    if (StaticList_is_empty(list)) {
        return false;
    }

    for (i = 0; i < list->qty; i++) {
        if (list->data[i] == value) {
            *index = i;
            return true;
        }
    }
    return false;
}

/**
 * Remoção de um elemento na lista;
 * @param list ponteiro para a lista estática
 * @param value valor a ser removido
 * @return true se a remoção foi bem sucedida, false caso contrário
 */

bool StaticList_remove(StaticList *list, int value){
    int i;
    bool valueM = false;
    if (StaticList_is_empty(list)) {
        return false;
    }

    int index;
    if (StaticList_search(list, value, &index)) {
        int i;
        for (i = index; i < list->qty-1; i++) {
            list->data[i] = list->data[i+1];
        }
        list->qty--;
        return true;
    } 
    else {
        return false;
    }

    return false;
}

/**
 * Retorna o tamanho da lista;
 * @param list ponteiro para a lista estática
 * @return o tamanho da lista
 */

unsigned int StaticList_size(StaticList *list){
    return list->qty;
}

/**
 * Verifica se a lista está vazia;
 * @param list ponteiro para a lista estática
 * @return true se a lista está vazia, false caso contrário
 */

bool StaticList_is_empty(StaticList *list) {
    return list->qty == 0;
}

bool StaticList_is_full(StaticList *list) { 
    return list->qty == MAX; 
}

void StaticList_print(StaticList *list) {
    int i;
    for (i = 0; i < list->qty; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}