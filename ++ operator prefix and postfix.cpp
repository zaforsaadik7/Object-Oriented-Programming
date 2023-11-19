#include<iostream>
using namespace std;

class Counter
{
public:
    int count;

    Counter() : count(0) {}

    // Prefix ++ overload
    Counter& operator++()
    {
        ++count;
        return *this;
    }

    // Postfix ++ overload
    Counter& operator++(int)
    {
        count++;
        return *this;
    }
};
int main()
{
    Counter counter;
    ++counter;
    cout<<counter.count<<endl;
    counter++;
    cout<<counter.count;
    return 0;
}
