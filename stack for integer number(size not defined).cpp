#include <iostream>
using namespace std;

class Stack
{
    int size;
    int *stck;
    int tos;

public:
    Stack(int size);
    ~Stack();
    int pop();
    void push(int x);
};

Stack::Stack(int size)
{
    this->size = size;
    stck = new int[size];
    cout << "Constructing a stack\n";
    tos = 0;
}

Stack::~Stack()
{
    cout << "destructing" << endl;
    delete[] stck;
}

void Stack::push(int x)
{
    if (tos == size)
    {
        cout << "Stack is full\n";
        return;
    }
    stck[tos] = x;
    tos++;
}

int Stack::pop()
{
    if (tos == 0)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    tos--;
    return stck[tos];
}

int main()
{
    int size;
    cout << "enter size for stack: ";
    cin >> size;
    Stack s1(size);
    for(int i=0; i<size; i++)
    {
        s1.push(i+1);
    }

    for (int i =size-1; i>=0; i--)
        cout << "Pop s1: " << s1.pop() <<"\n";
    return 0;
}
