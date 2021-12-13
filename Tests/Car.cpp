#include <Car.h>

using namespace std;
/*
Car::Car() {
    occupied = 0;
    capacity = 0;
    car.clear();
}

void Car::addCarriage(Carriage aux){
    if (capacity > occupied) {
        car.push_back(aux);
        setOccupied(occupied + 1);
    }
    else {
        throw (runtime_error("Car is full"));
    }
    return;
}
*/
int Car::getCapacity() {
    return capacity;
}

int Car::getOccupied() {
    return occupied;
}

void Car::setCapacity(int num) {
    capacity = num;
}

void Car::setOccupied(int num) {
    occupied = num;
}