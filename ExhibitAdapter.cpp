#include "ExhibitAdapter.h"

ExhibitAdapter::ExhibitAdapter(Exhibit& exhibitRef, Guide& _guide) : exhibit(exhibitRef), guide(_guide) {
}

void ExhibitAdapter::getInfo() const {
    //��� ����� �� ���� ���������� ��� ����������� � ���������������� ����� 
    std::vector<std::string> content;
    content.push_back("\t����� ���������������:\n");
    content.push_back(exhibit.getInfo());
    guide.setContentToSpeech(content);
}
