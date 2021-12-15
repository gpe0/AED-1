#ifndef CARRIAGE_H
#define CARRIAGE_H

#include <stack>
#include "Luggage.h"

using namespace std;

class Carriage {
private:
    const int STACKNUMBER;
    const int STACKSIZE;
    stack<stack<Luggage>> luggages;

public:

    /**Initializes the carriage with the max number of stacks and stack size
     *
     * @param stackNumber max stack number
     * @param stackSize max stack size
     */
    Carriage(int stackNumber, int stackSize);

    /**Returns the max stack number
     *
     * @return max stack number
     */
    int getMaxStackNumber();

    /**Returns the max stack size
     *
     * @return max stack size
     */
    int getMaxSTackSize();

    /**Tries to add a luggage to the carriage
     *
     * @param l luggage
     * @return whether it passed or failed
     */
    bool addLuggage(Luggage l);

    /**Tries to remove the next luggage from the carriage
     *
     * @return whether it passed or failed
     */
    bool removeNextLuggage();

    /**Return's all the luggages in the carriage
     *
     * @return luggages
     */
    stack<stack<Luggage>> getLuggages();
};


#endif
