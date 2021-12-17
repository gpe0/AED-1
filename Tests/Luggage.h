#ifndef LUGGAGE_H
#define LUGGAGE_H


class Luggage {
private:
    static int id;
    int luggageID;
    double width, height, weight;
    bool inCar;

public:

    /**Initializes a luggage with a width, height and weight (the id is given automatically)
     *
     * @param width width
     * @param height height
     * @param weight weight
     */
    Luggage(double width, double height, double weight);

    /**Returns the luggage's id
     *
     * @return id
     */
    int getID() const;

    /**Returns luggage's width
     *
     * @return width
     */
    double getWidth() const;

    /**Returns luggage's height
     *
     * @return height
     */
    double getHeight() const;

    /**Returns luggage's weight
     *
     * @return weight
     */
    double getWeight() const;

    /**Returns if the luggage is in the transport car or not
     *
     * @return true - it is in the car ; false - it isn't in the car
     */
    bool isInCar() const;

    /**Moves the luggage to the transport car or to the passenger
     *
     * @param inCar true - it is in the car ; false - it is with the passenger
     */
    void move(bool inCar);

    bool operator ==(const Luggage& right) const;
};



#endif
