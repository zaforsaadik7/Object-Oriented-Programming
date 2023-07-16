#include<iostream>
using namespace std;

class myclass
{
    int a;

public:
    myclass();
    void show();
};

myclass::myclass()
{
    cout<<"in the constructor";
    a=10;
}

void myclass::show()
{
    cout<<a;
}

int main()
{
    myclass ob;

    ob.show();
    return 0;
}
