

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cstdint>
#include <utility>
#include "SinglyNode.hpp"

template<typename T = int>
class LinkedList
{
public:
    [[nodiscard]] size_t size() const;

    [[nodiscard]] SinglyNode<T>* head();

    void insert(T item);

    void insertAtBeginning(T item);

    SinglyNode<T>* find(T value);

    void deleteNodeByValue(T value);

private /* methods */:
    void assignNodeToHead(T item);

private:
    std::unique_ptr<SinglyNode<T>> m_head;
    SinglyNode<T>* m_tail;

    size_t m_size{};
};

template<typename T>
size_t LinkedList<T>::size() const
{
    return this->m_size;
}

template<typename T>
SinglyNode<T>* LinkedList<T>::head()
{
    return this->m_head.get();
}

template<typename T>
void LinkedList<T>::insert(T item)
{
    if (!this->m_head)
    {
        assignNodeToHead(item);
        return;
    }

    auto node = std::make_unique<SinglyNode<T>>();
    node->value = item;
    this->m_tail->next = std::move(node);
    this->m_tail = this->m_tail->next.get();
    this->m_size++;
}

template<typename T>
void LinkedList<T>::insertAtBeginning(T item)
{
    if (this->m_head == nullptr)
    {
        assignNodeToHead(item);
        return;
    }

    auto node = std::make_unique<SinglyNode<T>>();
    node->value = item;

    node->next = std::move(this->m_head);
    this->m_head = std::move(node);
    this->m_size++;
}

template<typename T>
SinglyNode<T>* LinkedList<T>::find(T value)
{
    auto node = this->head();
    while (node)
    {
        if (value == node->value)
        {
            return node;
        }
        node = node->next.get();
    }

    return nullptr;
}

template<typename T>
void LinkedList<T>::deleteNodeByValue(T value)
{
    auto n = this->head();
    SinglyNode<T>* prev = nullptr;
    SinglyNode<T>* next = nullptr;

    while (n)
    {
        if (n->value == value)
        {
            if (prev != nullptr)
            {
                prev->next = std::move(n->next);
                this->m_size--;
                break;
            }

            if (n->next != nullptr)
            {
                this->m_head = std::move(n->next);
                this->m_size--;
                break;
            }

            this->m_size--;
            break;
        }
        prev = n;
        n = n->next.get();
    }
}

template<typename T>
void LinkedList<T>::assignNodeToHead(T item)
{
    m_head = std::make_unique<SinglyNode<T>>();
    m_head->value = item;
    m_tail = m_head.get();
    m_size++;
}


#endif //LINKEDLIST_HPP
