//Scenario: Using inheritance, create a University Management System.
//Define three base classes: Person, Student, and Professor.
//Person Class: This class should have attributes like name, age, and id. Implement a constructor for the Person class that initializes these attributes.
//Student Class: This class should inherit from the Person class and have an additional attribute major. Implement a constructor for the Student class that initializes these attributes.
//Professor Class: This class should also inherit from the Person class and have an additional attribute department. Implement a constructor for the Professor class that initializes these attributes.

#include<iostream>
#include<cstring>
using namespace std;

class Person
{
public:
    string name;
    int age;
    long long id;
    Person(string name, int age, long long id)
    {
        this-> name= name;
        this-> age= age;
        this-> id= id;
    }
    virtual void show()
    {

    }
};

class Student: public Person
{
public:
    float cgpa, totalCredit;
    int totalSubject;

    Student(string a, int b, long long c, float d, float e, int f): Person(a, b, c)
    {
        cgpa= d;
        totalCredit= e;
        totalSubject= f;
    }
    void show()
    {
        cout<<"Student name: "<<name<<"\nAge: "<<age<<"\nI'D: "<<id<<"\nCGPA: "<<cgpa<<"\nTotal Credit: "<<totalCredit<<"\nTotal Subjects: "<<totalSubject<<endl;
    }
};

class Professor: public Person
{
    public:
    string department;
    int salary;
    Professor(string a, int b, long long c, string d, int e): Person(a, b,c)
    {
        department= d;
        salary= e;
    }

    void show()
    {
        cout<<"Student name: "<<name<<"\nAge: "<<age<<"\nI'D: "<<id<<"\nDepertment: "<<department<<"\nSalary: "<<salary<<endl;
    }

};

int main()
{
    Student s1("Zafor Saadik", 23, 22235103581, 4.00, 163.5, 8);
    Professor p1("Anisul Haque", 56, 1234567890, "CSE", 1200000);
    s1.show();
    p1.show();
    return 0;
}
