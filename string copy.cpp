#include<iostream>
#include<cstring>
using namespace std;

class samp
{
    char s[80];
public:
    void show()
    {
        cout<<s<<endl;
    }

    void set(char *str)
    {
        strcpy(s, str);
    }

};

samp input()
{
    char p[80];
    samp ob;
    cout<<"enter a string: ";
    cin>>p;
    ob.set(p);
    return ob;
}

int main()
{
    samp ob1;
    ob1= input();
    ob1.show();
    return 0;
}
