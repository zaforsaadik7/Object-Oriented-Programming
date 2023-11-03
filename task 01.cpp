#include<iostream>
#include<cstring>
using namespace std;

class Player
{
public:
    string name;
    int age;
    string country;
    Player(string name, int age, string country)
    {
        this-> name= name;
        this-> age= age;
        this-> country= country;
    }
    virtual void show()
    {

    }
};

class Batsman: public Player
{
    public:
    float battingAverage;
    long long totalRuns;
    int highestScore;
    Batsman(float a, long long b, int c, string n, int m, string o): Player(n, m, o)
    {
        battingAverage= a;
        totalRuns=b;
        highestScore= c;
    }
    void show()
    {
        cout<<"name: "<<name<<"\nage: "<<age<<"\ncountry: "<<country<<"\nbatting average: "<<battingAverage<<"\ntotalRuns: "<<totalRuns<<"\nhighestScore: "<<highestScore<<endl;
    }
};

class bowler: public Player
{
    public:
    float bowlingAverage;
    int wicketsTaken;
    string bowlingStyle;
    bowler(float a, int b, string c, string n, int m, string o): Player(n, m, o)
    {
        bowlingAverage=a;
        wicketsTaken=b;
        bowlingStyle=c;
    }
    void show()
    {
         cout<<"name: "<<name<<"\nage: "<<age<<"\ncountry: "<<country<<"\nbowlingAverage: "<<bowlingAverage<<"\nwicketsTaken: "<<wicketsTaken<<"\nbowlingStyle: "<< bowlingStyle<<endl;
    }
};

class specialistBatsman: public Batsman
{
    public:
    float strikeRate;
    int numberOfCenturies;
    specialistBatsman(float a, int b, float p, int q, int r, string s, int t, string u):Batsman(p, q, r, s, t, u)
    {
        strikeRate=a;
        numberOfCenturies=b;

    }
    void show()
    {
        cout<<"name: "<<name<<"\nage: "<<age<<"\ncountry: "<<country<<"\nbatting average: "<<battingAverage<<"\ntotalRuns: "<<totalRuns<<"\nhighestScore: "<<highestScore<<"\nstrikeRate:"<<strikeRate<<"\nnumberOfCenturies: "<<numberOfCenturies<<endl;
    }

};

int main()
{
    bowler b1(6.3, 20,"fast bowler", "habib", 23, "afganistan");
    specialistBatsman b2(110.34, 6, 6.8, 13000, 200, "maxwell", 45, "australia");
    cout<<"bowler's details:"<<endl;
    b1.show();
    cout<<"batsman's details:"<<endl;
    b2.show();

    return 0;
}
