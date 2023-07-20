//':' is a ternary operator. If a is greater than b aka the condition is true it'll return the first value or if it's false it'll return the other value.#include<iostream>
#include<iostream>
using namespace std;

class compair
{
    int a,b;
public:
    compair(int n,int m);
    int max();
};
compair::compair(int n, int m)
{
    a=n;
    b=m;
}
inline int compair::max()
{
  return a>b ? a:b;
}

int main()
{
    int a,b;
    cout<<"enter two number: ";
    cin>>a>>b;
    compair obj(a,b);
    if(obj.max()==a)
        cout<<a<<" is greater than "<<b<<endl;
    else
        cout<<b<<" is greater than "<<a<<endl;
    return 0;
}

