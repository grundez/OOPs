#pragma once
#include "IOrder.h"
#include <iostream>
class OrderWeb : public IOrder
{
private:
    std::string username;
    bool isVIP;

public:
    OrderWeb(const std::string& user, bool vip) : username(user), isVIP(vip) {}

    const std::string& getUsername() const {
        return username;
    }

    bool isVIPUser() const {
        return isVIP;
    }
	std::string getTypeOfOrder() override;
};

// ������� ����� ��� ����������� ��������
class RequestHandler {
protected:
    RequestHandler* nextHandler;

public:
    RequestHandler() : nextHandler(nullptr) {}

    void setNextHandler(RequestHandler* handler) {
        nextHandler = handler;
    }

    virtual void handleRequest(const OrderWeb& request) = 0;
};

// ���������� ��� �������� �������������� ������������
class AuthenticationHandler : public RequestHandler {
public:
    void handleRequest(const OrderWeb& request) override {
        if (request.getUsername() != "") {
            std::cout << "������������ \"" << request.getUsername() << "\" �����������." << std::endl;
            if (nextHandler) {
                nextHandler->handleRequest(request);
            }
        }
        else {
            std::cout << "������ �����������.." << std::endl;
        }
    }
};

// ���������� ��� �������� ������� VIP ������������
class VIPStatusHandler : public RequestHandler {
public:
    void handleRequest(const OrderWeb& request) override {
        if (request.isVIPUser()) {
            std::cout << "� ������������ " << request.getUsername() << " VIP ������." << std::endl;
            if (nextHandler) {
                nextHandler->handleRequest(request);
            }
        }
        else {
            std::cout << "� ������������ " << request.getUsername() << " ��� VIP �������." << std::endl;
        }
    }
};
