#include <Car.h>

using namespace std;

Car::Car(int carriages): CARRIAGES(carriages) {

}

int Car::getMaxCarriages() {
    return CARRIAGES;
}

bool Car::addLuggage(Luggage l) {
    for (Carriage &c : carriages) {
        if (c.addLuggage(l)) {
            return true;
        }
    }
    return false;
}

bool Car::removeNextLuggage() {
    for (auto it = --carriages.end(); it != --carriages.begin(); it--) {
        if ((*it).removeNextLuggage()) {
            return true;
        }
        it = --carriages.erase(it);
    }
    return false;
}

list<Carriage> Car::getCarriages() {
    return carriages;
}