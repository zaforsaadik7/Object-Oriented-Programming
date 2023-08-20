
#include<iostream>
using namespace std;
class myclass
{
    int n, d;
public:
    myclass(int n, int d)
    {
        this->n= n;
        this->d= d;
    }
    friend int isfactor(myclass ob);
};
int isfactor(myclass ob)
{
    if(!(ob.n% ob.d))
    {
        return 1;
    }
    else{ return 0;}

}

int main()
{
    myclass ob1(6,3);
    if(isfactor(ob1))
    {
        cout<< "devisible"<<endl;
    }
    else
    {
        cout<<"not devisible"<<endl;
    }
    return 0;

}
