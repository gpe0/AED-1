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

bool Carriage::addLuggage(Luggage l) {
    if (!luggages.empty() && luggages.top().size() < STACKSIZE) {
        luggages.top().push(l);
        return true;
    }

    if (luggages.size() < STACKNUMBER) {
        stack<Luggage> s;
        s.push(l);
        luggages.push(s);
        return true;
    }

    return false;

}

bool Carriage::removeNextLuggage() {
    if (luggages.empty()) return false;

    luggages.top().pop();

    if (luggages.top().empty()) {
        luggages.pop();
    }

    return true;
}

stack<stack<Luggage>> Carriage::getLuggages() {
    return luggages;
}