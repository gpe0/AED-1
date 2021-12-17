#ifndef CAR_H
#define CAR_H

#include <list>
#include "Carriage.h"

class Car {
private:
    const int CARRIAGES;
    list<Carriage> carriages;
public:

    /**Initializes a car with the max number of carriages.
     *  The max number of stacks and the max stack size is carriage information
     * @param carriages max carriages' number
     * @param stackNumber max stack's number
     * @param stackSize max stack's size
     */
    Car(int carriages, int stackNumber, int stackSize);

    /**Returns the max number of carriages
     *
     * @return
     */
    int getMaxCarriages();

    /**Adds a luggage to the first carriage not full
     *
     * @param l luggage
     * @return whether it passed or failed
     */
    bool addLuggage(Luggage* l);

    /**Removes the next luggage from the farther carriage
     *
     * @return whether it passed or failed
     */
    bool removeNextLuggage();

    /**Returns the list of carriages
     *
     * @return list of carriages
     */
    list<Carriage> getCarriages();
};




#endif
