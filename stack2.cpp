#include <iostream>
using namespace std;
#define SIZE 10

class Stack {
    char stck[SIZE];
    int tos;
public:
    Stack();
    char pop();
    void push(char ch);
};

Stack::Stack() {
    cout << "Constructing a stack\n";
    tos = -1;
}

void Stack::push(char ch) {
    if (tos == SIZE - 1) {
        cout << "Stack is full\n";
        return;
    }
    tos++;
    stck[tos] = ch;
}

char Stack::pop() {
    if (tos <= -1) {
        cout << "Stack is empty\n";
        return 0;
    }
    char ch = stck[tos];
    tos--;
    return ch;
}

int main() {
    Stack s1, s2;
    int i;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s2 = s1;
    for (i = 0; i < 3; i++)
        cout << "Pop s1: " << s1.pop() << "\n";
    for (i = 0; i < 3; i++)
        cout << "Pop s2: " << s2.pop() << "\n";
    return 0;
}
