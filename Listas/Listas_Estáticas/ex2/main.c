#include "StaticList.h"
#include <stdio.h>

int main(void) {

  StaticList *lista1 = StaticList_create();

     StaticList_insert(lista1, 40);
     StaticList_insert(lista1, 5);
     StaticList_insert(lista1, 2);
     StaticList_insert(lista1, 4);
     StaticList_insert(lista1, 15);
    
    

    StaticList_print(lista1);

    StaticList_insert(lista1, 35);
    
    StaticList_print(lista1);

     StaticList_delete(&lista1);

     printf("lista1 is null? %s\n", lista1 == NULL ? "true" : "false");
    
  return 0;
}