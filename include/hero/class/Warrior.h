#include "../Hero.h"

namespace He_ARC::rpg
{
    class Warrior : public Hero
    {
        public:
            Warrior(int,int,int,double,string);
            void interact(const Hero&) override;
    };
}