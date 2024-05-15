#pragma once
#include "InteractiveMap.h"

class InteractiveMapDecorator : public InteractiveMap {
protected:
    InteractiveMap* map;

public:
    InteractiveMapDecorator(InteractiveMap* baseMap);
    virtual void display();
};
