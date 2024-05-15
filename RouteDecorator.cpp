#include "RouteDecorator.h"
#include <iostream>

RouteDecorator::RouteDecorator(InteractiveMap* baseMap, std::vector<std::string> _path) : InteractiveMapDecorator(baseMap) {
    for (auto place : _path) {
        path.push_back(place);
        path.push_back(" -> ");
    }
    path.pop_back();
}

void RouteDecorator::display() const {
    displayRoute(); // Общий метод отображения от интерфейса
}

void RouteDecorator::displayRoute() const {
    // Реализация отображения маршрута
    std::cout << "Маршрут экскурсии наложен на карту:" << std::endl;
    for (auto place : path) {
        std::cout << place;
    }
    std::cout << std::endl;
}
