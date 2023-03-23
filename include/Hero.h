#include <string>
#include "../src/Sword.cpp"

using namespace std;

namespace He_ARC::rpg
{
    class Hero 
    {
    private:
        int strength;
        int agility;
        int intelligence;
        double hp;
        string name;
        Sword sword;
    public:
        Hero();
        Hero(int,int,int,double,string);
        //Hero(const Hero&); //not necessary
        void interact(const Hero&);
        void show() const;
    };
}