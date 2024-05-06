#include "order.h"
#include <string>

Order::Order(IOrder* i,int id) {
    iorder = i;
    idTicket = id;
}

std::string Order::getTypeOfOrder() {
    return iorder->getTypeOfOrder(); // Делегирование
}