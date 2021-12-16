#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <list>
#include "Flight.h"

class Interface {
public:

    /**Reads a csv file and  instantiate a list of Flights
     *
     * @param file name of the file (must end with .csv)
     * @param flights passed by reference flight's list
     */
    static void readFlights(std::string file, std::list<Flight>& flights);
};


#endif
