#include "ticketproxy.h"
#include <iostream>

TicketProxy::TicketProxy() {
    ticket = new Ticket();
}

void TicketProxy::bookTicket() {
    ticket->bookTicket();
    actionLog.push_back("Booked ticket"); // ��������� ������ � ������������ ������ � ������
}

void TicketProxy::cancelTicket() {
    ticket->cancelTicket();
    actionLog.push_back("Canceled ticket"); // ��������� ������ �� ������ ������ � ������
}

void TicketProxy::getTicket(int id) {
    std::cout << "\n! Proxy pattern";
    if (id == ticket->getID()) {
        std::cout << "\n\tAction Log of ticket �" << id << std::endl;
        for (const auto& action : actionLog) {
            std::cout << action << std::endl; // ������� ������ � ��������� � ��������
        }
    }
    else {
        std::cout << "\nTicket not found.." << std::endl;
    }
}
