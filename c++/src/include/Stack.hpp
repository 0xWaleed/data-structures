

#ifndef STACK_HPP
#define STACK_HPP


#include <cstdint>


template<typename T = int>
class Stack
{
public:

    static const int DEFAULT_MAX_SIZE = 64;

    Stack();

    explicit Stack(uint32_t maxSize);

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] bool isFull() const;

    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t maxSize() const;

    void push(const T& item);

    [[nodiscard]] T peek();

    T pop();

private:
    std::unique_ptr<T[]> m_items;

    size_t m_maxSize;

    size_t m_size;

    bool m_isEmpty;

    bool m_isFull;
};

template<typename T>
Stack<T>::Stack(): Stack::Stack(DEFAULT_MAX_SIZE)
{

}

template<typename T>
Stack<T>::Stack(uint32_t maxSize):
        m_maxSize(maxSize),
        m_size(0),
        m_isEmpty(true),
        m_isFull(false),
        m_items(std::make_unique<T[]>(maxSize))
{

}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return this->m_isEmpty;
}

template<typename T>
bool Stack<T>::isFull() const
{
    return this->m_isFull;
}

template<typename T>
size_t Stack<T>::size() const
{
    return this->m_size;
}

template<typename T>
size_t Stack<T>::maxSize() const
{
    return this->m_maxSize;
}

template<typename T>
void Stack<T>::push(const T& item)
{
    if (this->size() >= this->maxSize())
    {
        return;
    }
    this->m_isEmpty = false;
    this->m_items[this->m_size++] = item;
    this->m_isFull = this->size() == this->maxSize();
}

template<typename T>
T Stack<T>::peek()
{
    if (size() == 0)
    {
        return T();
    }
    return this->m_items[this->size() - 1];
}

template<typename T>
T Stack<T>::pop()
{
    if (this->size() == 0)
    {
        return T();
    }
    T v = this->m_items[this->m_size-- - 1];
    this->m_isEmpty = this->size() == 0;
    this->m_isFull = false;
    return v;
}

#endif //STACK_HPP
