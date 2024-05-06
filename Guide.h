#pragma once
#include "ispeed.h"

class Guide {
private:
    ISpeed* speed;

public:
    Guide(ISpeed* s);
    void excursion();
};
