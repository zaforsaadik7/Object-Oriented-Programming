#include<iostream>
using namespace std;
class A
{
public:
    virtual void show()
    {
        cout<<"Euler circuit is a circuit containing all the edges of a graph."<<endl;
    }

};
class C:virtual public A
{

};

class D:virtual public A
{

};

class E: public C,public D
{

};

int main()
{
    E ob1;
    ob1.show();
    return 0;
}
