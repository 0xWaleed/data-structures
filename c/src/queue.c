#include "include/queue.h"

queue_s* queue_create(size_t capacity)
{
    queue_s* queue = malloc(sizeof(queue_s));
    queue->size = 0;
    queue->values = NULL;
    queue->capacity = capacity;
    return queue;
}

bool queue_enqueue(queue_s* queue, void* value)
{
    if (queue->size >= queue->capacity)
    {
        return false;
    }

    if (queue->values == NULL)
    {
        queue->values = malloc(queue->capacity * sizeof(NULL));
    }

    queue->values[queue->size++] = value;
    return true;
}

void* queue_dequeue(queue_s* queue)
{
    void* value = queue->values[0];
    for (int i = 0; i < queue->size - 1; ++i)
    {
        queue->values[i] = queue->values[i + 1];
    }
    queue->size--;
    return value;
}

void* queue_peek(queue_s* queue)
{
    return queue->values[0];
}

void queue_destroy(queue_s** queue)
{
    if (queue == NULL)
    {
        return;
    }
    queue_s* q = *queue;
    free(q->values);
    q->values = NULL;
    free(q);
    *queue = NULL;
}
