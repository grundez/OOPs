#include <iostream>
#include "Ticket.h"
#include "Exhibit.h"
#include "ExhibitInformation.h"
#include "InteractiveMap.h"
#include "Visitor.h"
#include "DigitalAssistant.h"
#include "Guide.h"
#include "ISpeed.h"
#include "IOrder.h"
#include "SlowSpeed.h"
#include "FastSpeed.h"
#include "OrderWeb.h"
#include "OrderMuseum.h"
#include "TicketProxy.h"
#include "Order.h"

int main() {
    Ticket ticket;
    ticket.bookTicket();
    ticket.getTicket(1);
    
    // Использование прокси для билета
    TicketProxy ticketProxy;
    ticketProxy.bookTicket();
    ticketProxy.cancelTicket();
    OrderMuseum orderType;
    Order order(&orderType, 1);
    std::cout << order.getTypeOfOrder() << std::endl;
    std::cout << "\nInput Ticket number to find: ";
    int idTicket; std::cin >> idTicket;
    ticketProxy.getTicket(idTicket);

    // Делегирование 
    FastSpeed speed; // Создаем объект класса скорости
    Guide guide(&speed); // Передаем объект скорости в конструктор гида
    guide.excursion(); // Вызываем метод экскурсии гида

    return 0;
}
