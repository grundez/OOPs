#pragma once
#include <iostream>
#include "IMap.h"

class InteractiveMap : public IMap{
private:
    int width;
    int height;
public:
    InteractiveMap();
    void display() override;
};