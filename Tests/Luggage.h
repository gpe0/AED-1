#include <stack>
#include <iostream>

#ifndef AED_1_LUGGAGE_H
#define AED_1_LUGGAGE_H

class Luggage {
private:
    int luggageID;
    double width, height, weight;

public:
    Luggage(int luggageID, double width, double height, double weight);
    int getID(); //returns number of suitcases
    double getWidth();
    double getHeight();
    double getWeight();
    void setID(int num);
    void setWidth(double num);
    void setHeight(double num);
    void setWeight(double num);
};



#endif //AED_1_LUGGAGE_H
