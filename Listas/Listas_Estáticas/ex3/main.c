#include "StaticList.h"
#include <stdio.h>


int main() {
  
  StaticList *listas[2] = {StaticList_create(), StaticList_create()};

  char action;
  int number, position;

  do {

    scanf("%c %d %d", &action, &number, &position);

    switch(action) {

    case  'i': 
      if (StaticList_insert(listas[position], number)) {
        printf("Inserido com sucesso\n");
        StaticList_print(listas[position]);
      } else {
        printf("Erro ao inserir\n");
      
    }

    case 'r': 
      if(StaticList_remove(listas[position], number)) {
        printf("Removido com sucesso\n");
        StaticList_print(listas[position]);
      } else {
        printf("Erro ao remover\n");
      }
    
    case 'p':
      StaticList_print(listas[position]);

    case 'c':

      break;

    case 0:
      printf("Finalizando...");
      break;
      
    default:
      printf("Opção inválida\n");
    }
          
   
  } while (action != 0);
    
  return 0;
}