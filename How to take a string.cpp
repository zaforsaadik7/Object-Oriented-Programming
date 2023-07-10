#include <iostream>
using namespace std;
int main ()
{
cout<<"Enter your name:";
char name[80];
cin.getline(name,80);

cout<<"Enter your university name:";
string university;
getline(cin,university);


cout<<"Hello, "<<name<<"."<<endl;
cout<<"Welcome to "<<university<<".";
return 0;
}
