#include <printf.h>
#include "include/queue.h"

queue_s* queue_create()
{
    queue_s* queue = malloc(sizeof(queue_s));
    queue->size = 0;
    queue->values = NULL;
    return queue;
}

void queue_enqueue(queue_s* queue, void* value)
{
    if (queue->values == NULL || queue->size % QUEUE_BLOCK_SIZE == 0)
    {
        size_t size = sizeof(NULL) * QUEUE_BLOCK_SIZE;
        void** newSpace = malloc(size);
        for (int i = 0; i < queue->size; ++i)
        {
            newSpace[i] = queue->values[i];
        }
        free(queue->values);
        queue->values = newSpace;
    }

    queue->values[queue->size++] = value;
}
