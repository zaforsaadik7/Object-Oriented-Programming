#include<iostream>
using namespace std;
inline int even(int x)
{
    return !(x%2);
}

int main()
{
    int x;
    cout<<"enter number:"<<endl;
    cin>>x;

    if(even(x))
        cout<<x<<" is an even number."<<endl;

    else
        cout<<x<<" is an odd number."<<endl;
        return 0;
}
