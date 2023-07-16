#include<iostream>
using namespace std;


class myclass
{
    int a;

public:
    myclass();
    ~myclass();
    void show();
};

myclass::myclass()
{
    cout<<"in this constructor: "<<endl;
    a=10;

}

myclass::~myclass()
{
    cout<<"destructed."<<endl;
}

void myclass::show()
{
    cout<<a<<endl;
}
int main()
{
    myclass ob;
    ob.show();

    return 0;
}
