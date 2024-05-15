#pragma once
#include <iostream>

// Интерфейс состояния
class GuideState {
public:
    virtual void handleExcursion() = 0;
    virtual void handleRest() = 0;

};

// Конкретное состояние: готовность
class ReadyState : public GuideState {
private:
public:
    void handleExcursion() override {
        std::cout << "Гид готов, начинаем экскурсию!" << std::endl;
    }

    void handleRest() override {
        std::cout << "Нельзя отдыхать, пока не начата экскурсия!" << std::endl;
    }
};

// Конкретное состояние: проведение экскурсии
class ExcursionState : public GuideState {
public:
    void handleExcursion() override {
        std::cout << "Экскурсия уже идет!" << std::endl;
    }

    void handleRest() override {
        std::cout << "Остановка на отдых!" << std::endl;
    }
};

// Конкретное состояние: отдых
class RestingState : public GuideState {
public:
    void handleExcursion() override {
        std::cout << "Нельзя начать экскурсию, пока отдыхаем!" << std::endl;
    }

    void handleRest() override {
        std::cout << "Продолжаем отдых!" << std::endl;
    }
};

