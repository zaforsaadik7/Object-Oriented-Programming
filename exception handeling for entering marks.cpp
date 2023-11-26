#include<iostream>
using namespace std;

void inputMark(int n)
{
    if(n> 40)
        throw "invalid input.";
    else
        cout<<"valid input."<<endl;

}

int main()
{
    int n;
    while(true)
    {
        try
        {
            cout<<"enter new mark as input: ";
            cin>>n;
            inputMark(n);
            break;

        }

        catch(const char *msg)
        {
            cout<<msg<<endl;
        }

    }
}
