#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Desenvolva um programa em C que receba como entrada uma sequência de caracteres 
representando uma expressão matemática simples contendo apenas operações de adição, 
subtração, multiplicação e divisão, juntamente com números inteiros de um único dígito. 
O programa deve construir uma lista encadeada onde cada nó armazena um par de informações:
o operador e o número. Por exemplo, para a entrada "3+42-5", a lista gerada seria: [+, 3] -> [, 4] -> [-, 2] -> [-, 5]. */


struct _node {
    int val;
    char operacao;
    struct _node *prox;
};

struct _list {
    Node *begin;
};


LinkedList *LinkedList_create() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));

    if (list == NULL)
        return NULL;

    list->begin = NULL;

    return list;
}

Node *Node_createNFill(int val, char operacao) {
    Node *no = (Node *) malloc(sizeof(Node));

    if (no == NULL)
        return NULL;

    no->val = val;
    no->operacao = operacao;
    no->prox = NULL;

    return no;
}

bool LinkedList_insert_end(LinkedList *list, int val, char operacao) {
    Node *no = Node_createNFill(val, operacao);
    if (no == NULL)
        return false;

    if (list->begin == NULL) {
        list->begin = no;
    } else {
        Node *aux = list->begin;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }

    return true;
}

void LinkedList_print(LinkedList *list) {
    Node *aux = list->begin;

    while (aux != NULL) {
        if (aux->prox == NULL)
            printf("[%d]", aux->val);
        else
            printf("[%c, %d]", aux->operacao, aux->val);

        if (aux->prox != NULL)
            printf("->");

        aux = aux->prox;
    }

    printf("\n");
}