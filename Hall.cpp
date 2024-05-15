#include "Hall.h"
#include <iostream>
#include "ConcreteIterator.h"

Hall::Hall(const std::string& name) : name(name) {}

void Hall::add(Component* exhibit) {
    exhibits.push_back(exhibit);
}

void Hall::remove(Component* exhibit) {
    // 
}

Component* Hall::getComponent(int index) const {
    if (index >= 0 && index < exhibits.size()) {
        return exhibits[index];
    }
    return nullptr;
}

int Hall::getComponentsCount() const {
    return exhibits.size();
}

std::string Hall::getName() const {
    return name;
}

std::string Hall::getInfo() const {
    std::string info = "Зал: " + name + "\nЭкспонаты:\n";
    for (const Component* exhibit : exhibits) {
        info += exhibit->getInfo() + "\n\n";
    }
    return info;
}

Iterator* Hall::createIterator() const {
    return new ConcreteIterator(this);
}

std::vector<Component*> Hall::getCollection() {
    return exhibits;
}