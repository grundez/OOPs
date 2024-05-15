#pragma once
#include <vector>
#include <string>

class ExcursionMemento {
private:
    std::vector<std::string> contentToSpeech;

public:
    ExcursionMemento(const std::vector<std::string>& content);
    std::vector<std::string> getSavedState() const;
};