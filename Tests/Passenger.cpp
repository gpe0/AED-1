#include <list>
#include "Passenger.h"

using namespace std;

bool Passenger::acquireTicket(int flightNum, Plane& plane, bool hasLuggage,  int tickets) {

    list<Flight> flights;
    bool hasTicket = false;
    for (Flight & flight : plane.getFlights()) {
        if (flight.getNum() == flightNum) {
            if (tickets <= flight.getAvailableSeats()) {
                flight.setAvailableSeats(flight.getAvailableSeats() - tickets);
                hasTicket = true;
            }
        }
        flights.push_back(flight);
    }

    plane.setFlights(flights);

    return hasTicket;
}

std::list<Luggage *> Passenger::getLuggage() {
    return luggage;
}

void Passenger::addLuggage(Luggage* l) {
    luggage.push_back(l);
}

bool Passenger::removeLuggage(Luggage* l) {
    for (auto it = luggage.begin(); it != luggage.end(); it++) {
        if (*l == *(*it)) {
            luggage.erase(it);
            return true;
        }
    }
    return false;
}