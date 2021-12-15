#ifndef CAR_H
#define CAR_H

#include <list>
#include "Carriage.h"

class Car {
private:
    const int CARRIAGES;
    list<Carriage> carriages;
public:
    Car(int carriages, int stackNumber, int stackSize);

    int getMaxCarriages();

    bool addLuggage(Luggage l);
    bool removeNextLuggage();

    list<Carriage> getCarriages();
};




#endif
