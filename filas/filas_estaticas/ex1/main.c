#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

void remove_negativo(StaticQueue *Q) {
    bool encontrado = false;
    StaticQueue *aux = StaticQueue_create(StaticQueue_capacity(Q));
    int value;
    while (!StaticQueue_is_empty(Q)) {
        value = StaticQueue_dequeue(Q);
        if (value >= 0) {
            StaticQueue_enqueue(aux, value);
        }
    }
    while (!StaticQueue_is_empty(aux)) {
        StaticQueue_enqueue(Q, StaticQueue_dequeue(aux));
    }

}

int main() {
    
    static const long capacity = 5;

    StaticQueue *Q = StaticQueue_create(capacity);

    int i;
    for (i = 0; i < capacity; i++) {
        StaticQueue_enqueue(Q, (i - 2));
    }

    StaticQueue_print(Q);

    remove_negativo(Q);

    StaticQueue_print(Q);

    return 0;
}