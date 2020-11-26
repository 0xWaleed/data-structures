

#ifndef STACK_HPP
#define STACK_HPP


#include <cstdint>
#include <vector>

#define STACK_BLOCK_SIZE 8

template<typename T = int>
class Stack
{
public:

    static const int DEFAULT_MAX_SIZE = 0;

    Stack();

    explicit Stack(uint32_t maxSize);

    Stack(const Stack& rhs);

    Stack& operator=(const Stack& rhs);

    Stack(Stack&& rhs) noexcept;

    Stack& operator=(Stack&& rhs) noexcept;

    ~Stack();

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] bool isFull() const;

    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t maxSize() const;

    void push(const T& item);

    [[nodiscard]] T peek();

    T pop();

private /* methods */:
    void resizeItemsBuffer();

    [[nodiscard]] bool needsReAllocation() const;

    [[nodiscard]] bool isMaxSizeApplicable() const;

private:
    T* m_items;

    size_t m_maxSize = DEFAULT_MAX_SIZE;

    size_t m_size;
};

template<typename T>
Stack<T>::Stack(): Stack::Stack(DEFAULT_MAX_SIZE)
{

}

template<typename T>
Stack<T>::Stack(uint32_t maxSize):
        m_maxSize{ maxSize },
        m_size{ 0 },
        m_items{ new T[STACK_BLOCK_SIZE] }
{

}

template<typename T>
Stack<T>::Stack(const Stack& rhs)
{
    size_t rhsSize = rhs.size();
    this->m_items = new T[rhsSize];
    std::copy(rhs.m_items, rhs.m_items + rhsSize, this->m_items);
    this->m_size = rhsSize;
    this->m_size = rhsSize;
    this->m_maxSize = rhs.maxSize();
}


template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

    size_t rhsSize = rhs.size();
    this->m_items = new T[rhsSize];
    std::copy(rhs.m_items, rhs.m_items + rhsSize, this->m_items);
    this->m_size = rhsSize;
    this->m_size = rhsSize;
    this->m_maxSize = rhs.maxSize();
    return *this;
}

template<typename T>
Stack<T>::Stack(Stack&& rhs) noexcept
{
    if (&rhs == this)
    {
        return;
    }

    this->m_size = rhs.size();
    this->m_items = rhs.m_items;
    this->m_maxSize = rhs.maxSize();

    rhs.m_size = 0;
    rhs.m_items = nullptr;
    rhs.m_maxSize = 0;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& rhs) noexcept
{
    if (&rhs == this)
    {
        return *this;
    }

    this->m_size = rhs.size();
    this->m_items = rhs.m_items;
    this->m_maxSize = rhs.maxSize();

    rhs.m_size = 0;
    rhs.m_items = nullptr;
    rhs.m_maxSize = 0;

    return *this;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return this->size() == 0;
}

template<typename T>
bool Stack<T>::isFull() const
{
    return this->isMaxSizeApplicable() && this->size() >= this->maxSize();
}

template<typename T>
bool Stack<T>::isMaxSizeApplicable() const
{
    return maxSize() != 0;
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
    if (this->isFull())
    {
        return;
    }

    if (this->needsReAllocation())
    {
        this->resizeItemsBuffer();
    }

    this->m_items[this->m_size++] = item;
}


template<typename T>
bool Stack<T>::needsReAllocation() const
{
    return (size() == 0 ? 1 : size()) % STACK_BLOCK_SIZE == 0;
}

template<typename T>
T Stack<T>::peek()
{
    if (this->size() == 0)
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
    return v;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] m_items;
}

template<typename T>
void Stack<T>::resizeItemsBuffer()
{
    auto newBuffer = new T[this->size() + STACK_BLOCK_SIZE];
    std::move(m_items, m_items + this->size(), newBuffer);
    delete[] m_items;
    m_items = newBuffer;
}


#endif //STACK_HPP
