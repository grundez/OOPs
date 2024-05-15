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
        location = "��� ��������";
    }
    void restavration() override {
        std::cout << "��������� �� �����������: " + this->getName() << std::endl;
    }
    void info()override {
        std::cout << "\n" << this->getInfo() << "\n�������: " << location << "\n������: " << size << std::endl;
    }
};

class SculptureExhibit : public IExhibit, Exhibit {
private:
    std::string location;
    std::string sizeOfWLH;
public:
    SculptureExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string size) : Exhibit(id, name, materials, exhIf) {
        sizeOfWLH = size;
        location = "��� ���������";
    }
    void restavration() override {
        std::cout << "��������� �� �����������: " + this->getName() << std::endl;
    }
    void info()override {
        std::cout << "\n" << this->getInfo() << "\n�������: " << location << "\n������: "<< sizeOfWLH << std::endl;
    }
};

class HallFactory{
public:
    virtual IExhibit* createExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string size) = 0;
};

// ���������� ������� ��� �������� �������
class PaintingFactory : public HallFactory {
public:
    IExhibit* createExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string size) override {
        return new PaintingExhibit(id, name, materials, size);
    }
};

// ���������� ������� ��� �������� ����������
class SculptureFactory : public HallFactory {
public:
    IExhibit* createExhibit(int id, const std::string& name, const std::vector<std::string>& materials, std::string size) override {
        return new SculptureExhibit(id, name, materials, size);
    }
};

