#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter your name:";
    string name;
    getline(cin,name);
    cout<<'\n';
    cout<<"Enter your age:";
    cin>>age;
    cout<<"\nYour name is "<<name<<".You are "<<age<<" years old.";
}
