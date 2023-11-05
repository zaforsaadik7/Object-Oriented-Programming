#include<iostream>
using namespace std;

class Distance
{
    float feet;
    float inches;
public:
    Distance() {}
    Distance(float feet, float inches)
    {
        this-> feet= feet;
        this-> inches= inches;

        if(inches>12)
        {

            feet= feet+ (inches/12);
            inches-= int(inches/12)*12;
        }
    }

    void getDist()
    {
        cout<<"Enter feet and inches: ";
        cin>>feet>>inches;
    }

    Distance& operator +=(Distance ob)
    {
        feet+=ob.feet;
        inches+=ob.inches;

        if(inches>12)
        {

            feet= feet+ (inches/12);
            inches-= int(inches/12)*12;
        }
        return *this;

    }

    void showDist()
    {
        cout<<feet<<" feet "<<inches<<" inches."<<endl;
    }

};



int main()
{
    Distance d1, d2, d3(5,90), d4(2, 11);
    d1.getDist();
    d2.getDist();
    d1=d1+=d2;
    d1.showDist();
    d3= d3+=d4;
    d3.showDist();
    return 0;
}
