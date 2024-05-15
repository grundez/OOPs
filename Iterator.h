#pragma once
#include "Component.h"

class Iterator {
public:
    virtual ~Iterator() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual Component* currentItem() const = 0;
};
