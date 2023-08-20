#include<iostream>
using namespace std;

class samp
{
    int n;
public:
    samp(int n)
    {
        this-> n= n;
    }

    int get()
    {
        return n;
    }
};

int main()
{
    samp ob(120);
    samp *p;
    p= &ob;
    cout<<"value of the object: "<<ob.get()<<endl;
    cout<<"the value from the memory location: "<<p->get()<<endl;
    return 0;
}
