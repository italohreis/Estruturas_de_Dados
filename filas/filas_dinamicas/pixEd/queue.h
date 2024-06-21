#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct typeQueue Fila;
typedef struct typePix Pix;

Fila* Fila_create(int size);
Pix* Pix_create(int id_orig, int id_dest, float valor);
bool Fila_enqueue(Fila *fila, Pix *pix);
bool Fila_dequeue(Fila *fila, Pix *temp);
bool Fila_destroy(Fila *fila);
bool Fila_Qty(Fila *fila);

bool isFull(Fila *fila);
bool isEmpty(Fila *fila);

void print(Pix *pix);

#endif