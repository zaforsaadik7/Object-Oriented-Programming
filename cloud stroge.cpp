#include<iostream>
using namespace std;
class Drive38
{
    double totalSpace;
    double free;
    double used;
public:
    Drive38()
    {
        totalSpace=10;
        free=10;
        used=0;
    }
    void upload(double x)
    {
        if(x<=totalSpace)
        {
        free-=x;
        used=x;
        }
        else
            cout<<"Not enough space."<<endl;
    }

    void upgrade(double y)
    {
        totalSpace+=y;
        free+=y;
    }

    void viewStatus()
    {
        cout << "Total Space: " << totalSpace << " GB"<<endl;
        cout << "Used: " << used << " GB"<<endl;
        cout << "Free: " << free << " GB"<<endl;
    }

};

int main()
{
    Drive38 user1;
    user1.upload(2.5);
    user1.viewStatus();
    user1.upgrade(12);
    user1.viewStatus();
}

