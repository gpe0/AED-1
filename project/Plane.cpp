#include "Plane.h"

Plane::Plane(std::string licensePlate, int capacity, std::list<Flight> flights) : licensePlate(licensePlate), capacity(capacity) {
    this->flights = flights;
}


std::string Plane::getLicensePlate() {
    return licensePlate;
}

int Plane::getCapacity() {
    return capacity;
}

std::list<Flight> Plane::getFlights() {
    return flights;
}

void Plane::setFlights(std::list<Flight> flights) {
    this->flights = flights;
}