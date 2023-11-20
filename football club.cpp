#include<iostream>
using namespace std;

class ManchesterUnited
{
    int couch;
    int player;
public:
    ManchesterUnited( int couch=0, int player=0)
    {
        this-> couch= couch;
        this-> player= player;
    }
   void getData ()
    {
        cout<<"enter the total number of couch: "<<endl;
        cin>>couch;
        cout<<"enter the total number of player: "<<endl;
        cin>>player;
    }

    int setCouch()
    {
        return couch;
    }

    int setPlayer()
    {
        return player;
    }

    void operator ++(int)
    {
        couch++;
        player++;
    }

    bool operator ==(ManchesterUnited ob)
    {
        if(couch==ob.couch && player== ob.player)
            return 1;
        else
            return 0;
    }
};

int main()
{
    ManchesterUnited ronaldo(4,5);
    ronaldo++;
    cout<<ronaldo.setCouch()<<" "<<ronaldo.setPlayer()<<endl;
    ManchesterUnited fernandes(5,6);
     cout<<fernandes.setCouch()<<" "<<fernandes.setPlayer()<<endl;
    if(ronaldo== fernandes)
        cout<<"both have same number of couch and player."<<endl;
    else
        cout<<"they don't have same number of couch and player."<<endl;
    return 0;

}
