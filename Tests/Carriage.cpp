#include "Carriage.h"

using namespace std;

Carriage::Carriage(int stackNumber, int stackSize, double capacity) {
    this->stackNumber = stackNumber;
    this->stackSize = stackSize;
    this->capacity = capacity;
    this->availableCapacity = capacity;
}

int Carriage::getMaxStackNumber() {
    return stackNumber;
}

int Carriage::getMaxStackSize() {
    return stackSize;
}

bool Carriage::addLuggage(Luggage* l) {

    if (stackSize == 0 || availableCapacity < l->getWeight()) return false;

    if (!luggage.empty() && luggage.back().size() < stackSize) {
        luggage.back().push(l);
        availableCapacity -= l->getWeight();
        return true;
    }

    if (luggage.size() < stackNumber) {

        stack<Luggage *> s;
        s.push(l);
        luggage.push_back(s);
        availableCapacity -= l->getWeight();
        return true;
    }

    return false;

}

bool Carriage::removeNextLuggage() {
    if (luggage.empty()) return false;

    luggage.back().pop();

    if (luggage.back().empty()) {
        luggage.pop_back();
    }

    return true;
}


list<stack<Luggage *>> Carriage::getLuggage() {
    return luggage;
}


double Carriage::getAvailableCapacity() {
    return availableCapacity;
}


double Carriage::getCapacity() {
    return capacity;
}

double Carriage::getEfficiency() {
    return (capacity-availableCapacity)/capacity;
}

Carriage& Carriage::operator=(const Carriage &right) {
    availableCapacity = right.availableCapacity;
    capacity = right.capacity;
    stackNumber = right.stackNumber;
    stackSize = right.stackSize;
    luggage = right.luggage;
    return *this;
}

bool Carriage::operator==(const Carriage &right) {
    return (stackNumber == right.stackNumber && stackSize == right.stackSize && capacity == right.capacity);
}