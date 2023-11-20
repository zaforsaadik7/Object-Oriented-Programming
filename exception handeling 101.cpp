#include<iostream>
using namespace std;

int main()
{
    int age;
    bool loop=1;
    while(loop!=0)
    {
        cout<<"Enter your age: ";
        cin>>age;
        try
        {
            if(age> 18)
                cout<<"Access Granted: You are old enough."<<endl;
            else
                throw(age);
        }

        catch(int age)
        {
            cout<<"Access Denied: You are not old enough."<<endl;
        }

        cout<<"Enter 1 to continue and 0 to terminate the program: ";
        cin>>loop;
    }

}

