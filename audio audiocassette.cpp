#include<iostream>
#include<cstring>
using namespace std;

class publication
{
public:
    string title;
    int price;
    virtual void getData()
    {

    }

    virtual void putData()
    {

    }

};

class book: public publication
{

public:
    int pageCount;
    void getData()
    {
        cout<<"enter the tile of the book: ";
        getline(cin, title);
        cout<<"enter the price of the book: ";
        cin>>price;
        cout<<"enter the total page number of the book: ";
        cin>>pageCount;
    }

    void putData()
    {
        cout<<"title: "<<title<<" price: "<<price<<" total page: "<<pageCount<<endl;
    }
};

class tape: public publication
{

public:
    float time;
    void getData()
    {
        cout<<"enter the tile of the tape: ";
        cin.ignore();
        getline(cin, title);
        cout<<"enter the price of the tape: ";
        cin>>price;
        cout<<"enter the total run time of the tape: ";
        cin>>time;
    }

    void putData()
    {
        cout<<"title: "<<title<<" price: "<<price<<" run time: "<<time<<endl;
    }

};

int main()

{
    book b1;
    tape t1;
    b1.getData();
    t1.getData();
    b1.putData();
    t1.putData();
    return 0;
}
