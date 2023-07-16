#include<iostream>
using namespace std;

class myclass
{
public:
    int a;
    void init();
    void show();
};
void myclass::init()
{
    a=10;
}

void myclass::show()
{
    cout<<a;
}

int main()
{
    myclass ob;
    ob.init();
    ob.show();

    return 0;
}
