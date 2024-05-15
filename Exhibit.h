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
    Exhibit(int i, const std::string& exhibitName); // ��������� ����������� ��� singleton

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
    // ����� ��� �������� ����� ���������
    Exhibit* clone() {
        return new Exhibit(*this);
    }
};

// ���������� ����� �������
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

    // ���������� ����������� ��� �������� ����� �������
    Painting(const Painting& other) : id(other.id), name(other.name), materials(other.materials), exhibitInfo(other.exhibitInfo), w(other.w), h(other.h),
        Exhibit(other.id, other.name, other.materials, other.exhibitInfo) {}

    // ����� ��� �������� ����� ���������
    Painting* clone() const  {
        return new Painting(*this);
    }

    // ����� ��� ����������� ���������� � �������
    void displayInfo() const  {
        std::cout << "�������: " << name << "\n�������: " << w<<"x"<<h << "\n����������: " << exhibitInfo.getInfo() << std::endl;
    }

    void resize(double _w, double _h) {
        std::cout << "������� " + this->getName() + " �������� ���� ������" << std::endl;
        w = _w;
        h = _h;
    }
};

// ���������� ����� ����������
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

    // ���������� ����������� ��� �������� ����� �������
    Sculpture(const Sculpture& other) : id(other.id), name(other.name), materials(other.materials), exhibitInfo(other.exhibitInfo), w(other.w), h(other.h), l(other.l),
        Exhibit(other.id, other.name, other.materials, other.exhibitInfo) {}

    // ����� ��� �������� ����� ���������
    Sculpture* clone() const  {
        return new Sculpture(*this);
    }

    // ����� ��� ����������� ���������� � ����������
    void displayInfo() const  {
        std::cout << "����������: " << name << "\n�������: " << w << "x" << h <<"x"<<l <<"\n����������: " << exhibitInfo.getInfo() << std::endl;
    }

    void changeDegreePos(double degree) {
        std::cout << "���������� " + this->getName() + " ����������� �� ���� " << degree << std::endl;
    }
};

// ����� ��� ���� ��������
class ExhibitPool {
private:
    std::vector<Exhibit*> pool_;

public:
    // �����������, ������� �������������� ������� ������� � ��������� �� � ���
    ExhibitPool(std::vector<Exhibit*> pool) {
        ExhibitInformation unknw;
        for (auto p : pool) {
            pool_.push_back(p);
        } 
    }

    // ����� ��� ������ ������� �� ����
    Exhibit* rentExhibit() {
        if (!pool_.empty()) {
            Exhibit* exhibit = pool_.back();
            pool_.pop_back();
            return exhibit;
        }
        else {
            std::cout << "��� ����!" << std::endl;
            return nullptr;
        }
    }

    // ����� ��� �������� ������� � ���
    void returnExhibit(Exhibit* exhibit) {
        pool_.push_back(exhibit);
    }

    // ���������� 
    ~ExhibitPool() {
        for (auto exhibit : pool_) {
            delete exhibit;
        }
    }
};
