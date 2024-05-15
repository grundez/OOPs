#pragma once
#include <string>

class Component {
public:
    virtual ~Component() {}
    virtual std::string getName() const = 0;
    virtual std::string getInfo() const = 0;
};
