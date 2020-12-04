

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include "common.h"

typedef struct
{
    size_t size;
    size_t capacity;
    void** values;
} queue_s;

BEGIN_DECL

queue_s* queue_create(size_t capacity);

bool queue_enqueue(queue_s* queue, void* value);

void* queue_dequeue(queue_s* queue);

void* queue_peek(queue_s* queue);

END_DECL

#endif //QUEUE_H
