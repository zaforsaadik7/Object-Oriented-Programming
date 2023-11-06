#include<iostream>
using namespace std;

class num
{
public:
    void print(int n, int i = 1)
    {
        if(i <= n)
        {
            cout << i << endl;
            print(n, i + 1);
        }
    }
};

int main()
{
    num ob;
    ob.print(5);
    return 0;
}
