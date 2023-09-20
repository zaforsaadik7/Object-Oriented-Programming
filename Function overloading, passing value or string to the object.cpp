#include<iostream>
#include<cstdio>
using namespace std;

class date
{
    int day, month, year;

public:
    date(char *str)
    {
        sscanf(str,"%d%*c%d%*c%d%*c",&day,&month,&year);

    }
    date(int day, int month, int year)
    {
        this-> day=day;
        this-> month= month;
        this-> year= year;
    }
    void show()
    {
        cout<<"The date is:"<<day<<"/"<<month<<"/"<<year<<endl;

    }
};

int main()
{
    date d1("12/12/2002");
    date d2(12,12,2002);
    d1.show();
    d2.show();
    return 0;
}
