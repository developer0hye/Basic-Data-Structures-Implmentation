#include <iostream>
#include "stack_impl.h"

#define EMPTY_INDEX             -1
#define BUF_MINIMUM_CAPACITY    2

template<class T>
Stack<T>::Stack()
    :
    buf_(nullptr),
    buf_size_(0),
    buf_maximum_capacity_(0),
    buf_minimum_capacity_(0),
    top_(EMPTY_INDEX)
{
}

template<class T>
Stack<T>::~Stack()
{
    Clear();
}

template<class T>
void Stack<T>::Pop()
{
    if (!Empty()) {
        top_        -= 1;
        buf_size_   -= 1;
        CheckBufMinimumCapacity();
    }
}

template<class T>
void Stack<T>::Push(T &data)
{
    if (Empty())
        Init();

    top_        += 1;
    buf_size_   += 1;

    buf_[top_]  = data;

    CheckBufMaximumCapacity();
}

template<class T>
T& Stack<T>::Top()
{
    return buf_[top_];
}

template<class T>
void Stack<T>::CheckBufMaximumCapacity()
{
    if (buf_size_ == buf_maximum_capacity_) {
        buf_minimum_capacity_ = buf_maximum_capacity_ / kStackBufCapacityRatio;
        buf_maximum_capacity_ = buf_maximum_capacity_ * kStackBufCapacityRatio;
        ReallocateBuf(buf_maximum_capacity_);
    }
}

template<class T>
void Stack<T>::CheckBufMinimumCapacity()
{
    if (buf_size_ > BUF_MINIMUM_CAPACITY &&
        buf_size_ == buf_minimum_capacity_) {

        ReallocateBuf(buf_minimum_capacity_);
        buf_maximum_capacity_ = buf_maximum_capacity_ / kStackBufCapacityRatio;
        buf_minimum_capacity_ = buf_minimum_capacity_ / kStackBufCapacityRatio;
    }
}

template<class T>
void Stack<T>::ReallocateBuf(int size)
{
    T* new_buf = new T[size];

    std::copy(buf_, buf_ + buf_size_, new_buf);
    delete [] buf_;

    buf_ = new_buf;
}

template<class T>
bool Stack<T>::Empty()
{
    return (top_ == EMPTY_INDEX);
}

template<class T>
void Stack<T>::Init()
{
    if (buf_ != nullptr)
        delete [] buf_;

    top_                    = EMPTY_INDEX;
    buf_size_               = 0;
    buf_maximum_capacity_   = BUF_MINIMUM_CAPACITY;
    buf_minimum_capacity_   = BUF_MINIMUM_CAPACITY;
    buf_                    = new T[buf_maximum_capacity_];
}

template<class T>
void Stack<T>::Clear()
{
    if (buf_ != nullptr)
    {
        delete[] buf_;
        buf_ = nullptr;
    }
    top_ = EMPTY_INDEX;
}
