#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

void preenche(StaticQueue *queue1, StaticQueue *queue2, StaticQueue *retorno) {



}   

int main() {
    
    static const long capacity = 5;

    StaticQueue *queue1 = StaticQueue_create(capacity);
    StaticQueue *queue2 = StaticQueue_create(capacity);
    StaticQueue *uniao = StaticQueue_create(capacity);

    int i;
    for (i = 0; i < capacity; i++) {
        StaticQueue_enqueue(queue1, (i));
    }

    for (i = 6; i < 11; i++) {
        StaticQueue_enqueue(queue2, (i));
    }

    StaticQueue_print(queue1);
    StaticQueue_print(queue2);

    preenche(queue1, queue2, uniao);

    StaticQueue_print(uniao);

    return 0;
}