#include "Doubly_Linked_List.h"
#include <stdio.h>

int main() {
  TDList *L1 = TDList_create();
  TDList_insert(L1, 5);
  TDList_insert(L1, 10);
  TDList_insert(L1, 2);
  TDList_insert(L1, 1);
  TDList_insert(L1, 4);
  TDList_insert(L1, 9);
  TDList_insert(L1, 20);

  TDList_print(L1);
  // TDList_reverse_print(L1);

  puts("Removing 1");
  TDList_remove(L1, 1);
  TDList_print(L1);
  TDList_reverse_print(L1);
  puts("Removing 5");
  TDList_remove(L1, 5);
  TDList_print(L1);
  TDList_reverse_print(L1);

  puts("Removing 8");
  TDList_remove(L1, 8);
  TDList_print(L1);
  TDList_reverse_print(L1);

  return 0;
}