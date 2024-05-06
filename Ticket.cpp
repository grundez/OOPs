#include "ticket.h"
#include <iostream>

Ticket::Ticket() {
    id = 1;
    visitor = "Шайдуров М.";
    type = "Regular";
    date = "2024-05-10";
    time = "10:00";
    price = 10.0;
    isBooked = false;
}

int Ticket::getID(){
    return id;
}

void Ticket::bookTicket() {
    if (!isBooked) {
        std::cout << "\n-Ticket booked successfully!" << std::endl;
        isBooked = true;
    }
    else {
        std::cout << "Ticket is already booked!" << std::endl;
    }
}

void Ticket::cancelTicket() {
    if (isBooked) {
        std::cout << "\n-Ticket canceled successfully!" << std::endl;
        isBooked = false;
    }
    else {
        std::cout << "Ticket is not booked yet!" << std::endl;
    }
}

void Ticket::getTicket(int i) {
    if (id == i) {
        std::cout << "\n\tTicket Details:" << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "Visitor: " << visitor << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Time: " << time << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Status: " << (isBooked ? "Booked" : "Not booked") << std::endl;
    }
    else {
        std::cout << "\nTicket not found.." <<  std::endl;
    }
}
