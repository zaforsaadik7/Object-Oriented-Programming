#include<iostream>
using namespace std;

class OpOverload
{
    int var1;
    int var2;
    int ID[3];
public:
    int sumID=0;
    OpOverload(int a, int b, int c[3])
    {
        var1=a;
        var2=b;
        for(int i=0; i<3; i++)
        {
            ID[i] = c[i];
            sumID += ID[i];
        }
    }
    void operator ++()
    {
        var1+=sumID;
        var2+=sumID;
    }
    void operator --()
    {
        var1-=sumID;
        var2-=sumID;
    }
    int get_v1()
    {
        return var1;
    }
    int get_v2()
    {
        return var2;
    }
    void display()
    {
        cout<<get_v1()<<" "<<get_v2()<<endl;
    }

};

int main()
{
    int arr[3] = {1, 2, 3};
    OpOverload b1(20,30,arr);
    ++b1;
    b1.display();

    OpOverload b2(20,30,arr);
    --b2;
    b2.display();
}
