#include "ConcreteIterator.h"

ConcreteIterator::ConcreteIterator(const Hall* collection) : collection(collection), currentPosition(0) {}

void ConcreteIterator::first() {
    currentPosition = 0;
}

void ConcreteIterator::next() {
    ++currentPosition;
}

bool ConcreteIterator::isDone() const {
    return currentPosition >= collection->getComponentsCount();
}

Component* ConcreteIterator::currentItem() const {
    if (!isDone()) {
        return collection->getComponent(currentPosition);
    }
    return nullptr;
}