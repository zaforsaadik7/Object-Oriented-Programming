#include<iostream>
using namespace std;

class samp
{
    int x;
public:
    samp(int x)
    {
        this-> x= x;

    }
    friend void operator --(samp& ob, int);
    int get_x()
    {
        return x;
    }


};

void operator --(samp& ob, int)
{
    ob.x--;
}

int main()
{
    samp ob(4);
    ob--;
    cout<<ob.get_x()<<endl;
    return 0;
}

