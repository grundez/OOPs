#pragma once
#include "Component.h"
#include <string>
#include <vector>
#include "IterableCollection.h"

class Hall : public Component {
private:
    std::string name;
    std::vector<Component*> exhibits;

public:
    Hall(const std::string& name);
    void add(Component* exhibit);
    void remove(Component* exhibit);
    Component* getComponent(int index) const;
    int getComponentsCount() const;
    std::string getName() const override;
    std::string getInfo() const override;
    Iterator* createIterator() const;
    std::vector<Component*> getCollection();
};
