#include "StaticList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

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

/**
 * Inserção de um elemento na lista ordenada;
 * @param list ponteiro para a lista estática
 * @param value valor a ser inserido
 * @return true se a inserção foi bem sucedida, false caso contrário
 */
bool StaticList_insert(StaticList *list, int value) {
  if (!StaticList_is_full(list)) {
    if (StaticList_is_empty(list)){
        return 1;    
    }

    int i = 0;
    while (i < list->qty && list->data[i] < value) {
        i++;
    }

    int j;
    for (j = list->qty; j > i; j--) {
        list->data[j] = list->data[j-1];
    }

    list->data[i] = value;
    list->qty++;
    return true;
  }
  
  return false;
}

/**
 * Busca de um elemento na lista;
 * @param list ponteiro para a lista estática
 * @param value valor a ser buscado
 * @param p ponteiro para a posição do elemento na lista
 * @return true se o elemento foi encontrado, false caso contrário
 */

bool StaticList_search(StaticList *list, int value, int *p) {
    int i;
    if (StaticList_is_empty(list)) {
        printf("A lista esta vazia.\n");
        return false;
    }

    for (i = 0; i < list->qty; i++) {
        if (list->data[i] == value) {
            *p = i;
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
        printf("A lista esta vazia.\n");
        return false;
    }

    for (i = 0; i <list->qty; i++){
        if (list->data[i] == value){
            valueM = true;
            list->data[i] = list->data[i+1];
            value = list->data[i+1];
        }
    }
    
    if (valueM == true) {
        list->qty--;
        return true;
    }
    else {
        return false;
    }
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
        printf("%d, ", list->data[i]);
  }
  putchar('\n');
}