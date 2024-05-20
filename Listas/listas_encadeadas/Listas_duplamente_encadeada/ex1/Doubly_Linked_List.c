#include <stdio.h>
#include <stdlib.h>
#include "Doubly_Linked_List.h"

struct _dnode {
    int val;
    struct _dnode *next;
    struct _dnode *prev;
};

struct _dlinked_list {
    struct _dnode *begin;
    struct _dnode *end;
};



DLinkedList *DLinkedList_create() {
    DLinkedList *list = (DLinkedList *) malloc(sizeof(DLinkedList));
    if (list == NULL) 
        return NULL;
    
    list->begin = NULL;
    list->end = NULL;

    return list;
}

Dnode *Dnode_create(int val) {
    Dnode *node = (Dnode *) malloc(sizeof(Dnode));
    if (node == NULL) 
        return NULL;
    
    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

bool DLinkedList_insert(DLinkedList *list, int val) {
    Dnode *node = Dnode_create(val);

    if (node == NULL)
        return false;

    if (list->begin == NULL) {
        list->begin = node;
    } else {
        Dnode *aux = list->begin;
        while (aux->next != NULL) {
            aux = aux->next;
        }

        node->prev = aux;
        aux->next = node;
    }
    list->end = node;

    return true;
}

void DLinkedList_print(DLinkedList *list) {
    if (list->begin != NULL) {

        Dnode *aux = list->begin;        
        while (aux != NULL) {
            printf("<-%d->", aux->val);
            aux = aux->next;
        }
        printf("\n");
    }
}

void DLinkedList_print_reverse(DLinkedList *list) {
    if (list->end != NULL) {

        Dnode *aux = list->end;        
        while (aux != NULL) {
            printf("<-%d->", aux->val);
            aux = aux->prev;
        }
        printf("\n");
    }
}