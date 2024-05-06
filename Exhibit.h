#pragma once
#include <string>
#include <vector>

class Exhibit {
private:
    int id;
    std::string name;
    std::vector<std::string> materials;

public:
    Exhibit(int i, const std::string& exhibitName);
    void setName(const std::string& exhibitName);
    std::string getName();
    std::vector<std::string> getMaterials();
    void addMaterial(const std::string& material);
};
