#include "static_queue.h"

#include <stdio.h>
#include <stdlib.h>

struct _static_queue {
    int *data;
    long capacity;
    long size;
    long begin;
    long end;
};

StaticQueue *StaticQueue_create(long capacity) {
    StaticQueue *Q = (StaticQueue *)malloc(sizeof(StaticQueue));
    if (Q == NULL) {
        return NULL;
    }

    Q->capacity = capacity;
    Q->size = 0;
    Q->begin = 0;
    Q->end = 0;
    Q->data = (int *)malloc(capacity * sizeof(int));
    if (Q->data == NULL) {
        return NULL;
    }

    return Q;
}


bool StaticQueue_is_empty(const StaticQueue *Q) {
    return Q->size == 0;
}

bool StaticQueue_is_full(const StaticQueue *Q) {
    return Q->size == Q->capacity;
}

long StaticQueue_size(const StaticQueue *Q) {
    return Q->size;
}

void StaticQueue_enqueue(StaticQueue *Q, int val) {
   
    if (StaticQueue_is_full(Q)) {
        return;
    }

    Q->data[Q->end] = val;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;


}

int StaticQueue_peek(const StaticQueue *Q) {
    if (StaticQueue_is_empty(Q)) {
        return -1;
    }

    return Q->data[Q->begin];
}

int StaticQueue_dequeue(StaticQueue *Q) {
    if (StaticQueue_is_empty(Q)) {
        return -1;
    }

    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;

    return val;
}

void StaticQueue_print(const StaticQueue *Q) {
    if (StaticQueue_is_empty(Q)) {
        return;
    }

    long i = Q->begin;
    do {
        printf("%d ", Q->data[i]);
        i = (i + 1) % Q->capacity;
    } while (i != Q->end);
    printf("\n");
}





