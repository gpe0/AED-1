#include "Luggage.h"

using namespace std;

int Luggage::id = 1;

Luggage::Luggage(double width, double height, double weight) {
    this->luggageID = id++;
    this->width = width;
    this->height = height;
    this->weight = weight;
    inCar = false; // assuming it get instantiated with the passenger
}

int Luggage::getID() const {
    return luggageID;
};

double Luggage::getWidth() const {
    return width;
}

double Luggage::getHeight() const {
    return height;
}

double Luggage::getWeight() const {
    return weight;
}

bool Luggage::isInCar() const {
    return inCar;
}

void Luggage::move(bool inCar) {
    this->inCar = inCar;
}

bool Luggage::operator==(const Luggage &right) const {
    return luggageID == right.luggageID;
}



