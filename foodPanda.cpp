#include<iostream>
#include<cstring>
using namespace std;
class foodPanda
{
    int x;
    stirng* food;
public:
    void Orderfood(int x)
    {
        this-> x= x;
        food= new string[x];
        if(x>=2 && x<=4)
        {
            cout<<"Enter "<<x<<" food names to order: "<<endl;
            for(int i=0; i<x; i++)
            {
                cin>>food[i];

            }
        }
    }
};

int main()
{
    foodPanda f1;
    f1.Orderfood(3);
}
