#pragma once
#include <iostream>
#include <fstream>
#include <string>

class ExhibitSingleton {
private:
    static ExhibitSingleton* instance;
    static bool initialized;
    std::ofstream logfile;

    ExhibitSingleton() {
        // Открываем файл лога для записи
        logfile.open("exhibit_log.txt", std::ios::app);
    }

public:
    static ExhibitSingleton* getInstance() {
        if (!initialized) {
            instance = new ExhibitSingleton();
            initialized = true;
        }
        return instance;
    }

    void logExhibitCreation(const std::string& exhibitName, const std::string& location) {
 
        // Записываем информацию об экспонате в лог
        logfile << "Создан экспонат: " << exhibitName << " в зале " << location << std::endl;
    }

    ~ExhibitSingleton() {
        // Закрываем файл лога при уничтожении синглтона
        logfile.close();
    }
};

ExhibitSingleton* ExhibitSingleton::instance = nullptr;
bool ExhibitSingleton::initialized = false;
