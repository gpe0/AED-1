#ifndef CAR_H
#define CAR_H

#include <list>
#include "Carriage.h"

class Car {
private:
    const int CARRIAGES;
    list<Carriage> carriages;
public:
    Car(int carriages);
    //void addCarriage(Carriage aux);
    int getMaxCarriages();

    bool addLuggage(Luggage l);
    bool removeNextLuggage();

    list<Carriage> getCarriages();
};




#endif
