#include "ExcursionMemento.h"

ExcursionMemento::ExcursionMemento(const std::vector<std::string>& content) : contentToSpeech(content) {}

std::vector<std::string> ExcursionMemento::getSavedState() const {
    return contentToSpeech;
}