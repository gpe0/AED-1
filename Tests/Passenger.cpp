#include <list>
#include <iostream>
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