#ifndef PROJECT_PLANE_H
#define PROJECT_PLANE_H

#include <string>
#include <list>
#include <queue>
#include "Flight.h"
#include "Service.h"

class Plane {

private:
    std::string const LICENSEPLATE;
    std::string const TYPE;
    int const CAPACITY;
    std::list<Flight> flights;
    std::queue<Service> services;
    std::queue<Service> finishedServices;

public:
    /** Initializes a plane (already finished services queue starts empty), and associates the number of empty seats to the flights
     *(validation and testing not implemented yet)
     *
     * @param licensePlate Plane's license plate (constant)
     * @param type Plane's type (constant)
     * @param capacity Plane's passenger capacity (constant)
     * @param flights Plane's flights (doesn't need to be provided, its default values is an empty list)
     * @param services Services to do in a plane (doesn't need to be provided, its default value is an empty queue)
     */
    Plane(std::string licensePlate, std::string type, int capacity, std::list<Flight> flights = std::list<Flight>(), std::queue<Service> services = std::queue<Service>());

    /** Returns the plane's license plate
     *
     * @return license plate
     */
    std::string getLicensePlate() const;

    /**Returns the plane's type
     *
     * @return  type
     */
    std::string getType() const;

    /** Returns the plane's passenger capacity
     *
     * @return capacity
     */
    int getCapacity() const;

    /** Returns the plane's flight list
     *
     * @return flight list
     */
    std::list<Flight> getFlights() const;

    /**Returns the queue of services yet to be completed
     *
     * @return not yet completed services queue
     */
    std::queue<Service> getServices() const;

    /**Returns a queue with already finished services
     *
     * @return finished services queue
     */
    std::queue<Service> getFinishedServices() const;
    /** Sets a flight list for the plane
     *
     * @param flights flight list
     */
     void setFlights(std::list<Flight> flights);

     void addFlight(Flight &flight, int c);


    /**Adds to the file queue (still not completed) a new service
     *
     * @param service service
     */
    void addService(Service service);

    class InvalidPlane {
    private:
        std::string msg;
    public:
        InvalidPlane(std::string msg) {this->msg = msg;};
        std::string what() {return msg;};
    };

};

#endif