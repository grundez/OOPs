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

// Базовый класс для обработчика запросов
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

// Обработчик для проверки аутентификации пользователя
class AuthenticationHandler : public RequestHandler {
public:
    void handleRequest(const OrderWeb& request) override {
        if (request.getUsername() != "") {
            std::cout << "Пользователь \"" << request.getUsername() << "\" авторизован." << std::endl;
            if (nextHandler) {
                nextHandler->handleRequest(request);
            }
        }
        else {
            std::cout << "Ошибка авторизации.." << std::endl;
        }
    }
};

// Обработчик для проверки статуса VIP пользователя
class VIPStatusHandler : public RequestHandler {
public:
    void handleRequest(const OrderWeb& request) override {
        if (request.isVIPUser()) {
            std::cout << "У пользователя " << request.getUsername() << " VIP статус." << std::endl;
            if (nextHandler) {
                nextHandler->handleRequest(request);
            }
        }
        else {
            std::cout << "У пользователя " << request.getUsername() << " нет VIP статуса." << std::endl;
        }
    }
};
