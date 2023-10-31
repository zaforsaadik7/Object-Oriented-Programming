#include<iostream>
using namespace std;

class box
{
    public:
    int height;//8
    int length;//10
    int width;//12
    box(int height, int length, int width)
    {
        this-> height= height;
        this-> length= length;
        this-> width= width;
    }
  void  checkBox()
    {
        int x;
        if(height<8)
        {
            x=8-height;
            height+=x;
        }
        else if(height>8)
        {
            x=height-8;
            height-=x;
        }
        x=0;
        if(length<10)
        {
            x=10- length;
            length+=x;
        }
        else if(length>10)
        {
            x=length-10;
            length-=x;
        }
        x=0;
        if(width<12)
        {
            x=12-width;
            width+=x;
        }
        else if(width>12)
        {
            x= width-12;
            width-=x;
        }
    }
    void display()
    {
        cout<<" height:"<<height<<" length:"<<length<<" width: "<<width<<endl;
    }
};

int main()
{
    box b1(8,10,12);
    box b2(10,12,14);
    box b3(6,8,10);
    b1.display();
    b2.display();
    b3.display();

    cout<<"After checking the boxes:"<<endl;
    b1.checkBox();
    b2.checkBox();
    b3.checkBox();
    b1.display();
    b2.display();
    b3.display();
    return 0;
}
