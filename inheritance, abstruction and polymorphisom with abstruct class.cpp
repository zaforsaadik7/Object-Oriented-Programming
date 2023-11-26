#include<iostream>
using namespace std;

class number
{
    int x;
public:
    number(int x=0)
    {
        this-> x= x;
    }
    int getX()
    {
        return x;
    }

    virtual void display()=0;
};

class outhex: public number
{
public:
    outhex(int x): number(x)
    {

    }
    void display()
    {
        cout<<hex<<getX()<<endl;
    }
};

class outoct: public number
{
public:
    outoct(int x): number(x)
    {

    }
    void display()
    {
        cout<<oct<<getX()<<endl;
    }
};

int main()
{
    outhex n1(14);
    outoct n2(12);

    number *p;
    p= &n1;
    p->display();
    p= &n2;
    p->display();
    return 0;
}
