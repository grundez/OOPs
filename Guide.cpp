#include "Guide.h"

Guide::Guide(ISpeed* s) : speed(s) {}

void Guide::excursion() {
    // ���������� ���������� ���������
    speed->doSpeed(); // ������������� ����������
}
