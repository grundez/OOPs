#pragma once
#include <iostream>

// ��������� ���������
class GuideState {
public:
    virtual void handleExcursion() = 0;
    virtual void handleRest() = 0;

};

// ���������� ���������: ����������
class ReadyState : public GuideState {
private:
public:
    void handleExcursion() override {
        std::cout << "��� �����, �������� ���������!" << std::endl;
    }

    void handleRest() override {
        std::cout << "������ ��������, ���� �� ������ ���������!" << std::endl;
    }
};

// ���������� ���������: ���������� ���������
class ExcursionState : public GuideState {
public:
    void handleExcursion() override {
        std::cout << "��������� ��� ����!" << std::endl;
    }

    void handleRest() override {
        std::cout << "��������� �� �����!" << std::endl;
    }
};

// ���������� ���������: �����
class RestingState : public GuideState {
public:
    void handleExcursion() override {
        std::cout << "������ ������ ���������, ���� ��������!" << std::endl;
    }

    void handleRest() override {
        std::cout << "���������� �����!" << std::endl;
    }
};

