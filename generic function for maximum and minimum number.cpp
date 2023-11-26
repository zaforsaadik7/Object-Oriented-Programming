#include<iostream>
using namespace std;

template <class t> t maximum(t x[], int size)
{
    t temp= x[0];
    for(int i=1; i<size; i++)
    {
        if(x[i]>temp)
            temp= x[i];
    }

    return temp;
}

template <class t> t minimum(t x[], int size)
{
    t temp= x[0];
    for(int i=1; i<size; i++)
    {
        if(x[i]<temp)
            temp= x[i];
    }
    return temp;
}

int main()
{
    int s[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<maximum(s, 10)<<endl;
    cout<<minimum(s, 10)<<endl;
}
