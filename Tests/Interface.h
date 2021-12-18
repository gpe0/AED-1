#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <list>
#include "Flight.h"
#include "Plane.h"
#include "Passenger.h"
#include "Airport.h"

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

    /**Export the data to a csv file
     *
     * @param fileName file name
     * @param planes list of planes
     * @param passengers list of passengers
     */
    static void exportCsv(std::string fileName, std::list<Plane>& planes, std::list<Passenger>& passengers, Airport aO, Airport aD);

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
    static int menu(int argc, char* argv[]);
};


#endif
