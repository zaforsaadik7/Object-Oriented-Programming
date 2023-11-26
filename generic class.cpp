#include<iostream>
using namespace std;


template <typename T>


class Number
{
    T x;
public:
    Number(T x=0)
    {
        this-> x= x;
    }

    T getValue()
    {
        return x;
    }
};

int main()
{
    Number<int> A(123);
    Number<float> B(12.34);

    cout<<A.getValue()<<endl;
    cout<<B.getValue()<<endl;
    return 0;
}
