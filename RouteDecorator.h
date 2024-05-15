#pragma once
#include "InteractiveMapDecorator.h"
#include <vector>

class RouteDecorator : public InteractiveMapDecorator {
private:
    std::vector<std::string> path;
public:
    RouteDecorator(InteractiveMap* baseMap, std::vector<std::string> _path);
    void display() const;
    void displayRoute() const;
};