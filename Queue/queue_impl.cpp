#include <iostream>
#include "queue_impl.h"

template<class T>
QueueNode<T>::QueueNode()
{
    next_ = nullptr;
}

template<class T>
QueueNode<T>::QueueNode(const T &data, QueueNode *next)
{
    data_ = data;
    next_ = next;
}

template<class T>
QueueNode<T>::~QueueNode()
{
    // next_ Delete 시에 Queue 클래스의 Dequeue 함수에서 Head 를 움직이는 과정에 문제 발생
}


template<class T>
Queue<T>::Queue()
    :
      head_(nullptr),
      tail_(nullptr)
{
}

template<class T>
Queue<T>::~Queue()
{
    Clear();
}

template<class T>
void Queue<T>::Dequeue()
{
    if(!Empty())
    {
        QueueNode<T>* tempHead = head_;
        head_ = head_->next_;

        delete tempHead;
    }
}

template<class T>
void Queue<T>::Enqueue(const T &data)
{
    QueueNode<T>* node  = new QueueNode<T>(data);

    if (Empty()) {
        head_ = node;
        tail_ = head_;
        //head_ 와 tail_ 이 같은 주소를 가리키게 되어 tail_ 이 변함에 따라 head_ 도 동시에 변함
        //tail_->next_ 접근 = head_->next_ 접근
    }
    else {
        tail_->next_    = node;
        tail_           = tail_->next_;
    }
}

template<class T>
T& Queue<T>::Head()
{
    return head_->data_;
}

template<class T>
bool Queue<T>::Empty() const
{
    return (head_ == nullptr);
}

template<class T>
void Queue<T>::Clear()
{
    while(!Empty())
    {
        Dequeue();
    }
}
