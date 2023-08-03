#include<iostream>
using namespace std;

class samp
{
    int a;
public:
    samp(int i);
    int getA();
};
samp::samp(int i)
{
    a= i;

}
int samp::getA()
{
    return a;
}
square(samp ob)
{
    return ob.getA()* ob.getA();

}
int main()
{
    samp ob1(6);
    cout<<square(ob1)<<endl;
    return 0;

}
