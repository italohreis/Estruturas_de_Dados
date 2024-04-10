#include "StaticList.h"
#include <stdio.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

void insertUI(StaticList *list) {
  int value;
  printf("Digite o valor a ser inserido: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_insert(list, value))
      puts(GREEN "\nInserido com sucesso!" RESET);
    else
      puts(RED "\nNão foi possível inserir!" RESET);
  }
}

void removeUI(StaticList *list) {
  int value;
  printf("Digite o valor a ser removido: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_remove(list, value))
      puts(GREEN "\nRemovido com sucesso!" RESET);
    else
      puts(RED "\nNão foi possível remover!" RESET);
  }
}

void searchUI(StaticList *list) {
  int value, index;
  printf("Digite o valor a ser buscado: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_search(list, value, &index))
      printf("\nEncontrado na posição %d\n", index);
    else
      puts(RED "\n404 Not found!" RESET); 
  }
}

int menuUI() {
  puts("");
  printf("Mundo da lista!\n1-> Inserir\n2-> "
         "Buscar\n3-> Remover\n4-> Imprimir\n0-> Sair\n");
  int op;
  return (scanf("%d", &op) == 1) ? op : 0;
}

int main(void) {

  StaticList *lista1 = StaticList_create();
  char op;
  do {
    op = menuUI();
    switch (op) {
    case 1:
      insertUI(lista1);
      break;
    case 2:
      searchUI(lista1);
      break;
    case 3:
      removeUI(lista1);
      break;
    case 4:
      puts("\nImprimindo: ");
      StaticList_print(lista1);
      break;
    case 0:
      puts("Até outra vez!");
      exit(0);
      break;
    }

  } while (op != '0');

  return 0;
}