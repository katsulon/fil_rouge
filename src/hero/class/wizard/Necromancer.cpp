#include "../../../../include/hero/class/wizard/Necromancer.h"

namespace He_ARC::rpg
{
    void Necromancer::raiseUndeads()
    {
        if (mana > 1)
        {
            cout << "Joyful Graveyard" << endl;
            mana-=2;
        }
    }
}