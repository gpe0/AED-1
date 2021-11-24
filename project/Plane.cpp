#include "Plane.h"

Plane::Plane(std::string licensePlate, int capacity, std::list<Flight> flights, std::queue<Service> services) : licensePlate(licensePlate), capacity(capacity) {
    this->flights = flights;
    this->services = services;
    finishedServices = std::queue<Service>();
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
    this->flights = flights;
}

void Plane::addService(Service service) {
    services.push(service);
}