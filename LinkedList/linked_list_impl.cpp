#include "linked_list_impl.h"

template<typename T>
LinkedList<T>::LinkedList():
    m_head(nullptr),
    m_length(0)
{
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Clear();
}

template<typename T>
T LinkedList<T>::Get(const int position) const
{
    if(position < 0 || position > m_length)
    {
        return NULL;
    }
    else
    {
        Node<T>* node = m_head;
        for (int count = 0; count < position; count++)
            node = node->m_next_node;

        return node->m_data;
    }
}

template<typename T>
bool LinkedList<T>::Set(const int position, const T &data)
{
    if(position < 0 || position > m_length)
    {
        return false;
    }
    else
    {
        Node<T>* node = m_head;
        for (int count = 0; count < position; count++)
            node = node->m_next_node;

        node->m_data = data;
        return true;
    }
}

template<typename T>
bool LinkedList<T>::Search(const T &data)
{
    if(m_head == nullptr) return false;

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
    m_head = new Node<T>(data, m_head);
    m_length++;
    return true;
}

template<typename T>
bool LinkedList<T>::Push(int position, const T &data)
{
    if(position > m_length)
    {
        return false;
    }
    else if(position == 0) //Add node at beginning
    {
        return Push(data);
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
        Node<T>* cur_node = m_head;

        while(cur_node->m_next_node != nullptr)
            cur_node = cur_node->m_next_node;

        cur_node->m_next_node = new Node<T>(data);
    }

    m_length++;
    return true;
}

template<typename T>
bool LinkedList<T>::Pop() //Delete first node
{
    if(m_head == nullptr)
        return false;

    Node<T>* cur_head_node = m_head;
    m_head = m_head->m_next_node;

    delete cur_head_node;

    m_length--;
    return true;
}

template<typename T>
bool LinkedList<T>::Pop(const int position)
{
    if(position >= m_length)
    {
        return false;
    }
    else if(position == 0) //Delete first node
    {
        return Pop();
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
        Node<T>* node = m_head;

        for(int count = 0; count < position - 1; count++)
            node = node->m_next_node;

        delete node->m_next_node;
        node->m_next_node = nullptr;
    }

    m_length--;
    return true;
}

template<typename T>
void LinkedList<T>::Clear()
{
    while(m_head != nullptr)
        Pop();
}

