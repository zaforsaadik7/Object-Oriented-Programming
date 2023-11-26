#include<iostream>
#include<cstring>
using namespace std;

class Student
{
    string name;
    int rollNumber;
    int mark;
public:
    void setdetails(string name, int rollNumber, int mark)
    {
        this-> name= name;
        this-> rollNumber= rollNumber;
        this-> mark= mark;
    }

    void display()
    {
        cout<<"Name: "<<name<<" ,roll number: "<<rollNumber<<" ,mark: "<<mark<<endl;
    }

};

int main()
{
    Student *s;
    s= new Student[10];
    for(int i=0; i<10; i++)
    {
        string name;
        int rollNumber;
        int mark;

        cin>>name>>rollNumber>>mark;
        s[i].setdetails(name, rollNumber, mark);
        s[i].display();
        delete[]s;

    }
}
