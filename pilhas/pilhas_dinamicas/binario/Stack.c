#include "Stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
  int info;
  struct _no *prox;
} TNo;

struct _stack {
  TNo *inicio;
  unsigned int qty;
};

Stack *Stack_create() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (stack) {
    stack->inicio = NULL;
    stack->qty = 0;
  }
  return stack;
}

TNo *TNode_create(int value) {
  TNo *node = (TNo *)malloc(sizeof(TNo));
  if (node) {
    node->info = value;
    node->prox = NULL;
  }
  return node;
}

bool Stack_push(Stack *stack, int value) {
  TNo *novo = TNode_create(value);

  novo->prox = stack->inicio;
  stack->inicio = novo;
  stack->qty++;
  return true;
}
/**
 * Remove um elemento da pilha.
 * @param Stack* stack - Ponteiro para a pilha
 * @param int* value - Ponteiro para a variável que receberá o valor removido
 * @return bool - true se a remoção foi bem sucedida, false caso contrário
 */
bool Stack_pop(Stack *stack, int *temp) {
  if (!Stack_is_empty(stack)) {
    *temp = stack->inicio->info;
    TNo *aux = stack->inicio;
    stack->inicio = aux->prox;
    free(aux);
    stack->qty--;
    return true;
  }
  return false;
}

void Stack_destroy(Stack *stack) {
  
  if (stack->inicio == NULL) {
    free(stack);
    return;
  }

  TNo *aux = stack->inicio;
  while (aux != NULL) {
    TNo *temp = aux;
    aux = aux->prox;
    free(temp);
  }

  free(stack);
}


/**
 * Checa se a pilha está vazia
 * @param Stack* stack - Ponteiro para a pilha
 * @return bool - true se a pilha estiver vazia, false caso contrário
 */
bool Stack_is_empty(Stack *stack) { return stack->qty == 0; }
/**
 * Checa se a pilha está cheia
 * @param Stack* stack - Ponteiro para a pilha
 * @return bool - true se a pilha estiver cheia, false caso contrário
 */
bool Stack_is_full(Stack *stack) { return false; }

/**
 * Retorna o tamanho da pilha.
 * @param Stack* stack - Ponteiro para a pilha
 * @return unsigned int - Tamanho ocupado da pilha
 */
uint Stack_size(Stack *stack) { return stack->qty; }
