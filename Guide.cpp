#include "Guide.h"

Guide::Guide(ISpeed* s) : speed(s) {}

void Guide::excursion() {
    // Реализация выполнения экскурсии
    speed->doSpeed(); // Делегирование выполнения
}
