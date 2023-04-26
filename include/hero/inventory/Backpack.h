#pragma once

#include <stack>
#include "hero/object/IObject.h"

namespace He_ARC::rpg {
    /**
    * Backpack class for storing inventory in a similar way to stacks
    * @author Elisa Goloviatinski
    * @version 5.0
    */
   class Backpack {
        private:
            stack<IObject*> mStack;
        public:
            Backpack() = default;
            void pack(IObject*);
            IObject* unPack();
            bool isNotEmpty() const;
            virtual ~Backpack() = default;
   };
}