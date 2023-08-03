#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class samp
{
    char *s;
public:
    samp(){s=NULL;}
    ~samp()
    {
        cout<<"freeing s."<<endl;
        free(s);
    }
    void show()
    {
        cout<<s;
    }
    void set(char *str);
};
void samp::set(char *str)
{
    if(!str)
    {
        cout<<"the string is empty."<<endl;
        exit(1);
    }
    s= (char*) malloc(strlen(str)+1);
    if(!s)
    {
        cout<<"Error memory allocation"<<endl;
        exit(1);
    }
    strcpy(s,str);
}

samp input()
{
    char s[80];
    samp str;
    cout<<"Enter a string: "<<endl;
    cin>>s;
    str.set(s);
    return str;

}
