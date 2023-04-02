#include <list>
#include "Hero.h"
#include "class/ClassImpl.h"

using namespace He_ARC::rpg;

int main() {
    Warrior *war1 = new Warrior;
    Rogue *rog1 = new Rogue;
    Wizard *wzd1 = new Wizard;
    Necromancer *ncm1 = new Necromancer;
    list<Hero*> party;
    party.push_back(war1);
    party.push_back(rog1);
    party.push_back(wzd1);
    party.push_back(ncm1);
    
    for(Hero *member : party) {
        cout << *member;
    }

    war1->interact(*wzd1);
    wzd1->interact(*ncm1);
    rog1->interact(*wzd1);

    wzd1->castSpell();
    ncm1->castSpell();
    ncm1->raiseUndeads();

    for(Hero *member : party) {
        delete member;
    }
    return 0;
}