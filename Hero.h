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
        Hero();
        void interact(const Hero&);
        void show();
};