using namespace std;

namespace He_ARC::rpg
{
    class Sword
    {
    private:
        int damage;
    public:
        Sword();
        Sword(int);
        int getDamage() const;
    };
}