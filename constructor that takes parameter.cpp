
#include<iostream>
using namespace std;

class myclass
{
    int a;
public:
    myclass(int x);
    void show();
};

myclass::myclass(int x)
{
    cout<<"in this constructor: ";

    a=x;
}

void myclass::show()
{
    cout<<a<<endl;
}

int main()

{
    myclass ob(4);
    ob.show();

    return 0;
}
