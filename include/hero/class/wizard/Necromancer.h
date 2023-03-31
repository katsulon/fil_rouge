#include "class/Wizard.h"

namespace He_ARC::rpg
{
    class Necromancer : public Wizard
    {
        public:
            using Wizard::Wizard;
            void raiseUndeads();
    };
}