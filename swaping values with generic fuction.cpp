#include<iostream>
using namespace std;

template <class type1> void swaper(type1 &x, type1 &y)
{
    type1 temp= x;
    x= y;
    y= temp;
}

int main()
{
    int x=2, y=3;
    swaper(x, y);
    cout<<x<<" "<<y<<endl;
}
