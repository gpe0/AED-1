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

std::vector<Luggage *> Passenger::getLuggage() {
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

Luggage *Passenger::findLuggageWithId(int id) {
    int left = 0, right = luggage.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (luggage[mid]->getID() < id) left = mid + 1;
        else if (id < luggage[mid]->getID()) right = mid - 1;
        else return luggage[mid];
    }
    Luggage * notFound = new Luggage(-1, -1, -1);
    return notFound;
}