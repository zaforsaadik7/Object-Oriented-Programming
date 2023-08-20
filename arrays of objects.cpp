#include<iostream>
using namespace std;
class samp
{
    int n;
public:
    int getA()
    {
        return n;
    }
    void setA(int n)
    {
        this-> n= n;
    }
};

int main()
{
    samp s[4];
    for(int i=0; i<4; i++)
    {
        s[i].setA(i);
    }

     for(int i=0; i<4; i++)
     {
         cout<<s[i].getA()<<endl;
     }

     return 0;
}
