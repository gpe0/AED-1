#include <Luggage.h>

using namespace std;

Luggage::Luggage(int luggageID, double width, double height, double weight) {
    luggageID = 0;
    width = 0;
    height = 0;
    weight = 0;
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

void Luggage::setID(int num) {
    luggageID = num;
}

void Luggage::setWeight(double num) {
    weight = num;
}

void Luggage::setHeight(double num) {
    height = num;
}

void Luggage::setWidth(double num) {
    width = num;
}