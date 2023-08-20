#include<iostream>
using namespace std;

class samp
{
    int n;
public:
    samp(int n)
    {
        cout<<"Constructing."<<endl;
        this->n= n;
    }
    ~samp()
    {
        cout<<"Destructing."<<endl;
    }
    int get()
    {
        return n;
    }
};

int squareIT(samp ob)
{
   return ob.get()*ob.get();
}

int main()
{
    samp ob1(20);
    cout<<squareIT(ob1)<<endl;
    return 0;
}
