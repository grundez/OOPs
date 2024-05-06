#include "ticketproxy.h"
#include <iostream>

TicketProxy::TicketProxy() {
    ticket = new Ticket();
}

void TicketProxy::bookTicket() {
    ticket->bookTicket();
    actionLog.push_back("Booked ticket"); // Добавляем запись о бронировании билета в вектор
}

void TicketProxy::cancelTicket() {
    ticket->cancelTicket();
    actionLog.push_back("Canceled ticket"); // Добавляем запись об отмене билета в вектор
}

void TicketProxy::getTicket(int id) {
    std::cout << "\n! Proxy pattern";
    if (id == ticket->getID()) {
        std::cout << "\n\tAction Log of ticket №" << id << std::endl;
        for (const auto& action : actionLog) {
            std::cout << action << std::endl; // Выводим записи о действиях с билетами
        }
    }
    else {
        std::cout << "\nTicket not found.." << std::endl;
    }
}
