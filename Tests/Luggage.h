#ifndef LUGGAGE_H
#define LUGGAGE_H


class Luggage {
private:
    int luggageID;
    double width, height, weight;
    static int id;

public:
    Luggage(double width, double height, double weight);
    int getID() const;
    double getWidth() const;
    double getHeight() const;
    double getWeight() const;

    void setWidth(double width);
    void setHeight(double height);
    void setWeight(double weight);

    bool operator ==(const Luggage& right) const;
};



#endif
