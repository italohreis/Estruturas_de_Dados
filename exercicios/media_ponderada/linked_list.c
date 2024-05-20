#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct _node {
    int nota;
    int peso;
    struct _node *prox;
};

struct _list {
    Node *begin;
    float media;
};


LinkedList *LinkedList_create() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));

    if (list == NULL)
        return NULL;

    list->begin = NULL;

    return list;
}

Node *Node_createNFill(int nota, int peso) {
    Node *no = (Node *) malloc(sizeof(Node));

    if (no == NULL)
        return NULL;

    no->nota = nota;
    no->peso = peso;
    no->prox = NULL;

    return no;
}

bool LinkedList_insert_end(LinkedList *list, int nota, int peso) {
    Node *no = Node_createNFill(nota, peso);
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

float calcular_media(LinkedList *list) {
    float somaNota = 0, somaPeso = 0;

    Node *aux = list->begin;

    while (aux != NULL) {
        somaNota += (aux->nota * aux->peso);
        somaPeso += aux->peso;
        aux = aux->prox;
    }

    return somaNota / somaPeso;
}

void LinkedList_print(LinkedList *list) {
    Node *aux = list->begin;

    while (aux != NULL) {
        printf("[%d, %d]", aux->nota, aux->peso);
        if (aux->prox != NULL)
            printf("->");
        aux = aux->prox;
    }
    printf("->NULL");

    printf("\n");
}