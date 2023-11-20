#include<iostream>
using namespace std;

template <class type1,class type2> void display(type1 x, type2 y)
{
    cout<<"my name is "<<x<<". I am "<<y<<" years old."<<endl;
}

int main()
{
    string x= "saadik";
    int y= 23;
    display(x, y);
    return 0;
}
