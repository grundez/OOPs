#pragma once
#include <string>
#include "ITicket.h"

class Ticket : public ITicket {
private:
    int id;
    std::string visitor;
    std::string type;
    std::string date;
    std::string time;
    double price;
    bool isBooked;

public:
    Ticket();
    int getID();
    void bookTicket();
    void cancelTicket();
    void getTicket(int id);
};
