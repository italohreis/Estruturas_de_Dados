#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void esvaziar_fila(Fila *fila) {
    Pix *temp = Pix_create(0, 0, 0);
    while (!isEmpty(fila)) {
        Fila_dequeue(fila, temp);
        print(temp);
    }
}

int main() {
    int size;

    scanf("%d", &size);

    Fila *fila = Fila_create(size);

    int id_orig, id_dest;
    float value;
    while (1) {
        scanf("%d %d %f", &id_orig, &id_dest, &value);
        
        if (id_dest == 0 && id_orig == 0)
            break;

        Pix *pix = Pix_create(id_orig, id_dest, value);
        if (!isFull(fila)) {
            Fila_enqueue(fila, pix);
        } else {
            esvaziar_fila(fila);
            Fila_enqueue(fila, pix);     
        }
    }    
    
    esvaziar_fila(fila);

    return 0;
}