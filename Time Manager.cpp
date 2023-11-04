#include<iostream>
using namespace std;

class time
{
    int hour, minute, second;
public:
    time(int hour, int minute, int second)
    {
        this-> hour= hour;
        this-> minute= minute;
        this-> second= second;
    }
    time()
    {
        this-> hour=0;
        this-> second=0;
        this-> minute=0;
    }

    time* add_time(time t1, time t2)
    {
        time* temp=new time();
        temp->hour= t1.hour+t2.hour;
        temp->minute= t1.minute+ t2.minute;
        if(temp->minute>60)
        {
            while(temp->minute>=60)
            {
                temp->minute-=60;
                temp->hour++;

            }
        }

        temp->second= t1.second+ t2.second;
        if(temp->second>60)
        {
            while(temp->second>=60)
            {
                temp->second-=60;
                temp->minute++;

            }
        }
        return temp;
    }
    void display()
    {
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
};
int main()
{
    time t1(2,55, 40), t2( 5, 20, 30);
    time* t3;
    t3= t3->add_time(t1, t2);
    t3->display();
    delete t3;
    return 0;

}
