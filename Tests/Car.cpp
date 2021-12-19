#include <Car.h>

using namespace std;

Car::Car(int maxStackSize) : maxStackSize(maxStackSize) {}

int Car::getNumberCarriages() {
    return carriages.size();
}

void Car::addCarriage(Carriage carriage) {
    carriages.push(carriage);
}

Carriage Car::popCarriage() {
    Carriage result = carriages.top();
    carriages.pop();
    return result;
}

stack<Carriage> Car::getCarriages() {
    return carriages;
}