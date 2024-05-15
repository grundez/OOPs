#include "HighlightDecorator.h"
#include <iostream>

HighlightDecorator::HighlightDecorator(InteractiveMap* baseMap, std::vector<std::string> _highlits) : InteractiveMapDecorator(baseMap) {
    for (auto high : _highlits) {
        highlits.push_back(high);
        highlits.push_back(", ");
    }
    highlits.pop_back();
}

void HighlightDecorator::display() const {
    highlightExhibits(); // Вызываем метод подсветки экспонатов
}

void HighlightDecorator::highlightExhibits() const {
    // Реализация подсветки интересных пользователю экспонатов
    std::cout << "Подсветка интересных пользователю экспонатов на карте:" << std::endl;
    for (auto high : highlits) {
        std::cout << high;
    }
    std::cout << std::endl;
}
