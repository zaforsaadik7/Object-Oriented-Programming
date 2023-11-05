#include<iostream>
using namespace std;

class num
{
public:
    int n;
    num(int n)
    {
        this-> n= n;
    }

    virtual void shownum()
    {
        cout<<n<<endl;
    }
};

class outhex: public num
{
public:
    outhex(int n):num(n)
    {

    }
    void shownum()
    {
        cout<<hex<<n<<endl;
    }

};

class outoct: public num
{
public:
    outoct(int n): num(n)
    {

    }
    void shownum()
    {
        cout<<oct<<n<<endl;
    }
};

int main()
{
    num b(20);
    b.shownum();
    outhex c(20);
    c.shownum();
    outoct d(20);
    d.shownum();

}
