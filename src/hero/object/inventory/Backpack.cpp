#include "hero/inventory/Backpack.h"

namespace He_ARC::rpg {
    /// @brief Adds an IObject item to the stack
    /// @param pObject Item to add on top of stack
    void Backpack::pack(IObject* pObject) {
        mStack.push(pObject);
    }

    /// @brief Removes an IObject item from the stack
    /// @return Pointer to removed item as well as a description of the removed item
    IObject* Backpack::unPack() {
        IObject* pObject = mStack.top();
        cout << "Item: " << pObject->getName() << ", stat: " << pObject->getFeature() << endl;
        mStack.pop();
        return pObject;
    }

    /// @brief Checks whether the backpack is empty or not
    /// @return True if not empty, false otherwise
    bool Backpack::isNotEmpty() const {
        if (mStack.size() > 0) {
            return true;
        }
        return false;
    }
}