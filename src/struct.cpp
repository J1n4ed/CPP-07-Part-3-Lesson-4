#include "../headers/struct.h"

// ListNode::ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr) : value(value), prev(prev), next(next)
ListNode::ListNode(int value, ListNode* prev, ListNode* next) : value(value), prev(prev), next(next)
{
    if (prev != nullptr) 
        prev->next = this;
    if (next != nullptr) 
        next->prev = this;
}

bool List::Empty()
{ 
    // return m_size == 0; // == !
    bool is_empty = false;
    
    if (m_size == 0)
        is_empty = true;    

    return is_empty;
}

unsigned long List::Size()
{ 
    return m_size; 
}

void List::PushFront(int value)
{
    new ListNode(value, m_head, m_head->next);
    ++m_size;
}

void List::PushBack(int value)
{
    new ListNode(value, m_tail->prev, m_tail);
    ++m_size;
}

int List::PopFront()
{
    if (Empty()) throw std::runtime_error("list is empty");
    auto node = extractPrev(m_head->next->next);
    int ret = node->value;
    delete node;
    return ret;
}

int List::PopBack()
{
    if (Empty()) throw std::runtime_error("list is empty");
    auto node = extractPrev(m_tail);
    int ret = node->value;
    delete node;
    return ret;
}

void List::Clear()
{
    auto current = m_head->next;
    while (current != m_tail)
    {
        current = current->next;
        delete extractPrev(current);
    }
}

ListNode* List::extractPrev(ListNode* node)
{
    auto target = node->prev;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    --m_size;
    return target;
}