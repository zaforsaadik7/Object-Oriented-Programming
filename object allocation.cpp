#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class samp
{
    char *p;
    int len;
public:
    samp(char *ptr);
    ~samp();
    void show();
};
samp::samp(char *ptr)
{
    if(!ptr)
    {
        cout<<"the pointer is Null."<<endl;
        exit(1);
    }
    len= strlen(ptr);
     p= (char*) malloc(len+1);
    if(!p)
    {
       cout<<"Allocation error."<<endl;
        exit(1);
    }
    strcpy(p,ptr);
}
samp::~samp()
{
   cout<<"freeing the pointer."<<endl;
    free(p);
}
void samp::show()
{
    cout<<p<<"- length: "<<len<<endl;
}

int main()
{
    samp ob1("Hello, My name is Saadik.");
    ob1.show();
    return 0;

}
