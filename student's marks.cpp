#include<iostream>
using namespace std;

class student
{
    int mark[10];
public:
    student(int mark[10])
    {
        for(int i=0; i<10; i++)
        this-> mark[i]= mark[i];
    }

    void calculate_marks(int &H, int &L, float &A)
    {
        int highest= mark[0];
        int lowest= mark[0];
        int totalMarks=0;


        for(int i=1; i<10;i++)
        {
            if(mark[i]> highest)
            {
                highest= mark[i];
            }

            if(mark[i]<lowest)
            {
                lowest= mark[i];
            }
            totalMarks+=mark[i];

        }
        float averageMark= totalMarks/10;

        H=highest;
        L=lowest;
        A=averageMark;
    }
};

 void dispaly_marks(int H, int L, float A)
    {
        cout<<"Highest marks: "<<H<<"\n"<<"Lowest marks: "<<L<<"\n"<<"Average marks: "<<A<<endl;
    }

int main()
{
    int marks[10]={85, 90, 88, 92, 76, 81, 95, 89, 78, 88};
    student s(marks);
    int highest=0;
    int lowest=0;
    float average=0;
    s.calculate_marks(highest, lowest, average);

    dispaly_marks(highest, lowest, average);

    return 0;
}
