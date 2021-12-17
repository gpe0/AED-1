#include <Car.h>

using namespace std;

Car::Car(int carriages, int stackNumber, int stackSize): CARRIAGES(carriages) {
    for (int i = 0; i < carriages; i++) {
        this->carriages.emplace_back(stackNumber, stackSize);
    }
}

int Car::getMaxCarriages() {
    return CARRIAGES;
}

bool Car::addLuggage(Luggage* l) {
    for (Carriage &c : carriages) {
        if (c.addLuggage(l)) {
            return true;
        }
    }
    return false;
}

bool Car::removeNextLuggage() {
    for (auto it = carriages.rbegin(); it != carriages.rend(); it++) {
        if ((*it).removeNextLuggage()) {
            return true;
        }
    }
    return false;
}

list<Carriage> Car::getCarriages() {
    return carriages;
}