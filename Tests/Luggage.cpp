#include "Luggage.h"

using namespace std;

int Luggage::id = 1;

Luggage::Luggage(double width, double height, double weight) {
    this->luggageID = id++;
    this->width = width;
    this->height = height;
    this->weight = weight;
}

int Luggage::getID(){
    return luggageID;
};

double Luggage::getWidth() {
    return width;
}

double Luggage::getHeight() {
    return height;
}

double Luggage::getWeight() {
    return weight;
}

void Luggage::setWidth(double width) {
    this->width = width;
}

void Luggage::setHeight(double height) {
    this->height = height;
}

void Luggage::setWeight(double weight) {
    this->weight = weight;
}



