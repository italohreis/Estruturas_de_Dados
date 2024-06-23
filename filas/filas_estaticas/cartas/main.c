#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

void processDeck(int n) {
    if (n == 0) return;

    StaticQueue* q = StaticQueue_create(n);
    for (int i = 1; i <= n; i++) {
        StaticQueue_enqueue(q, i);
    }

    printf("Discarded cards:");
    int first = 1;
    while (StaticQueue_size(q) > 1) {
        if (!first) {
            printf(",");
        }
        printf(" %d", StaticQueue_dequeue(q));
        StaticQueue_enqueue(q, StaticQueue_dequeue(q));
        first = 0;
    }

    printf("\nRemaining card: %d\n", StaticQueue_dequeue(q));
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        processDeck(n);
    }

    return 0;
}
