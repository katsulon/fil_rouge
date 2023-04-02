#include "Hero.h"
#include "class/ClassImpl.h"

using namespace He_ARC::rpg;

int main() {
    Warrior w1;
    w1.show();
    Wizard wiz1(1,5,10,100,1,new Weapon(100,"Great staff"));
    wiz1.show();
    Rogue r1;
    r1.show();
    
    wiz1.interact(w1);

    cout << wiz1;

    w1.interact(wiz1);

    r1.interact(wiz1);

    Necromancer test;

    cout << test;

    test.interact(wiz1);

    test.raiseUndeads();
    
    return 0;
}