#pragma once
#include <vector>
#include <algorithm>

// Интерфейс для наблюдателя
class GuideListeners {
public:
    virtual void update(std::string n) = 0;
};

// Интерфейс для субъекта
class GuideManager {
public:
    virtual void attach(GuideListeners* observer) = 0;
    virtual void detach(GuideListeners* observer) = 0;
    virtual void notify(std::string n) = 0;
};
