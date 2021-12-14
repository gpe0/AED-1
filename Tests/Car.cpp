#include <Car.h>

using namespace std;

Car::Car(int MaxCarriages): MAXCARRIAGES(MaxCarriages) {

}

int Car::getMaxCarriages() {
    return MAXCARRIAGES;
}