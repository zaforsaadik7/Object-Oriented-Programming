#include<iostream>
using namespace std;

class myclass
{
    int a;
public:
    myclass(int x);
    int get();
};
myclass::myclass(int x)
{
    a=x;
}
int myclass::get()
{
    return a;
}
int main()
{
    myclass ob(120);
    myclass *p;
    p=&ob;
    cout<<"value of the object:"<<ob.get()<<endl;
    cout<<"value of the attribute of this pointer:"<<p->get()<<endl;
    cout<<"value of the pointer:"<<p<<endl;
    cout<<"address of the memory of the object:"<<&ob<<endl;
    return 0;
}
