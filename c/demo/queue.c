#include <stdio.h>
#include <queue.h>


int main()
{
    queue_s* q = queue_create(3);

    queue_enqueue(q, "1");
    queue_enqueue(q, "2");
    queue_enqueue(q, "3");
    queue_enqueue(q, "4"); // discarded, exceed the capacity

    size_t size = q->size;
    printf("size of queue: %zu\n", size);

    for (int i = 0; i < size; ++i)
    {
        printf("%s ", (char*)queue_dequeue(q));
    }

    queue_destroy(&q);

    return 0;
}

