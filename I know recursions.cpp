#include<iostream>
#include<algorithm>
using namespace std;

void callerCallee(int n,int p,long long k)
{
    if (k>0&&k<=n)
    {
        cout <<"Case "<<k<<": "<<k-1<<" "<<k-2<<endl;
    }
    else
    {
        long long A=n;
        for (int i=0; i<k; i++)
        {
            long long B=0;
            if (A>=p)
            {
                for(int j=1; j<=p; j++)
                {
                    B+=min(A-j,k);
                }
            }
            else
            {
                for(int j=1; j<=A; j++)
                {
                    B+=min(j,k);
                }
            }
            if (B==k)
            {
                cout<<"Case "<<k<<": "<<A<<" "<<A-p<<endl;
                return;
            }
            A--;
        }
        cout<<"Case "<<k<<": Invalid"<<endl;
    }
}
int main()
{
    int D;
    cin>>D;
    for (int i=1;i<=D;i++)
    {
        int n,p;
        long long k;
        cin >>n>>p>>k;
        callerCallee(n,p,k);
    }
    return 0;
}

