

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_BLOCK_SIZE 8

#include <stdlib.h>
#include "common.h"

typedef struct
{
    size_t size;
    void** values;
} queue_s;

BEGIN_DECL

queue_s* queue_create();
void queue_enqueue(queue_s* queue, void* value);

END_DECL

#endif //QUEUE_H
