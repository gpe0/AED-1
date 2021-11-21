#include "Plain.h"

Plain::Plain(std::string licensePlate, int capacity, std::list<Flight> flights) : licensePlate(licensePlate), capacity(capacity) {
    this->flights = flights;
}


std::string Plain::getLicensePlate() {
    return licensePlate;
}

int Plain::getCapacity() {
    return capacity;
}

std::list<Flight> Plain::getFlights() {
    return flights;
}

void Plain::setFlights(std::list<Flight> flights) {
    this->flights = flights;
}