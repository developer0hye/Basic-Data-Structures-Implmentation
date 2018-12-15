#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> stack;

    for(int i = 0; i < 1000; i++)
    {
        stack.Push(i);
    }

    while(!stack.Empty())
    {
        std::cout << stack.Top() << std::endl;
        stack.Pop();
    }

    return 0;
}
