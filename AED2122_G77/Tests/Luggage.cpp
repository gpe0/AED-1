#include "Luggage.h"

using namespace std;

int Luggage::id = 1;

Luggage::Luggage(double width, double height, double weight) {
    this->luggageID = id++;
    this->width = width;
    this->height = height;
    this->weight = weight;
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

bool Luggage::operator==(const Luggage &right) const {
    return luggageID == right.luggageID;
}