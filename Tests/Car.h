#ifndef CAR_H
#define CAR_H

#include <list>
#include "Carriage.h"

class Car {
private:
    std::stack<Carriage> carriages;
    int maxStackSize;
public:

    /**Initializes a car with the max number of carriages.
     *  The max number of stacks and the max stack size is carriage information
     * @param carriages max carriages' number
     * @param stackNumber max stack's number
     * @param stackSize max stack's size
     */
    Car(int maxStackSize);

    /**Returns the max number of carriages
     *
     * @return
     */
    int getNumberCarriages();

    /**Adds a luggage to the first carriage not full
     *
     * @param l luggage
     * @return whether it passed or failed
     */
    void addCarriage(Carriage carriage);

    /**Removes the next luggage from the farther carriage
     *
     * @return whether it passed or failed
     */
    Carriage popCarriage();

    /**Returns the list of carriages
     *
     * @return list of carriages
     */
    std::stack<Carriage> getCarriages();
};




#endif
