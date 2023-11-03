#include<iostream>
#include<cstring>
using namespace std;

class House
{
public:
    string houseName;
    string sigil;
    string motto;
    House(string houseName,string sigil,string motto)
    {
        this-> houseName= houseName;
        this-> sigil= sigil;
        this-> motto= motto;
    }

};

class Personality
{
public:
    string characterName;
    string alignment;
    string traits;
    Personality(string characterName,string alignment,string traits)
    {
        this-> characterName= characterName;
        this-> alignment= alignment;
        this-> traits= traits;
    }
};

class Skills
{
public:
    string combatSkills;
    string leadership;
    string specialAbilities;
    Skills(string combatSkills,string leadership,string specialAbilities)
    {
        this-> combatSkills= combatSkills;
        this-> leadership= leadership;
        this-> specialAbilities= specialAbilities;
    }
};

class GameOfThronesCharacter: public House, public Personality, public Skills
{
public:
    GameOfThronesCharacter(string housename, string sigil, string motto, string name, string alignment, string traits, string combatskills, string leadership, string specialAbilities):House(housename, sigil, motto), Personality(name, alignment,traits), Skills(combatskills, leadership, specialAbilities)
    {

    }
    void show()
    {
        cout<<"character name: "<<characterName<<"\n\nHouse name: "<<houseName<<"\n\nSilig: "<<sigil<<"\n\nMoto: "<<motto<<"\n\nAlignment: "<< alignment<<"\n\nTraits: "<<traits<<"\n\nCombat skills: "<<combatSkills<<"\n\nLeadership: "<<leadership<<"\n\nSpecial Abilities: "<<specialAbilities<<endl;
    }
};

int main()
{
    GameOfThronesCharacter c1("Targaryen", "A red three-headed dragon on a black field", "Fire and Blood", "Daenerys Targaryen", "Initially a timid, obedient youth", "She is known for her determination, resilience, and belief in herself. She is also known for her compassion towards those who are oppressed", "While not a traditional warrior, Daenerys has dragons and is unafraid to use them in battle","While not a traditional warrior, Daenerys has dragons and is unafraid to use them in battle", "She is known as the Mother of Dragons and has a unique bond with her dragons. She is also immune to fire");
    c1.show();
    return 0;
}
