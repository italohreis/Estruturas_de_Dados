#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

void preenche(StaticQueue *queue1, StaticQueue *queue2, StaticQueue *retorno) {
    int val1, val2;
    bool hasVal1, hasVal2;

    if (StaticQueue_capacity(retorno) < StaticQueue_size(queue1) + StaticQueue_size(queue2)) {
        return;
    }

    while (!StaticQueue_is_empty(queue1) || !StaticQueue_is_empty(queue2)) {
        hasVal1 = !StaticQueue_is_empty(queue1);
        hasVal2 = !StaticQueue_is_empty(queue2);

        if (hasVal1) {
            StaticQueue_peek(queue1, &val1);
        }
        if (hasVal2) {
            StaticQueue_peek(queue2, &val2);
        }

        if (hasVal1 && (!hasVal2 || val1 <= val2)) {
            StaticQueue_dequeue(queue1, &val1);
            StaticQueue_enqueue(retorno, val1);
        } else if (hasVal2) {
            StaticQueue_dequeue(queue2, &val2);
            StaticQueue_enqueue(retorno, val2);
        }
    }

}

int main() {
    
    static const long capacity = 5;

    StaticQueue *queue1 = StaticQueue_create(capacity);
    StaticQueue *queue2 = StaticQueue_create(capacity);
    StaticQueue *uniao = StaticQueue_create(capacity * 2);

    int i;
    for (i = 0; i < capacity; i++) {
        StaticQueue_enqueue(queue1, i);
        StaticQueue_enqueue(queue2, i +2 );
    }
    
    StaticQueue_print(queue1);
    StaticQueue_print(queue2);

    preenche(queue1, queue2, uniao);

    StaticQueue_print(uniao);

    return 0;
}