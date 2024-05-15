#pragma once
#include <string>

class ExhibitInformation{
private:
    std::string info;

public:
    ExhibitInformation(std::string exhibitInfo);
    ExhibitInformation();
    std::string getInfo();
};


