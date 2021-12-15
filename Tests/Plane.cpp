#include <iostream>
#include "Plane.h"

using namespace std;

Plane::Plane(std::string licensePlate, std::string type, int capacity, list<Flight> flights, queue<Service> services) : LICENSEPLATE(licensePlate), TYPE(type) , CAPACITY(capacity), flights(flights), services(services) {
    finishedServices = std::queue<Service>();

    for (Flight &flight : this->flights) {
        flight.setAvailableSeats(capacity);
    }

    if (licensePlate.size() != 4) throw InvalidPlane("Invalid License Plate");

    for (int i = 0; i < type.size(); i++) {
        if (i == 0 && !(type[i] >= 'A' && type[i] <= 'Z')) {
            throw InvalidPlane("Invalid License Plate");
        }

        if (i != 0 && !(type[i] >= '0' && type[i] <= '9')) {
            throw InvalidPlane("Invalid License Plate");
        }

    }

}

string Plane::getLicensePlate() const {
    return LICENSEPLATE;
}

std::string Plane::getType() const {
    return TYPE;
}

int Plane::getCapacity() const {
    return CAPACITY;
}

list<Flight> Plane::getFlights() const {
    return flights;
}

queue<Service> Plane::getServices() const {
    return services;
}

queue<Service> Plane::getFinishedServices() const {
    return finishedServices;
}

void Plane::setFlights(list<Flight> flights) {
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