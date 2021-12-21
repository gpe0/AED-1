#ifndef CARRIAGE_H
#define CARRIAGE_H

#include <stack>
#include "Luggage.h"
#include <list>
using namespace std;

class Carriage {
private:
    int stackNumber;
    int stackSize;
    std::list<stack<Luggage*>> luggage;
    double capacity, availableCapacity;
public:

    /**Initializes the carriage with the max number of stacks and stack size
     *
     * @param stackNumber max stack number
     * @param stackSize max stack size
     * @param capacity carriage's capacity
     */
    Carriage(int stackNumber, int stackSize, double capacity);

    /**Returns the max stack number
    *
    * @return max stack number
    */
    int getMaxStackNumber();

    /**Returns the max stack size
     *
     * @return max stack size
     */
    int getMaxStackSize();

    /**Tries to add a luggage to the carriage
     *
     * @param l luggage
     * @return whether it passed or failed
     */
    bool addLuggage(Luggage * l);

    /**Tries to remove the next luggage from the carriage
     *
     * @return whether it passed or failed
     */
    bool removeNextLuggage();

    /**Return's all the luggages in the carriage
     *
     * @return luggages
     */
    list<stack<Luggage *>> getLuggage();

    /**Returns the carriage's efficiency (based on available capacity and total capacity)
     *
     * @return efficiency
     */
    double getEfficiency();

    /**Returns the carriage's available capacity
     *
     * @return available capacity
     */
    double getAvailableCapacity();

    /**Returns the carriage's capacity
     *
     * @return capacity
     */
    double getCapacity();

    Carriage& operator=(const Carriage &right);

    bool operator==(const Carriage & right);
};


#endif
