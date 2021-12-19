#ifndef CARRIAGE_H
#define CARRIAGE_H

#include <stack>
#include "Luggage.h"
#include <list>
using namespace std;

class Carriage {
private:
    std::list<stack<Luggage*>> luggages;
    double capacity, availableCapacity, width, heigth, availableHeigth;
public:

    /**Initializes the carriage with the max number of stacks and stack size
     *
     * @param stackNumber max stack number
     * @param stackSize max stack size
     */
    Carriage(double capacity, double width, double heigth);

    /**Returns the max stack number
     *
     * @return max stack number
     */
    int getStackLength();

    std::stack<Luggage*> getStackNum(int index);

    void addLugToStackNum(int index, Luggage* luggage);

    void addNewStack(Luggage* luggage);

    list<stack<Luggage *>> getLuggages();

    double getEfficiency();

    Carriage& operator=(const Carriage& right);

    double getAvailableCapacity();
    double getWidth();
    double getHeigth();
    double getCapacity();
};


#endif
