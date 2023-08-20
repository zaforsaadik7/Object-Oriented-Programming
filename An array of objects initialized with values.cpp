#include<iostream>
using namespace std;
class samp
{
    int n;
    int m;
public:
    int getA()
    {
        return n;
    }
    int getB()
    {
        return m;
    }
   samp(int n)
    {
        this-> n= n;
    }
    samp(int n, int m)
    {
        this-> n= n;
        this-> m= m;
    }
};

int main()
{
    samp s1[4]={1,2,3,4};
       samp s2[4][4]={
        {samp(2,4), samp(3,6), samp(4,8), samp(5,10)},
        {samp(6,12), samp(7,14), samp(8,16), samp(9,18)},
        {samp(10,20), samp(11,22), samp(12,24), samp(13,26)},
        {samp(14,28), samp(15,30), samp(16,32), samp(17,34)}
    };


     for(int i=0; i<4; i++)
     {
         cout<<s1[i].getA()<<endl;
     }

     cout<<"the 2D array:"<<endl;

     for(int i=0; i<4; i++)
     {
         for(int j=0; j<4; j++)
         {
             cout<<s2[i][j].getA()<<","<<s2[i][j].getB()<<endl;
         }
         cout<<"\n";

     }


     return 0;
}

