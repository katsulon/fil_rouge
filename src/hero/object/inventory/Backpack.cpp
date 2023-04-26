#include "hero/inventory/Backpack.h"

namespace He_ARC::rpg {
    void Backpack::pack(IObject* pObject) {
        mStack.push(pObject);
    }

    IObject* Backpack::unPack() {
        IObject* pObject = mStack.top();
        cout << "Item: " << pObject->getName() << ", stat: " << pObject->getFeature() << endl;
        mStack.pop();
        return pObject;
    }

    bool Backpack::isNotEmpty() const {
        if (mStack.size() > 0) {
            return true;
        }
        return false;
    }
}