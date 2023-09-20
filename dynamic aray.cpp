#include<iostream>
using namespace std;

class samp
{
    int x;
    public:
        samp()
        {
            x=0;
        }
        samp(int c)
        {
            x=c;
        }
        int get_x()
        {
            return x;
        }

};

int main()
{
    samp ob(10);
    samp *p;
    p= new samp[10];
    if(!p)
    {
        cout<<"Allocation Error."<<endl;
        return 1;
    }

    for(int i=0;i<10;i++)
    {
        p[i]=ob;
    }
    for(int i=0;i<10;i++)
    {
        cout<<p[i].get_x()<<endl;
    }
    return 0;
}
