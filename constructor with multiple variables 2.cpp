#include<iostream>
using namespace std;

class myclass
{
    int a;
    int b;
public:
    myclass(int x,int y);
    void show();
};

myclass::myclass(int x, int y)
{
    cout<<"in this constructor: ";
     a=x;
     b=y;
}

void myclass::show()
{
     cout<<a<<' '<<b<<endl;
}
int main ()
{
    int x,y;
    cout<<"enter two integers:";
    cin>>x>>y;
    myclass ob(x,y);
    ob.show();
    return 0;
}
