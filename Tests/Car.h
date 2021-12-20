#ifndef CAR_H
#define CAR_H

#include <list>
#include "Carriage.h"

class Car {
private:
    std::stack<Carriage> carriages;
    const int CARRIAGESNUMBER;
public:

    /**Initializes a car with the max number of carriages.
     *  The max number of stacks and the max stack size is carriage information
     * @param maxCarriageNumber max carriages' number
     */
    Car(int maxCarriageNumber);

    /**Returns the max number of carriages
     *
     * @return
     */
    int getMaxNumberCarriages();

    /**Adds a carriage to the car
     *
     * @param carriage
     * @return true - it was added ; false - it wasn't
     */
    bool addCarriage(Carriage carriage);

    /**Removes the farther carriage (to the car)
     *
     * @return whether it passed or failed
     */
    bool popCarriage();

    /**Returns the stack of carriages
     *
     * @return list of carriages
     */
    std::stack<Carriage> getCarriages();

    /**Tries to add a luggage to the last carriage of the stack
     *
     * @param l luggage
     * @return true - it was added ; false - it wasn't
     */
    bool addLuggage(Luggage* l);
};




#endif
