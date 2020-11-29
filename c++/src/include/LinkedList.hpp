

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cctype>
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

private:
    std::unique_ptr<SinglyNode<T>> m_head;
    size_t m_size;
};

template<typename T>
size_t LinkedList<T>::size() const
{
    return m_size;
}

template<typename T>
void LinkedList<T>::insert(T item)
{
    if (!this->m_head)
    {
        this->m_head = std::make_unique<SinglyNode<T>>();
        this->m_head->value = item;
        this->m_size++;
        return;
    }
    auto node = std::make_unique<SinglyNode<T>>();
    node->value = item;
    auto temp = this->m_head.get();
    while (temp)
    {
        if (temp->next == nullptr)
        {
            temp->next = std::move(node);
            break;
        }
        temp = temp->next.get();
    }
    this->m_size++;
}

template<typename T>
SinglyNode<T>* LinkedList<T>::head()
{
    return this->m_head.get();
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
void LinkedList<T>::insertAtBeginning(T item)
{
    if (this->m_head == nullptr)
    {
        auto node = std::make_unique<SinglyNode<T>>();
        node->value = item;
        this->m_head = std::move(node);
        this->m_size++;
        return;
    }

    auto node = std::make_unique<SinglyNode<T>>();
    node->value = item;

    node->next = std::move(this->m_head);
    this->m_head = std::move(node);
    this->m_size++;
}

template<typename T>
void LinkedList<T>::deleteNodeByValue(T value)
{
    int i = 0;

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
                break;
            }

            if (n->next != nullptr)
            {
                m_head = std::move(n->next);
                break;
            }

            break;
        }
        prev = n;
        n = n->next.get();
    }
}


#endif //LINKEDLIST_HPP
