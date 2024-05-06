#pragma once
#include <vector>
#include <string>

class Visitor {
public:
    void updateProfile();
    std::vector<std::string> getVisitHistory();
    void addFavoriteExhibit();
    void getRecommendation();
};
