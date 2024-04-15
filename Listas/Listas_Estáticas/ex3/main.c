#include "StaticList.h"
#include <stdio.h>

#define TAM 3

//menu

void menu(StaticList *listas[]) {
  char action = 0;
  int number = 0, position = 0, size = 0;

  do {
    printf("\nenter the action:\n");
    scanf("%c %d %d", &action, &number, &position);
    while(getchar() != '\n');   //limpa o buffer do teclado

     if (position < 0 || position > TAM - 1) {  //verifica se a posicao escolhida é valida
      printf("\ninvalid position\n");
      continue;
    } 
    
    if (listas[position] == NULL) {       //verifica se a lista na posição é nula(nao existe), se for criará uma nova lista na posição
      listas[position] = StaticList_create();
      size++;
      printf("List create\n");
    }

    switch(action) {

    case 'i': 
      if (StaticList_insert(listas[position], number)) 
        printf("sucess\n");
      else
        printf("fail\n");
      
      break;
    case 'r': 
      if(StaticList_remove(listas[position], number)) 
        printf("sucess\n");
      else 
        printf("not found\n");
    
      break;
    case 'p':
      StaticList_print(listas[position]);
      break;

    case 'c':

      if (size == TAM) {  //verifica se o tamanho da lista é igual ao tamanho maximo
        printf("not possible\n");
        break;
      }

      listas[size] = StaticList_concatenar(listas[number], listas[position]);
      if (listas[size] != NULL) {
        StaticList_print(listas[size]);
        size++;
      }
      else {
        printf("not possible\n");
      }
  
      break;

    case '0':
      printf("\nExiting...\n");
      break;

    default:
      printf("\ninvalid action\n");
    }   
   
  } while (action != '0');
}

int main() {
  
  StaticList *listas[TAM] = {NULL, NULL, NULL};

  menu(listas);
    
  return 0;
}