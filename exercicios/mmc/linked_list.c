#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct _node {
    int val;
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

Node *Node_createNFill(int val) {
    Node *no = (Node *) malloc(sizeof(Node));

    if (no == NULL)
        return NULL;

    no->val = val;
    no->prox = NULL;

    return no;
}

bool LinkedList_insert_end(LinkedList *list, int val) {
    Node *no = Node_createNFill(val);
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
        printf("%d", aux->val);
        if (aux->prox != NULL)
            printf("->");
        aux = aux->prox;
    }
    printf("->NULL");

    printf("\n");
}