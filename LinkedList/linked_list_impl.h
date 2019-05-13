#ifndef LINKED_LIST_IMPL_H
#define LINKED_LIST_IMPL_H

#include <iostream>

using std::ostream;

template<typename T>
class Node
{
public:
    T           m_data;
    Node<T>*	m_next_node;

    Node(const T& data = NULL, Node<T>* next_node = nullptr)
        :
        m_data(data),
        m_next_node(next_node)
    {
    }
};

template <typename T>
class LinkedList
{

private:
    Node<T>*            m_head;
    unsigned int		m_length; //the number of node

public:
    LinkedList();
    ~LinkedList();

    T&              Get(const int position) const;
    bool			Set(const int position, const T& data);
    bool            Search(const T& data);

    bool			Push(const T& data); //Add node at beginning
    bool			Push(const int position, const T& data);

    bool			Pop(); //Delete first node
    bool			Pop(const int position);

    unsigned int    Size()	const{return m_length;}// return length
    bool			Empty() const{return m_head == nullptr;}

    void			Clear();

    friend ostream& operator<<(ostream& os, const LinkedList<T>& linked_list)
    {
        if (linked_list.Empty())
        {
            os << "This linked list is empty." << std::endl;
        }
        else
        {
            os << "------------------------------------" << std::endl;
            Node<T>* node = linked_list.m_head;
            int pos = 0;

            do
            {
                os << "position: " << pos++ <<", data: " << node->m_data << std::endl;
                node = node->m_next_node;
            }while(node != nullptr);

            os << "------------------------------------" << std::endl;
        }

        return os;
    }
};

#endif // LINKED_LIST_IMPL_H
