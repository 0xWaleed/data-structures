#include <iostream>
#include <Queue.hpp>

int main()
{
    Queue<int> queue(3);

    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(3); //discarded, exceed capacity

    size_t size = queue.size();

    for (int i = 0; i < size; ++i)
    {
        std::cout << queue.dequeue() << std::endl;
    }

    return 0;
}

