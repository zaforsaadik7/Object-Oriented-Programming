#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class samp
{
    char *p;
public:
    samp(char *s)
    {
        int l;
        l=strlen(s)+1;
        p=new char [l];
        if(!p)
        {
            cout<<"Allocation Error."<<endl;
            exit(1);
        }
        strcpy(p,s);
    }
    samp(const samp &o)
    {
        int l;
        l=strlen(o.p)+1;
        p=new char [l];
        if(!p)
        {
            cout<<"Allocation Error."<<endl;
            exit(1);
        }
        strcpy(p,o.p);
    }
    char *get()
    {
        return p;
    }
};

void show(samp c)
{
    char *p;
    p=c.get();
    cout<<p<<endl;
}

int main()
{
    samp a("hello"), b("there");
    show(a);
    show(b);
    return 0;

}
