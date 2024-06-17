#include "static_queue.h"
/* Banco Central da Computação deseja um sistema moderno para efetuar transferências bancárias
de maneira instantânea chamado PixED. Acontece que o sistema global de execução de
transferências PixED é implementado por uma fila global de tamanho finito (N). Esta fila
funciona como uma espécie de buffer que acumula as transações e quando fica cheia, é que de
fato o executor do PixED faz as transferências.
Neste sentido, o BCC solicita a implementação de um programa em C que receba uma sequência
de entradas e acumule-as na fila. Quando a fila atingir seu máximo, as transferências devem ser
efetivadas. Cada transferência é identificada por conta origem (int), conta destino (int) e o valor a
ser transferido (float). O tipo PixED deve ser um tipo struct com os campos mencionados
anteriormente e cada struct PixED deve ser armazenada em uma Fila de buffer com tamanho
máximo de N elementos (N também é fornecido). Quando a Fila fica cheia, as transações devem
ser executadas. A execução das transações será a seguinte informação “(id_orig, id_dest,
valor),”, onde id_orig e id_dest correspondem respectivamente aos inteiros que identificam
as contas. A variável valor deverá ser impresso com apenas 2 casas decimais. Ao final de uma
linha de transferência, deverá ser impresso um ‘\n’ */

#include <stdio.h>
#include <stdlib.h>

typedef struct _PixED {
    int id_orig;
    int id_dest;
    float value;
} PixED;

typedef struct _static_queue {
    PixED *data;
    long capacity;
    long size;
    long begin;
    long end;
} StaticQueue;


StaticQueue *StaticQueue_create(long capacity) {
    StaticQueue *Q = (StaticQueue *)malloc(sizeof(StaticQueue));
    if (Q == NULL) {
        return NULL;
    }

    Q->capacity = capacity;
    Q->size = 0;
    Q->begin = 0;
    Q->end = 0;
    Q->data = (PixED *) malloc(capacity * sizeof(PixED));
    if (Q->data == NULL) {
        return NULL;
    }

    return Q;
}

PixED *PixED_create(int id_orig, int id_dest, float value) {
    PixED *p = (PixED *)malloc(sizeof(PixED));
    if (p == NULL) {
        return NULL;
    }

    p->id_orig = id_orig;
    p->id_dest = id_dest;
    p->value = value;

    return p;
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

long StaticQueue_capacity(StaticQueue *Q) {
    return Q->capacity;
}

bool StaticQueue_enqueue(StaticQueue *Q, PixED *val) {
    if (StaticQueue_is_full(Q)) {
        return false;
    }

    Q->data[Q->end] = *val;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;

    return true;
}

PixED StaticQueue_peek(const StaticQueue *Q) {
    if (StaticQueue_is_empty(Q)) {
        return (PixED){0, 0, 0.0f}; // return a default value
    }

    return Q->data[Q->begin];
}

PixED StaticQueue_dequeue(StaticQueue *Q) {
    if (StaticQueue_is_empty(Q)) {
        static PixED defaultPixED = {0, 0, 0.0f};
        return defaultPixED; // return a default value
    }

    PixED val = Q->data[Q->begin];
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
        printf("(%d, %d, %.2f),", Q->data[i].id_orig, Q->data[i].id_dest, Q->data[i].value);
        i = (i + 1) % Q->capacity;
    } while (i != Q->end);
    printf("\n");
}





