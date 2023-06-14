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
            /// @brief Default constructor
            Backpack() = default;
            string getStackTop() { return mStack.top()->getName(); }
            void pack(IObject*);
            IObject* unPack();
            bool isNotEmpty() const;
            /// @brief Virtual deconstructor
            virtual ~Backpack() = default;
   };
}