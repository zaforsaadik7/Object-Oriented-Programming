#include<iostream>
using namespace std;

template <class X> void swaper(X &x, X &y)
{
    X temp= x;
    x= y;
    y= temp;
    cout<<"after swaping: "<<x<<"  "<<y<<endl;
}

void swaper(int x, int y)
{
    cout<<"The inputed values are integers now."<<endl;
}

int main()
{
    int x=3, y=4;
    float a=3.4, b=6.7;
    swaper(x,y);
    swaper(a,b);
    return 0;
}
