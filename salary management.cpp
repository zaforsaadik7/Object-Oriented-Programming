#include<iostream>
using namespace std;

class Employee
{
    public:
        Employee(int salary)
        {
            this-> salary= salary;
        }
    int salary;
    virtual int calculateSalary()
    {

    }
};

class Manager: public Employee
{
    public:
    Manager(int salary):Employee(salary)
    {

    }
    int calculateSalary()
    {
        return salary* 0.2;
    }
};

class Salesperson: public Employee
{
    public:
    Salesperson(int salary):Employee(salary)
    {

    }
    int calculateSalary()
    {
        return salary* 0.4;
    }
};

class Engineer: public Employee
{
    public:
    Engineer(int salary):Employee(salary)
    {

    }
    int calculateSalary()
    {
        return salary* 0.05;
    }
};

int main()
{
    Manager p1(10000);
    Salesperson p2(10000);
    Engineer p3(10000);
    cout<<p1.calculateSalary()<<endl;
    cout<<p2.calculateSalary()<<endl;
    cout<<p3.calculateSalary()<<endl;
    return 0;
}
