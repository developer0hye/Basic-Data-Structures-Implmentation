#include <iostream>
#include <string>

#include "linked_list.h"

using namespace std;

int main()
{

    LinkedList<int> linkedList;

    cout << "Initialization (data)" << endl << endl;

    cout << "Add node at beginning (1)" << endl << endl;
    cout << "Add node at beginning (3)" << endl << endl;
    cout << "Add node at beginning (4)" << endl << endl;
    cout << "Add node at beginning (6)" << endl << endl;

    linkedList.Push(1);
    linkedList.Push(3);
    linkedList.Push(4);
    linkedList.Push(6);

    cout << "Size of linked list = " << linkedList.Size() << endl;
    cout << linkedList << endl;

    cout << "Test Adding node in middle (position, data)" << endl << endl;
    cout << "Add node in middle (1, 2)" << endl << endl;
    cout << "Add node in middle (4, 5)" << endl << endl;

    linkedList.Push(1, 2);
    linkedList.Push(4, 5);

    cout << "Size of linked list = " << linkedList.Size() << endl;
    cout << linkedList << endl;

    cout << "Test pop(position)" << endl << endl;
    cout << "pop (0)" << endl << endl;
    cout << "pop (3)" << endl << endl;
    cout << "pop ()" << endl << endl;

    linkedList.Pop(0);
    linkedList.Pop(3);
    linkedList.Pop();

    cout << "Size of linked list = " << linkedList.Size() << endl;
    cout << linkedList << endl;

    cout << "Test get and set function" << endl << endl;

    cout << "linkedList.get(1)  = " << linkedList.Get(1) << endl;

    linkedList.Set(1, 50);

    cout << "linkedList.set(1, 50)" << endl;
    cout << "linkedList.get(1)  = " << linkedList.Get(1) << endl << endl;

    cout << "Test search function Search(data) (return value, 0: not exists, 1: exists)" << endl << endl;

    cout << "linkedList.Search(50)  = " << linkedList.Search(50) << endl;

    cout << "Test clear" << endl << endl;
    linkedList.Clear();

    cout << "Size of linked list  = " << linkedList.Size() << endl;
    cout << linkedList << endl;

    return 0;
}
