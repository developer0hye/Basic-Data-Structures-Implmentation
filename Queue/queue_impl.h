#ifndef QUEUE_IMPL_H
#define QUEUE_IMPL_H

template<class T>
class QueueNode
{
public:
    QueueNode();
    QueueNode(const T& data, QueueNode *next = nullptr);

    ~QueueNode();

    template<class> friend class Queue;

private:
    T           data_;
    QueueNode*  next_;
};

template<class T>
class Queue
{

public:
    Queue();
    ~Queue();

    void        Dequeue();
    void        Enqueue(const T& data);
    T&          Head();

    bool        Empty() const;

private:
    void        Clear();

    QueueNode<T>*  head_;
    QueueNode<T>*  tail_;
};

#endif // QUEUE_IMPL_H
