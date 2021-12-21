#include "Car.h"

using namespace std;

Car::Car(int maxCarriageNumber) : CARRIAGESNUMBER(maxCarriageNumber){
}

int Car::getMaxNumberCarriages() {
    return CARRIAGESNUMBER;
}

bool Car::addCarriage(Carriage carriage) {
    if (carriages.size() < CARRIAGESNUMBER){
        carriages.push(carriage);
        return true;
    }
    return false;
}

bool Car::popCarriage() {
    if (carriages.empty()) return false;
    carriages.pop();
    return true;
}

stack<Carriage> Car::getCarriages() {
    return carriages;
}

bool Car::addLuggage(Luggage* l) {
    if (carriages.empty() || !carriages.top().addLuggage(l)) return false;
    return true;
}