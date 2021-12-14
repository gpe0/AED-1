#ifndef CAR_H
#define CAR_H
#include <iostream>

class Car {
private:
    const int MAXCARRIAGES;
    //stack<Carriage> carriages;
public:
    Car(int MaxCarriages);
    //void addCarriage(Carriage aux);
    int getMaxCarriages();
};




#endif
