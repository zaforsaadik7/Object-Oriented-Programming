#include<iostream>
using namespace std;
int main()
{
union
{
    int i;
    char ch[4];
};
i=10;
ch[0]='h';
}
