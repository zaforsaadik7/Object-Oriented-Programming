#include<iostream>
using namespace std;

class samp
{
    int a,b;
public:
    samp(int n,int m);
    int divisibility(int n,int m);
};
samp::samp(int n, int m)
{
    a=n;
    b=m;
}
inline int divisibility(int n,int m)
{
  return !(n%m);
}
int main()
{
    int a,b;
    cout<<"enter two number: ";
    cin>>a>>b;
    if(divisibility(a,b))
        cout<<a<<" is divisible by "<<b<<endl;
    else
        cout<<a<<" isn't divisible by "<<b<<endl;
    return 0;
}
