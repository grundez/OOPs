#include <iostream>
#include "GuideManager.h"

class Visitor : public GuideListeners {
public:
    // �����, ������� ���������� ��� ���������� ��������� ����
    void update(std::string n)  {
        std::cout << "����������: " + n << std::endl;
    }
};
