#include "../include/Sword.h"

namespace He_ARC::rpg
{
    Sword::Sword()
    {
        damage=1;
    }
    Sword::Sword(int _damage): damage(_damage) {}

    int Sword::getDamage() const
    {
        return damage;
    }
}