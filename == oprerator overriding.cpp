#include<iostream>
using namespace std;

class A
{
public:
    int a;
    A(int a)
    {
        this-> a=a;
    }
    A()
    {

    }

};

class B: virtual public A
{
public:
    int b;
    B(int a, int b): A(a)
    {
        this-> b= b;
    }
    bool operator ==(A ob)
    {
        return b== ob.a;
    }
};

class C: virtual public A
{
public:
    int c;
    C(int a, int c): A(a)
    {
        this-> c= c;
    }
    bool operator ==(A ob)
    {
        return c== ob.a;
    }
};

class D: virtual public A
{
public:
    int d;
    D(int a, int d): A(a)
    {
        this-> d= d;
    }
    bool operator ==(A ob)
    {
        return d== ob.a;
    }
    D()
    {

    }
};

class E: public B, public C, virtual public D
{
public:
    int e;
    E(int a, int b, int c, int d, int e): B(a, b), C(a, c), D(a, d)
    {
        this-> e=e;
    }
    bool operator ==(A ob)
    {
        return e== ob.a;
    }

    bool operator ==(B ob)
    {
        return e== ob.b;
    }

    bool operator ==(C ob)
    {
        return e== ob.c;
    }

    bool operator ==(D ob)
    {
        return e== ob.d;
    }
};

class F: virtual public D
{
public:
    int f;
    F(int a, int d, int f): D(a, d)
    {
        this-> f=f;
    }

    bool operator ==(A ob)
    {
        return f== ob.a;
    }

    bool operator ==(B ob)
    {
        return f== ob.b;
    }

    bool operator ==(C ob)
    {
        return f== ob.c;
    }

    bool operator ==(D ob)
    {
        return f== ob.d;
    }

    bool operator ==(E ob)
    {
        return f== ob.e;
    }
};

class G: public E, public F
{
public:
    int g;
    G(int a, int b, int c, int d, int e, int f, int g): E(a,b,c,d,e), F(a,d,f)
    {
        this-> g= g;

    }

    bool operator ==(A ob)
    {
        return g== ob.a;
    }

    bool operator ==(B ob)
    {
        return g== ob.b;
    }

    bool operator ==(C ob)
    {
        return g== ob.c;
    }

    bool operator ==(D ob)
    {
        return g== ob.d;
    }

    bool operator ==(E ob)
    {
        return g== ob.e;
    }

    bool operator ==(F ob)
    {
        return g== ob.f;
    }
};

int main()
{
    A ob1(2); B ob2(2,3); C ob3(3,4); D ob4(1,2); E ob5(1,2,3,4,5); F ob6(4,5,3); G ob7(1, 2, 3, 4, 5, 6, 7);
    if(ob2==ob1)
        cout<<"Equal."<<endl;
    else
        cout<<"Not equal."<<endl;
    if(ob3==ob1)
        cout<<"Equal."<<endl;
    else
        cout<<"Not equal."<<endl;

    if(ob4==ob1)
        cout<<"Equal."<<endl;
    else
        cout<<"Not equal."<<endl;

    if(ob5==ob1)
        cout<<"Equal."<<endl;
    else
        cout<<"Not equal."<<endl;
    return 0;
}
