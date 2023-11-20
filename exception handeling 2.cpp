#include<iostream>
using namespace std;

float devide(int x, int y)
{
    if(y== 0)
    {
        throw"Error: division by zero condition.";
    }

    return static_cast<float>(x)/y;
}

int main()
{
    int x, y;
    cout<<"enter the values of x and y: ";
    cin>>x>>y;

    float z;
    while (true) {
        try
        {
            z=devide(x, y);
            cout<<"z: "<<z<<endl;
            break;  // If the division was successful, break the loop.
        }

        catch( char* msg)
        {
            cout<<msg<<endl;
            cout<<"enter a new value for y: ";
            cin>>y;
        }
    }

    return 0;
}
