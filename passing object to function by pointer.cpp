#include<iostream>
using namespace std;
class samp
{
    int i;
public:
    samp(int i)
    {
        this-> i= i;
    }
    ~samp()
    {
        cout<<"Destructing."<<endl;
    }

    int get()
    {
        return i;
    }

    int set(int i)
    {
        this-> i= i;
    }
};

int squareit(samp *p)
{
    p->set(p->get()*p->get());
    cout<<"the changed value of the object is: "<<p->get()<<endl;
}
int main()
{
    samp ob(4);
    cout<<"original value of the object: "<<ob.get()<<endl;
    squareit(&ob);

    return 0;
}

