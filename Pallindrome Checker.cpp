#include<iostream>
using namespace std;

class pallindrome
{
    int input;
public:

    void getInput(int input)
    {
        this-> input= input;
    }
    int isPallindrome()
    {
        int remainder, original, reversed;
        reversed=0;
        original=input;
        while(original!=0)
        {
        remainder=original%10;
        reversed=reversed*10+remainder;
        original/=10;
        }
        if(reversed== input)
        {
            return 1;
        }

        else
        {
            return 0;
        }

    }

};

int main()
{
    pallindrome p;
    p.getInput(123);
    if(p.isPallindrome())
    {
        cout<<"Pallindrome."<<endl;
    }
    else{cout<<"Not Pallindrome."<<endl;}

    return 0;
}
