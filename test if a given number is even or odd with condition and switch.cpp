#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number to test:";
    cin>>n;
    if (n%2 == 0)
        cout<<"Even number."<<endl;
    else
        cout<<"Odd number."<<endl;

    int m;
    cout<<"Enter another number:";
    cin>>m;
    switch(cin.fail() ? -1 : m % 2)
    //This line uses the ternary operator (?:) to set the value of the switch expression based on whether the input was successful or not.
    {
    case 0:
        cout<<"Even number.";
        break;
    case 1:
        cout<<"Odd number.";
        break;
    default:
        cout<<"Not a valid number.";
        break;

    }

    return 0;
}
