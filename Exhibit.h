#pragma once
#include "Component.h"
#include "ExhibitInformation.h"
#include <string>
#include <vector>
#include <iostream>

class Exhibit : public Component {
private:
    int id;
    std::string name;
    std::vector<std::string> materials;
    ExhibitInformation& exhibitInfo;
    Exhibit(int i, const std::string& exhibitName); // приватный конструктор для singleton

public:
    Exhibit();
    Exhibit(int i, const std::string& exhibitName, const std::vector<std::string>& mats, ExhibitInformation& exhInf);
    Exhibit(const Exhibit& other);
    Exhibit(int i, const std::string& exhibitName, const std::vector<std::string>& mats);
    void setName(const std::string& exhibitName);
    std::string getName() const override;
    std::vector<std::string> getMaterials() const;
    void addMaterial(const std::string& material);
    std::string getInfo() const override;
    int getID() const;
    // Метод для создания копии экспоната
    Exhibit* clone() {
        return new Exhibit(*this);
    }
};

// Конкретный класс картины
class Painting : public Exhibit {
private:
    int id;
    std::string name;
    std::vector<std::string> materials;
    ExhibitInformation& exhibitInfo;
    double w;
    double h;

public:
    Painting(int i, const std::string& exhibitName, const std::vector<std::string>& mats, ExhibitInformation& exhInf, double w, double h) :
        id(i), name(exhibitName), materials(mats), exhibitInfo(exhInf), w(w), h(h),
        Exhibit(i, exhibitName, mats, exhInf) {}

    // Копирующий конструктор для создания копии объекта
    Painting(const Painting& other) : id(other.id), name(other.name), materials(other.materials), exhibitInfo(other.exhibitInfo), w(other.w), h(other.h),
        Exhibit(other.id, other.name, other.materials, other.exhibitInfo) {}

    // Метод для создания копии экспоната
    Painting* clone() const  {
        return new Painting(*this);
    }

    // Метод для отображения информации о картины
    void displayInfo() const  {
        std::cout << "Картина: " << name << "\nРазмеры: " << w<<"x"<<h << "\nИнформация: " << exhibitInfo.getInfo() << std::endl;
    }

    void resize(double _w, double _h) {
        std::cout << "Картина " + this->getName() + " изменила свой размер" << std::endl;
        w = _w;
        h = _h;
    }
};

// Конкретный класс скульптуры
class Sculpture : public Exhibit {
private:
    int id;
    std::string name;
    std::vector<std::string> materials;
    ExhibitInformation& exhibitInfo;
    double w;
    double h;
    double l;

public:
    Sculpture(int i, const std::string& exhibitName, const std::vector<std::string>& mats, ExhibitInformation& exhInf, double w, double h, double l) :
        id(i), name(exhibitName), materials(mats), exhibitInfo(exhInf), w(w), h(h), l(l), 
        Exhibit(i, exhibitName,  mats, exhInf) {}

    // Копирующий конструктор для создания копии объекта
    Sculpture(const Sculpture& other) : id(other.id), name(other.name), materials(other.materials), exhibitInfo(other.exhibitInfo), w(other.w), h(other.h), l(other.l),
        Exhibit(other.id, other.name, other.materials, other.exhibitInfo) {}

    // Метод для создания копии экспоната
    Sculpture* clone() const  {
        return new Sculpture(*this);
    }

    // Метод для отображения информации о скульптуре
    void displayInfo() const  {
        std::cout << "Скульптура: " << name << "\nРазмеры: " << w << "x" << h <<"x"<<l <<"\nИнформация: " << exhibitInfo.getInfo() << std::endl;
    }

    void changeDegreePos(double degree) {
        std::cout << "Скульптура " + this->getName() + " повернулась на угол " << degree << std::endl;
    }
};

// Класс для пула объектов
class ExhibitPool {
private:
    std::vector<Exhibit*> pool_;

public:
    // Конструктор, который предварительно создает объекты и добавляет их в пул
    ExhibitPool(std::vector<Exhibit*> pool) {
        ExhibitInformation unknw;
        for (auto p : pool) {
            pool_.push_back(p);
        } 
    }

    // Метод для аренды объекта из пула
    Exhibit* rentExhibit() {
        if (!pool_.empty()) {
            Exhibit* exhibit = pool_.back();
            pool_.pop_back();
            return exhibit;
        }
        else {
            std::cout << "Пул пуст!" << std::endl;
            return nullptr;
        }
    }

    // Метод для возврата объекта в пул
    void returnExhibit(Exhibit* exhibit) {
        pool_.push_back(exhibit);
    }

    // Деструктор 
    ~ExhibitPool() {
        for (auto exhibit : pool_) {
            delete exhibit;
        }
    }
};
