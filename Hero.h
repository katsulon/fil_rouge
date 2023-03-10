#include <string>

using namespace std;

class Hero {
    private:
        int strength;
        int agility;
        int intelligence;
        double hp;
        string name;
    public:
        Hero() { strength = 3; agility=7; intelligence=10; hp=100; name="Gimli"; };
        void interact(const Hero&);
        void show();
};