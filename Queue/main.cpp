#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> queue;

    for(int i = 0; i < 100; i++)
    {
        std::cout << "enqueue: " << i << std::endl;
        queue.Enqueue(i);
    }

   while(!queue.Empty())
   {
       std::cout << "dequeue: " << queue.Head() << std::endl;
       queue.Dequeue();
   }

    return 0;
}
