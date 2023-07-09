#include<iostream>
using namespace std;
int main()
{
    int n, sum;
    sum=0;
    cout<<"Enter the value of n:";
    cin>>n;
    int i=1;
    while(i<=n)
    {
        sum+= i;
        i++;
    }
    cout<<"Sum of the series is "<<sum;
    return 0;
}
