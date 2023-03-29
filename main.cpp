#include "src/hero/Hero.cpp"
#include "src/hero/class/Wizard.cpp"
#include "src/hero/class/wizard/Necromancer.cpp"

using namespace He_ARC::rpg;

int main()
{
    Hero h1;
    h1.show();
    Hero h2(3,7,10,100,"Gimli",new Weapon(100));
    h2.show();
    
    h2.interact(h1);

    cout << h2;

    Necromancer test(3,7,10,100,"Seiga",new Weapon(100),1);

    cout << test;

    test.interact(h2);

    test.raiseUndeads();
    
    return 0;
}