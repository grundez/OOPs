#include "ExhibitInformation.h"

ExhibitInformation::ExhibitInformation(std::string exhibitInfo) {
    info = exhibitInfo;
}
ExhibitInformation::ExhibitInformation() {
    info = "нет информации об экспонате..\n";
}

std::string ExhibitInformation::getInfo() {
    return info;
}


