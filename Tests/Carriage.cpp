#include "Carriage.h"

using namespace std;

Carriage::Carriage(double capacity, double width, double heigth) {
    this->capacity = capacity;
    this->availableCapacity = capacity;
    this->width = width;
    this->heigth = heigth;
    this->availableHeigth = heigth;
}

int Carriage::getStackLength() {
    return luggages.size();
}

std::stack<Luggage*> Carriage::getStackNum(int index) {
    list<stack<Luggage*>>::iterator it = luggages.begin();
    for (int i = index; i > 0; i--){
        it++;
    }
    return *it;
}

Carriage& Carriage::operator=(const Carriage &right) {
    availableCapacity = right.availableCapacity;
    capacity = right.capacity;
    heigth = right.heigth;
    width = right.width;
    return *this;
}

list<stack<Luggage *>> Carriage::getLuggages() {
    return luggages;
}

void Carriage::addLugToStackNum(int index, Luggage* luggage) {
    availableCapacity -= (*luggage).getWeight();
    list<stack<Luggage*>>::iterator it = luggages.begin();
    for (int i = index; i > 0; i--){
        it++;
    }
    (*it).push(luggage);
}

double Carriage::getAvailableCapacity() {
    return availableCapacity;
}

double Carriage::getWidth() {
    return width;
}

double Carriage::getCapacity() {
    return capacity;
}

double Carriage::getHeigth() {
    return heigth;
}

void Carriage::addNewStack(Luggage *luggage) {
    availableHeigth -= (*luggage).getHeight();
    availableCapacity -=(*luggage).getWeight();
    stack<Luggage*> newStack;
    newStack.push(luggage);
    luggages.push_back(newStack);
}

double Carriage::getEfficiency() {
    return (capacity-availableCapacity)/capacity;
}
