#include "ExhibitInformation.h"

ExhibitInformation::ExhibitInformation(std::string exhibitInfo) {
    info = exhibitInfo;
}
ExhibitInformation::ExhibitInformation() {
    info = "��� ���������� �� ���������..\n";
}

std::string ExhibitInformation::getInfo() {
    return info;
}


