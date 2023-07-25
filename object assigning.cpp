
#include<iostream>

using namespace std;

class object
{
    int a,b;
public:
    void set(int i, int j)
    {
        a=i;
        b=j;

    }
    void show()
    {
        cout<<a<<' '<<b<<endl;
    }
};

int main()
{
    object ob1, ob2;
    ob1.set(4,5);
    ob1.show();
    ob2=ob1;
    ob2.show();

    ob1.set(5,9);
    ob1.show();
    ob2.show();

    return 0;
}
