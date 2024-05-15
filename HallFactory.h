#pragma once
#include "Exhibit.h"
#include <iostream>
#include "ExhibitInformation.h" 
ExhibitInformation exhIf;

class IExhibit {
public:
    virtual void restavration() = 0;
    virtual void info() = 0;
};

class PaintingExhibit : public IExhibit, Exhibit {
private:
    std::string location;
    std::string size;
public:
    PaintingExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string _size) : Exhibit(id, name, materials, exhIf) {
        size = _size;
        location = "Зал живописи";
    }
    void restavration() override {
        std::cout << "Экспонент на рестоврации: " + this->getName() << std::endl;
    }
    void info()override {
        std::cout << "\n" << this->getInfo() << "\nЛокация: " << location << "\nРазмер: " << size << std::endl;
    }
};

class SculptureExhibit : public IExhibit, Exhibit {
private:
    std::string location;
    std::string sizeOfWLH;
public:
    SculptureExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string size) : Exhibit(id, name, materials, exhIf) {
        sizeOfWLH = size;
        location = "Зал скульптур";
    }
    void restavration() override {
        std::cout << "Экспонент на рестоврации: " + this->getName() << std::endl;
    }
    void info()override {
        std::cout << "\n" << this->getInfo() << "\nЛокация: " << location << "\nРазмер: "<< sizeOfWLH << std::endl;
    }
};

class HallFactory{
public:
    virtual IExhibit* createExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string size) = 0;
};

// Конкретная фабрика для создания картины
class PaintingFactory : public HallFactory {
public:
    IExhibit* createExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string size) override {
        return new PaintingExhibit(id, name, materials, size);
    }
};

// Конкретная фабрика для создания скульптуры
class SculptureFactory : public HallFactory {
public:
    IExhibit* createExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string size) override {
        return new SculptureExhibit(id, name, materials, size);
    }
};

