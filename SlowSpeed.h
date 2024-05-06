#pragma once
#include "ispeed.h"

class SlowSpeed : public ISpeed {
public:
    void doSpeed() override;
};
