#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct typePix{
	int id_orig, id_dest;
	float valor;
	Pix *next;
};

struct typeQueue{
	Pix *tail;
	int qty, MAX;
};

Pix* Pix_create(int id_orig, int id_dest, float valor) {
    Pix *novo = (Pix*)malloc(sizeof(Pix));
    if (!novo) return NULL;

    novo->id_orig = id_orig;
    novo->id_dest = id_dest;
    novo->valor = valor;
    novo->next = NULL;
    return novo;
}

Fila* Fila_create(int size) {
    Fila *new = (Fila*)malloc(sizeof(Fila));
    if (!new) return NULL;

    new->tail = NULL;
    new->qty = 0;
    new->MAX = size;
    return new;
}

bool Fila_enqueue(Fila *fila, Pix *pix) {
    if (isFull(fila)) return false;

    if (fila->tail == NULL) {
        pix->next = pix;
    } else {
        pix->next = fila->tail->next;
        fila->tail->next = pix;
    }
    fila->tail = pix;
    fila->qty++;
    return true;
}

bool Fila_dequeue(Fila *fila, Pix *temp) {
    if (isEmpty(fila)) return false;

    Pix *oldHead = fila->tail->next;
    *temp = *oldHead;

    if (fila->tail == oldHead) {
        fila->tail = NULL;
    } else {
        fila->tail->next = oldHead->next;
    }
    free(oldHead);
    fila->qty--;
    return true;
}

/* void Fila_destroy(Fila *fila) {
    while (!isEmpty(fila)) {
        Pix temp;
        Fila_dequeue(fila, &temp);
    }
    free(fila);
} */

bool isEmpty(Fila *fila) {
    return fila->qty == 0;
}

bool isFull(Fila *fila) {
    return fila->qty == fila->MAX;
}

void print(Pix *pix) {
    printf("%d %d %.2f\n", pix->id_orig, pix->id_dest, pix->valor);
}

