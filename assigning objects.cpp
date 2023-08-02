#include<iostream>
using namespace std;

class samp
{
    int a,b;
public:
    void set(int i, int j)
    {
        a= i;
        b=j;

    }
    int show()
    {
        cout<<a<<" "<<b<<endl;
    }
};

int main()
{
    samp ob1, ob2;

    ob1.set(4,6);
    ob1.show();
    ob2= ob1;
    ob2.show();
    ob1.set(6,7);
    ob1.show();
    ob2.show();

    return 0;

}
