#pragma once
#include "ticket.h"
#include "iticket.h"
#include <vector>
#include <string>

class TicketProxy : public ITicket {
private:
    Ticket* ticket;
    std::vector<std::string> actionLog; // ¬ектор дл€ хранени€ записей о действи€х с билетами

public:
    TicketProxy();
    void bookTicket() ;
    void cancelTicket() ;
    void getTicket(int id); // ћетод дл€ вывода записей о действи€х с билетами
};
