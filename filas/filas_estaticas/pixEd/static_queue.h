#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>

typedef struct _static_queue StaticQueue;
typedef struct _PixED PixED;

StaticQueue *StaticQueue_create(long capacity);
PixED *PixED_create(int id_orig, int id_dest, float value);
void StaticQueue_destroy(StaticQueue **Q_ref);

bool StaticQueue_is_empty(const StaticQueue *Q);
bool StaticQueue_is_full(const StaticQueue *Q);

long StaticQueue_size(const StaticQueue *Q);

long StaticQueue_capacity(StaticQueue *Q);

bool StaticQueue_enqueue(StaticQueue *Q, PixED *val);
PixED StaticQueue_peek(const StaticQueue *Q);
PixED StaticQueue_dequeue(StaticQueue *Q);

void StaticQueue_print(const StaticQueue *Q);


#endif