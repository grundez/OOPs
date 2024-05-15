#include "Guide.h"
#include "iostream"

Guide::Guide(ISpeed* s, GuideState* initialState) : speed(s), currentState(initialState) {}

void Guide::excursion() {
    currentState->handleExcursion();
    // Реализация выполнения экскурсии
    speed->doSpeed(); // Делегирование выполнения
    for (auto sentences : contentToSpeech) {
        std::cout << sentences;
    }
    std::cout << std::endl;
}

void Guide::setContentToSpeech(std::vector<std::string> content) {
    contentToSpeech = content;
}

void Guide::stopExcursion() {
    std::cout << "Гид ушел отдыхать\n";
    setState(new RestingState());
}

ExcursionMemento* Guide::saveToMemento() {
    return new ExcursionMemento(contentToSpeech);
}

void Guide::restoreFromMemento(ExcursionMemento* memento) {
    contentToSpeech = memento->getSavedState();
}
