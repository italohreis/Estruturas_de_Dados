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
  * Concatenação de duas listas;
  * se a concatenação couber em uma lista, uma nova lista é criada e os elementos são copiados para ela;
  * se a concatenação não couber em uma lista, a concatenação não é realizada e a função retorna false;
  * @param list1 ponteiro para a primeira lista estática
  * @param list2 ponteiro para a segunda lista estática
  * @return true se a concatenação foi bem sucedida, false caso contrário
  */
 StaticList *StaticList_concatenar(StaticList *list1, StaticList *list2) {

    if ((list1->qty + list2->qty) > MAX || list1->qty == 0 || list2->qty == 0) {
        return NULL;
    } 

    StaticList *list3 = StaticList_create();

    int i;
    for (i = 0; i < list1->qty; i++) {
      StaticList_insert(list3, list1->data[i]);
    }

    for (i = 0; i < list2->qty; i++) {
      StaticList_insert(list3, list2->data[i]);
    }
  
  return list3;
}
 


/**
 * Inserção de um elemento na lista de maneira ordenada crescente;
 * @param list ponteiro para a lista estática
 * @param value valor a ser inserido
 * @return true se a inserção foi bem sucedida, false caso contrário
 */
bool StaticList_insert(StaticList *list, int value) {
  if (!StaticList_is_full(list)) {

    int i = list->qty - 1;
    while (i >= 0 && list->data[i] > value) {   // procura a posição correta do novo elemento
      list->data[i + 1] = list->data[i];    // desloca os elementos maiores para a direita
      i--;
    }

    list->data[i + 1] = value;  
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
    if (StaticList_is_empty(list)) 
        return false;
    
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
    if (StaticList_is_empty(list)) 
        return false;

    for (i = 0; i < list->qty; i++) {
        if (list->data[i] == value) {
            valueM = true;
            break;
        }
    }

    if (valueM) {
        for (i; i < list->qty - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
        
        list->qty--;
        return true;
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
      printf("%d", list->data[i]);

      if (i < list->qty - 1)
        printf(", ");
  }
      
  putchar('\n');

}