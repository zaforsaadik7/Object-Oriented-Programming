#include <iostream>

using namespace std;

class Maximum
{
    int a, b;

public:
    Maximum(int x, int y)
    {
        a = x;
        b = y;
    }
    int maxfinder(int x, int y) { return (x > y) ? x : y; }
};
int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    Maximum ob1(num1, num2);
    int max = ob1.maxfinder(num1, num2);
    cout << "the maximum value: " << max << endl;
    return 0;
}
