#include "TLinkedList.h"
#include <stdio.h>

int main(void) {
  TLinkedList *novaLista = TLinkedList_create();
  int V[] = {1, 5, 7, 9};
  for (int i = 0; i < 4; i++)
    if (!TLinkedList_insert_end(novaLista, V[i]))
      printf("Erro ao tentar inserir V[%d]=%d\n", i, V[i]);
  TLinkedList_print(novaLista);
  return 0;
}