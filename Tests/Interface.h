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

    /**Reads a csv file and  instantiate a list of transitStops
     *
     * @param file name of the file (must end with .csv)
     * @param transitStops passed by reference transit Stops's list
     */
    static void readTransitStops(std::string file, std::list<TransitStop>& transitStops);

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

    /**Creats a map with the airports and routes for a given simulation (saved in ./../files/output/)
     *
     * @param html HTML
     */
    static void exportMap(std::string html);

public:

    /**Reads a csv file and instantiate a list of Planes with the flights from the a given csv
     *
     * @param file name of the planes' file (must end with .csv)
     * @param planes passed by reference plane's list
     * @param flights name of the flights' file (must end with .csv)
     */
    static void readPlanes(std::string file, std::list<Plane>& planes, std::string flights);

    /**Reads a csv file and instantiate a list of Airports with the transitStops nearby from the a given csv
     *
     * @param file name of the airports' file (must end with .csv)
     * @param airports passed by reference airport's list
     * @param transitStops name of the transit stops' file (must end with .csv)
     */
    static void readAirports(std::string file, std::list<Airport>& airports, std::string transitStops);

    /**Creates a menu to interact with the user
     *
     */
    static int menu(int argc, char* argv[]);
};


#endif
