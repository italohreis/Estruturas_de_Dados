#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"
int main() {
    int size;

    scanf("%d", &size);

    StaticQueue *queue = StaticQueue_create(size);

    int id_orig, id_dest;
    float value;
    do {
        scanf("%d %d %f", &id_orig, &id_dest, &value);
        if (id_dest != 0 || id_orig != 0 || value != 0.0) {
            if (StaticQueue_is_full(queue)) {
                while (!StaticQueue_is_empty(queue)) {
                    StaticQueue_dequeue(queue);
                    StaticQueue_print(queue);
                }
            }

            PixED *pix = PixED_create(id_orig, id_dest, value);
            StaticQueue_enqueue(queue, pix);
        }

        if (id_dest == 0 || id_orig == 0 || value == 0.0) {
            while (!StaticQueue_is_empty(queue)) {
                StaticQueue_print(queue);
            }
        }


    } while (id_dest != 0 || id_orig != 0 || value != 0.0);


    return 0;
}