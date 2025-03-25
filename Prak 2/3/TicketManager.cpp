#include "TicketManager.hpp"

TicketManager::TicketManager(string eventName) {
    for (int i=0; i<VENUE_CAPACITY; i++) {
        this->tickets[i] = nullptr;
    }
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentVIPTickets = 0;
    this->currentRegularTickets = 0;

}

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity) {
    if (vipCapacity+regularCapacity>VENUE_CAPACITY) {
        cout << "The total capacity you construct is " << vipCapacity+regularCapacity << ", meanwhile the venue capacity is 15" << endl;
    } else {
        for (int i=0; i<VENUE_CAPACITY; i++) {
            this->tickets[i] = nullptr;
        }
        this->eventName = eventName;
        this->vipCapacity = vipCapacity;
        this->regularCapacity = regularCapacity;
        this->ticketCount = 0;
        this->currentVIPTickets = 0;
        this->currentRegularTickets = 0;
    }   
}

TicketManager::~TicketManager() {}

string TicketManager::getEventName() const {
    return this->eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP) {
    string id;
    if (ticketCount >= VENUE_CAPACITY) {
        cout << "Error: All tickets are sold out!" << endl;
        return;
    } else {
        if (isVIP) { // VIP customer
            if (currentVIPTickets >= vipCapacity) {
                cout << "Error: No VIP tickets left!" << endl;
                return;
            } else { // Masih ada slot
                currentVIPTickets++;
                id = "V" + to_string(currentVIPTickets);
                tickets[ticketCount] = new VIPTicket(id, ownerName);
                cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << id << endl;
            }
        } else { // Not VIP
            if (currentRegularTickets >= regularCapacity) {
                cout << "Error: No Regular tickets left!" << endl;
                return;
            } else { // Masih ada slot
                currentRegularTickets++;
                id = "R" + to_string(currentRegularTickets);
                tickets[ticketCount] = new RegularTicket(id, ownerName);
                cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << id << endl;    
            }
        }
    }
    ticketCount++;
}

void TicketManager::checkTicket(const string &ticketID) const {
    for (int i=0; i<this->ticketCount; i++) {
        if (this->tickets[i]->getTicketID() == ticketID) {
            this->tickets[i]->printTicket();
            return;
        }
    }
    cout << "Ticket ID is invalid!" << endl;
}

void TicketManager::listAudience() const {
    if (ticketCount==0) {
        cout << "No audience yet!" << endl;
        return;
    } else {
        for (int i=0; i<ticketCount; i++) {
            cout << i+1 << ". ";
            this->tickets[i]->printTicket();
        }
    }
}

int TicketManager::calculateRevenue() const {
    return ((500*currentVIPTickets)+(275*currentRegularTickets));
}