#include "Exhibit.h"
ExhibitInformation exhInf;

Exhibit::Exhibit() : id(0), name(""), materials({""}), exhibitInfo(exhInf) {}

Exhibit::Exhibit(const Exhibit& other)
    : id(other.id), name(other.name), materials(other.materials), exhibitInfo(other.exhibitInfo) {}

Exhibit::Exhibit(int i, const std::string& exhibitName, const std::vector<std::string>& mats, ExhibitInformation& exhInf)
    : id(i), name(exhibitName), materials(mats), exhibitInfo(exhInf) {}

void Exhibit::setName(const std::string& exhibitName) {
    name = exhibitName;
}

std::string Exhibit::getName() const {
    return name;
}

std::vector<std::string> Exhibit::getMaterials() const {
    return materials;
}

void Exhibit::addMaterial(const std::string& material) {
    materials.push_back(material);
}

std::string Exhibit::getInfo() const {
    std::string mats;
    for (const auto& mat : materials) {
        mats += mat + ", ";
    }
    mats.erase(mats.size() - 2); // Remove trailing comma and space
    return "Экспонат №" + std::to_string(id) + ": " + name + "\nМатериалы: " + mats + "\n" + exhibitInfo.getInfo();
}

int Exhibit::getID() const {
    return id;
}

