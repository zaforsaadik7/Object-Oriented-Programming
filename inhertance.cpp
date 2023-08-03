#include<iostream>
using namespace std;
class A
{
    int a;
public:
    void setA(int i){a= i;}
    int getA(){return a;}
};
class B: public A
{
    int b;
public:
    void setB(int j){b= j;}
    int mul(){return b* getA();}

};
int main()
{
    B ob1;
    ob1.setA(5);
    ob1.setB(6);
    cout<<ob1.mul()<<endl;
    return 0;

}
