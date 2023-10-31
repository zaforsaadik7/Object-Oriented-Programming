#include<iostream>
#include<cstring>
using namespace std;
class Passwordcrack
{
public:
    string password;
    Passwordcrack(string password)
    {
        this-> password= password;
    }
    int operator ==(Passwordcrack ob)
    {
        if(password== ob.password)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Passwordcrack ob("hello saadik");
    Passwordcrack ob1("hello saadik");
    Passwordcrack ob2("hello sadik");
    if(ob==ob1)
    {
        cout<<"Password cracked"<<endl;
    }
    else
    {
        cout<<"Wrong password!"<<endl;
    }
    if(ob==ob2)
    {
        cout<<"Password cracked"<<endl;
    }
    else
    {
        cout<<"Wrong password!"<<endl;
    }
}
