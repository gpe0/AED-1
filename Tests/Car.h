#ifndef AED_1_CAR_H
#define AED_1_CAR_H
#include <iostream>

class Car{
private:
    int capacity;
    int occupied;
    //vector<Carriage> car;
    //missing class Carriage
public:
    Car();
    //void addCarriage(Carriage aux);
    int getCapacity();
    int getOccupied();
    void setCapacity(int num);
    void setOccupied(int num);
};




#endif //AED_1_CAR_H
