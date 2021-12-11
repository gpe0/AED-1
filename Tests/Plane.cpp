#include "Plane.h"

Plane::Plane(std::string licensePlate, int capacity, std::list<Flight> flights, std::queue<Service> services) : licensePlate(licensePlate), capacity(capacity), flights(flights), services(services) {
    finishedServices = std::queue<Service>();

    for (Flight &flight : this->flights) {
        flight.setAvailableSeats(capacity);
    }
}


std::string Plane::getLicensePlate() const {
    return licensePlate;
}

int Plane::getCapacity() const {
    return capacity;
}

std::list<Flight> Plane::getFlights() const {
    return flights;
}

std::queue<Service> Plane::getServices() const {
    return services;
}

std::queue<Service> Plane::getFinishedServices() const {
    return finishedServices;
}

void Plane::setFlights(std::list<Flight> flights) {
    this->flights.clear();
    for (Flight f : flights) {
        addFlight(f);
    }
}

void Plane::addFlight(Flight flight) {
    flights.push_back(flight);
}


void Plane::addService(Service service) {
    services.push(service);
}