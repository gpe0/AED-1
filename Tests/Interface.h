#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <list>
#include "Flight.h"
#include "Plane.h"

class Interface {
private:
    /**Reads a csv file and  instantiate a list of Flights
     *
     * @param file name of the file (must end with .csv)
     * @param flights passed by reference flight's list
     */
    static void readFlights(std::string file, std::list<Flight>& flights);

    /**Display the menu (in terminal)
     *
     */
    static void displayMenu();

public:

    /**Reads a csv file and  instantiate a list of Planes with the flights from the a given csv
     *
     * @param file name of the planes' file (must end with .csv)
     * @param planes passed by reference plane's list
     * @param flights name of the flights' file (must end with .csv)
     */
    static void readPlanes(std::string file, std::list<Plane>& planes, std::string flights);

    /**Simple menu to interact with the user
     *
     */
    static void menu();
};


#endif
