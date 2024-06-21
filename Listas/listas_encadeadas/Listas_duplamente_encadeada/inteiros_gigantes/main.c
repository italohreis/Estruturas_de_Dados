#include "Doubly_Linked_List.h"
#include <stdio.h>

int main(void) {

  TDList *lista1 = TDList_create();
  TDList *lista2 = TDList_create();

  int testes;
  char n1[1000], n2[1000];
  scanf("%d", &testes);

  while (testes--) {
    
    scanf("%s %s", n1, n2);
    
    int i;
    for (i = 0; n1[i] != '\0'; i++) {
      TDList_insert_end(lista1, n1[i] - '0');
    }

    for (i = 0; n2[i] != '\0'; i++) {
      TDList_insert_end(lista2, n2[i] - '0');
    }

    TDList *lista3 = soma(lista1, lista2);

    TDList_reverse_print(lista3);
  }

  
  return 0;
}