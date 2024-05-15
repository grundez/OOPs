#include <iostream>
#include "GuideManager.h"

class Visitor : public GuideListeners {
public:
    // Метод, который вызывается при обновлении состояния гида
    void update(std::string n)  {
        std::cout << "Посетителю: " + n << std::endl;
    }
};
