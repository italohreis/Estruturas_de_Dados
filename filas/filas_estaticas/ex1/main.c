#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

int main() {
    
    static const long capacity = 5;

    StaticQueue *Q = StaticQueue_create(capacity);

    int i;
    for (i = 0; i < capacity; i++) {
        StaticQueue_enqueue(Q, i);
    }

    StaticQueue_print(Q);
    StaticQueue_dequeue(Q);
    StaticQueue_print(Q);
    StaticQueue_enqueue(Q, 6);
    StaticQueue_print(Q);



    return 0;
}