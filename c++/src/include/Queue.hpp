

#ifndef QUEUE_HPP
#define QUEUE_HPP

template<typename T>
class Queue
{
public:
    explicit Queue(size_t capacity);

    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t capacity() const;

    bool enqueue(T item);

    T dequeue();

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
    T value = this->m_items[0];
    for (int i = 0; i < this->size() - 1; ++i)
    {
        this->m_items[i] = this->m_items[i + 1];
    }
    this->m_size--;
    return value;
}

#endif //QUEUE_HPP
