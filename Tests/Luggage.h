#ifndef LUGGAGE_H
#define LUGGAGE_H


class Luggage {
private:
    int luggageID;
    double width, height, weight;
    static int id;

public:
    Luggage(double width, double height, double weight);
    int getID(); //returns number of suitcases
    double getWidth();
    double getHeight();
    double getWeight();

    void setWidth(double width);
    void setHeight(double height);
    void setWeight(double weight);
};



#endif
