#include<iostream>
using namespace std;

class cloths
{
    float sweatshirtPrize;
    float jeansPrize;
    float othersPrize;
public:
    void setSweatshirtPrize(float x)
    {
        if(x<500)
        {
            cout<<"Error: Not enough money.";
            return;
        }
        else
            sweatshirtPrize= x- (x*0.2);
    }

    void setJeansPrize(float y)
    {
        if(y<500)
        {
            cout<<"Error: Not enough money.";
            return;
        }
        else
            jeansPrize= y- (y*0.06);
    }

    void setOthersPrize(float z)
    {
        othersPrize= z;
    }

    float returnMoney(int a)
    {
        float extra=a;
        float totalBuy= sweatshirtPrize+jeansPrize+othersPrize;
        if(totalBuy> 1000)
        {
            cout<<"Error: exceeded purchasing limit."<<endl;
            return -1.0;
        }
        extra= a- totalBuy;
        return extra;
    }

    float totalBuy()
    {
        float totalBuy= sweatshirtPrize+jeansPrize+othersPrize;
        return totalBuy;
    }
};

int main()
{
    cloths s1;
    s1.setSweatshirtPrize(510);
    s1.setJeansPrize(500);
    s1.setOthersPrize(80);
    cout<<s1.returnMoney(5000)<<endl;
    cout<<s1.totalBuy()<<endl;
    return 0;
}
