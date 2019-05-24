#include "linked_list.h"

#include "linked_list_impl.h"
#include <string>

template<typename T>
LinkedList<T>::LinkedList():
    m_head(nullptr),
    m_tail(nullptr),
    m_length(0)
{
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Clear();
}

template<typename T>
T &LinkedList<T>::Get(const int position) const
{
    if(position < 0 || position > m_length)
    {
        std::string error_msg = "out of range: Indexed position is "
                                + std::to_string(position)
                                + ", but the length of list is " + std::to_string(m_length) + "." ;
        throw std::out_of_range(error_msg);
    }
    else if(position == m_length - 1)
    {
        return m_tail->m_data;
    }
    Node<T>* node = m_head;
    for (int count = 0; count < position; count++)
        node = node->m_next_node;

    return node->m_data;
}

template<typename T>
bool LinkedList<T>::Set(const int position, const T &data)
{
    if(position < 0 || position > m_length)
        return false;

    Node<T>* node = m_head;
    for (int count = 0; count < position; count++)
        node = node->m_next_node;

    node->m_data = data;
    return true;
}

template<typename T>
bool LinkedList<T>::Search(const T &data)
{
    if(m_head == nullptr)
        return false;

    Node<T>* node = m_head;
    do
    {
        if(node->m_data == data)
            return true;
        node = node->m_next_node;
    }while(node != nullptr);

    return false;
}

template<typename T>
bool LinkedList<T>::Push(const T &data) //Add node at beginning
{
    Node<T>* new_node = new Node<T>(data, nullptr);

    if(m_head != nullptr)
    {
        m_tail->m_next_node = new_node;
        m_tail = new_node;
    }
    else
    {
        m_head = m_tail = new_node;
    }

    m_length++;
    return true;
}

template<typename T>
bool LinkedList<T>::Push(int position, const T &data)
{
    if(position > m_length || position < 0)
    {
        return false;
    }
    else if(position == 0) //Add node at beginning
    {
        m_head = new Node<T>(data, m_head);
    }
    else if(position < m_length) //Add node in middle
    {
        Node<T>* node = m_head;

        for(int count = 0; count < position - 1; count++)
            node = node->m_next_node;

        node->m_next_node = new Node<T>(data, node->m_next_node);
    }
    else // = else if(position == m_length) ,Add node at end
    {
        return Push(data);
    }

    m_length++;
    return true;
}

template<typename T>
bool LinkedList<T>::Pop() //Delete last node
{
    if(m_tail == nullptr)
        return false;

    Node<T>* node = m_head;

    while(node->m_next_node != m_tail)
        node = node->m_next_node;

    delete node->m_next_node;
    node->m_next_node = nullptr;

    m_tail = node;

    m_length--;
    return true;
}

template<typename T>
bool LinkedList<T>::Pop(const int position)
{
    if(m_head == nullptr || m_tail == nullptr || position >= m_length || position < 0)
    {
        return false;
    }
    else if(position == 0) //Delete first node
    {
        Node<T>* cur_head_node = m_head;
        m_head = m_head->m_next_node;

        if(m_head == nullptr) m_tail = nullptr;
        delete cur_head_node;
    }
    else if(position < m_length - 1) //Delete node in middle
    {
        Node<T>* node = m_head;
        Node<T>* delete_node;

        for(int count = 0; count < position - 1; count++)
            node = node->m_next_node;

        delete_node = node->m_next_node;
        node->m_next_node = delete_node->m_next_node;

        delete delete_node;
    }
    else// = else if(position == m_length - 1), Delete node at end
    {
        return Pop();
    }

    m_length--;
    return true;
}

template<typename T>
void LinkedList<T>::Clear()
{
    while(m_head != nullptr)
        Pop(0);
}
