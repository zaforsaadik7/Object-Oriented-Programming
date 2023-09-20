#include<iostream>
using namespace std;

int main()
{
    int n, c1,c2=0;
    cin>>n;
    int s[3];
    for(int i=0; i<n; i++)
    {
        c1=0;
        cin>>s[0]>>s[1]>>s[2];
        for(int j=0; j<3; j++)
        {

            if(s[j]==1)
                c1+=1;
        }
        if(c1>1)
            c2+=1;
    }
    cout<<c2;
    return 0;
}
