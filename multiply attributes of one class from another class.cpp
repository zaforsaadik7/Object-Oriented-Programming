#include<iostream>
using namespace std;

class A
{
    int a, b,c;
public:
    A(int x, int y, int z) {a= x; b= y; c= z;}

    int getA()
    {
        return a;
    }

    int getB()
    {
        return b;
    }

    int getC()
    {
        return c;
    }

    friend void connector(A &obj);
};

class B
{
public:
    void multiply(int &a, int &b, int &c)
    {
        a= a*10;
        b= b*10;
        c= c*10;

    }

};

void connector(A &obj)
{
    B ob;
    ob.multiply(obj.a, obj.b, obj.c);
}

int main()
{
    A ob1(2,3,4);
    connector(ob1);
    cout<<ob1.getA()<<" "<<ob1.getB()<<" "<<ob1.getC();
    return 0;
}
