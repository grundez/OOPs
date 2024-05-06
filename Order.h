#pragma once
#include "iorder.h"

class Order {
private:
    IOrder* iorder;
    int idTicket;

public:
    Order(IOrder* i, int id);
    std::string getTypeOfOrder();
};