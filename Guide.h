#pragma once
#include "ispeed.h"
#include "GuideState.h"
#include "GuideManager.h"
#include "Exhibit.h"
#include "ExcursionMemento.h"
#include <vector>
#include <string>
#include <stack>

class Guide : public GuideManager {
private:
    ISpeed* speed;
    GuideState* currentState;
    std::vector<GuideListeners*> observers;
    std::vector<std::string> contentToSpeech;
    std::vector<Exhibit*> exhibits;

public:
    void addExhibit(Exhibit* a) { exhibits.push_back(a); }
    std::vector<Exhibit*> getExhibits() {
        return exhibits;
    }
    ExcursionMemento* saveToMemento();
    void restoreFromMemento(ExcursionMemento* memento);
    Guide(ISpeed* s, GuideState* initialState);
    void setContentToSpeech(std::vector<std::string> content);
    void excursion();
    void stopExcursion();

    void setState(GuideState* newState) {
        currentState = newState;
    }
    // Методы для управления наблюдателями
    void attach(GuideListeners* observer)  {
        observers.push_back(observer);
    }

    void detach(GuideListeners* observer)  {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Метод для уведомления наблюдателей
    void notify(std::string n) {
        for (auto observer : observers) {
            observer->update(n);
        }
    }
};

// Абстрактный класс команды
class ICommand {
public:
    virtual ~ICommand() {}
    virtual void execute() = 0;
};

// Конкретная команда для выполнения экскурсии
class ExcursionCommand : public ICommand {
private:
    Guide* guide_;
    ExcursionMemento* memento;
    std::stack<ExcursionMemento*> history;

public:
    ExcursionCommand(Guide* guide) : guide_(guide), memento(nullptr) {}

    void execute() override {
        if (guide_) {
            memento = guide_->saveToMemento();
            history.push(memento);
            guide_->excursion();
        }
        else {
            std::cout << "Ошибка: гид не указан" << std::endl;
        }
    }

    void undo() {
        if (!history.empty()) {
            ExcursionMemento* prevMemento = history.top();
            guide_->restoreFromMemento(prevMemento);
            history.pop();
            delete prevMemento;
        }
    }
};

// Класс, который инициирует выполнение команд
class Invoker {
private:
    ICommand* command_;

public:
    void setCommand(ICommand* command) {
        command_ = command;
    }

    void executeCommand() {
        if (command_) {
            command_->execute();
        }
        else {
            std::cout << "Команда не установлена" << std::endl;
        }
    }
};