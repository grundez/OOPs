#pragma once
#include "Iterator.h"
#include "Hall.h"

class ConcreteIterator : public Iterator {
private:
    const Hall* collection;
    int currentPosition;

public:
    ConcreteIterator(const Hall* collection);
    void first() override;
    void next() override;
    bool isDone() const override;
    Component* currentItem() const override;
};
