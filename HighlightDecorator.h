#pragma once
#include "InteractiveMapDecorator.h"
#include <vector>

class HighlightDecorator : public InteractiveMapDecorator {
private:
    std::vector<std::string> highlits;
public:
    HighlightDecorator(InteractiveMap* baseMap, std::vector<std::string> _highlits);
    void display() const;
    void highlightExhibits() const;
};