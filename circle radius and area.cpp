#include<iostream>
using namespace std;

class circle
{
    float r;
    public:
        circle()
        {
            r= 1;
        }
        circle(float r)
        {
            this ->r= r;
        }
        float getr(){return r;}
        void setr(int x) {r=x;}
};

float getArea(circle obj)
{
    float area= 3.1416*obj.getr()*obj.getr();
    return area;
}

int main()
{
    circle ob1(2), ob2(12), ob3(24);
    cout<<"first circle: \nradius:" <<ob1.getr()<<endl;
    cout<<"Area: "<< getArea(ob1)<<endl;


    cout<<"second circle: \nradius:" <<ob2.getr()<<endl;
    cout<<"Area: "<< getArea(ob2)<<endl;


    cout<<"third circle: \nradius:" <<ob3.getr()<<endl;
    cout<<"Area: "<< getArea(ob3)<<endl;

    ob2.setr(35)
    cout<<"second circle: \nnew radius:" <<ob2.getr()<<endl;
    cout<<"New area: "<< getArea(ob2)<<endl;
