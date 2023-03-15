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
        Hero(int,int,int,double,string);
        void interact(const Hero&);
        void show();
};