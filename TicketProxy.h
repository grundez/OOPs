#pragma once
#include "ticket.h"
#include "iticket.h"
#include <vector>
#include <string>

class TicketProxy : public ITicket {
private:
    Ticket* ticket;
    std::vector<std::string> actionLog; // ������ ��� �������� ������� � ��������� � ��������

public:
    TicketProxy();
    void bookTicket() ;
    void cancelTicket() ;
    void getTicket(int id); // ����� ��� ������ ������� � ��������� � ��������
};
