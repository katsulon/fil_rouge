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
            /// @brief Gets top item in backpack
            /// @return Returns top item in backpack stack
            IObject* getStackTop() const { 
                try {
                    if (isNotEmpty() == false) {
                        throw "Backpack empty, no item to return";
                    }
                    return mStack.top(); 
                }
                catch(const char* emptyBackpack) {
                    cout << emptyBackpack << endl;
                    return nullptr;
                } 
            }
            void pack(IObject*);
            IObject* unPack();
            bool isNotEmpty() const;
            /// @brief Virtual deconstructor
            virtual ~Backpack() = default;
   };
}