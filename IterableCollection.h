#pragma once
#include "Iterator.h"

class IterableCollection {
public:
    virtual ~IterableCollection() {}
    virtual Iterator* createIterator() const = 0;
};
