#include "Carriage.h"

using namespace std;

Carriage::Carriage(int stackNumber, int stackSize) : STACKNUMBER(stackNumber), STACKSIZE(stackSize) {

}


int Carriage::getMaxStackNumber() {
    return STACKNUMBER;
}

int Carriage::getMaxSTackSize() {
    return STACKSIZE;
}

bool Carriage::addLuggage(Luggage* l) {

    if (l->isInCar()) return false;

    if (!luggage.empty() && luggage.top().size() < STACKSIZE) {
        l->move(true);
        luggage.top().push(l);
        return true;
    }

    if (luggage.size() < STACKNUMBER) {
        l->move(true);
        stack<Luggage*> s;
        s.push(l);
        luggage.push(s);
        return true;
    }

    return false;

}

bool Carriage::removeNextLuggage() {
    if (luggage.empty()) return false;

    luggage.top().top()->move(false);
    luggage.top().pop();

    if (luggage.top().empty()) {
        luggage.pop();
    }

    return true;
}

stack<stack<Luggage*>> Carriage::getLuggage() {
    return luggage;
}