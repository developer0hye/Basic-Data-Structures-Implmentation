#ifndef STACK_IMPL_H
#define STACK_IMPL_H

const int kStackBufCapacityRatio = 2;

template<class T>
class Stack
{

public:
    Stack();
    ~Stack();

    void        Pop();
    void        Push(T& data);
    T&          Top();

    bool        Empty();

private:
    void        Init();
    void        Clear();

    void        CheckBufMaximumCapacity();
    void        CheckBufMinimumCapacity();

    void        ReallocateBuf(int size);

    T*          buf_;
    int         buf_size_;
    int         buf_maximum_capacity_;
    int         buf_minimum_capacity_;

    int         top_;
};

#endif // STACK__H
