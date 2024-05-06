#include "exhibit.h"

Exhibit::Exhibit(int i, const std::string& exhibitName)
{
    id = i;
    name = exhibitName;
}

void Exhibit::setName(const std::string& exhibitName) {
    name = exhibitName;
}

std::string Exhibit::getName() {
    return name;
}

std::vector<std::string> Exhibit::getMaterials() {
    return materials;
}

void Exhibit::addMaterial(const std::string& material) {
    materials.push_back(material);
}
