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
        // ��������� ���� ���� ��� ������
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
 
        // ���������� ���������� �� ��������� � ���
        logfile << "������ ��������: " << exhibitName << " � ���� " << location << std::endl;
    }

    ~ExhibitSingleton() {
        // ��������� ���� ���� ��� ����������� ���������
        logfile.close();
    }
};

ExhibitSingleton* ExhibitSingleton::instance = nullptr;
bool ExhibitSingleton::initialized = false;
