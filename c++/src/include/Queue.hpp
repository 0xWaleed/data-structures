

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdint>
#include <utility>

template<typename T>
class Queue
{
public:
    explicit Queue(size_t capacity);

    Queue(const Queue& rhs);

    Queue<T>& operator=(const Queue<T>& rhs);

    Queue(Queue&& rhs) noexcept;

    Queue<T>& operator=(Queue<T>&& rhs) noexcept;

    ~Queue();

    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t capacity() const;

    bool enqueue(T item);

    T dequeue();

    T peek();

private:
    size_t m_capacity;

    size_t m_size;

    T* m_items;
};

template<typename T>
Queue<T>::Queue(size_t capacity):
        m_capacity(capacity),
        m_size(0),
        m_items(new T[capacity])
{

}

template<typename T>
Queue<T>::Queue(const Queue<T>& rhs)
{
    this->m_size = rhs.size();
    this->m_capacity = rhs.capacity();
    this->m_items = new T[this->m_capacity];
    for (int i = 0; i < this->size(); ++i)
    {
        this->m_items[i] = rhs.m_items[i];
    }
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    this->m_size = rhs.size();
    this->m_capacity = rhs.capacity();
    this->m_items = new T[this->m_capacity];
    for (int i = 0; i < this->size(); ++i)
    {
        this->m_items[i] = rhs.m_items[i];
    }
    return *this;
}

template<typename T>
Queue<T>::Queue(Queue<T>&& rhs) noexcept
{
    this->m_items = std::move(rhs.m_items);
    this->m_size = rhs.size();
    this->m_capacity = rhs.capacity();
    rhs.m_capacity = 0;
    rhs.m_size = 0;
    rhs.m_items = nullptr;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& rhs) noexcept
{
    this->m_items = std::move(rhs.m_items);
    this->m_size = rhs.size();
    this->m_capacity = rhs.capacity();
    rhs.m_capacity = 0;
    rhs.m_size = 0;
    rhs.m_items = nullptr;
    return *this;
}

template<typename T>
Queue<T>::~Queue()
{
    delete[] m_items;
}

template<typename T>
size_t Queue<T>::size() const
{
    return this->m_size;
}

template<typename T>
size_t Queue<T>::capacity() const
{
    return this->m_capacity;
}

template<typename T>
bool Queue<T>::enqueue(T item)
{
    if (this->size() >= this->capacity())
    {
        return false;
    }
    this->m_items[this->m_size++] = item;
    return true;
}

template<typename T>
T Queue<T>::dequeue()
{
    if (this->size() == 0)
    {
        return T();
    }
    T value = this->m_items[0];
    for (int i = 0; i < this->size() - 1; ++i)
    {
        this->m_items[i] = this->m_items[i + 1];
    }
    this->m_size--;
    return value;
}

template<typename T>
T Queue<T>::peek()
{
    return this->m_items[0];
}

#endif //QUEUE_HPP
