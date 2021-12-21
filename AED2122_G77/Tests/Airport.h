#ifndef AIRPORT_H
#define AIRPORT_H

#include "TransitStop.h"
#include "Bst.h"

#include <string>
#include <vector>

class Airport : public TransitStop {
private:
    BST<TransitStop> transitStops;
    iteratorBST<TransitStop> iterator;
public:

    /**Initializes an airport with a name and a location
     *
     * @param name name
     * @param location location
     */
    Airport(std::string name, Location* location);

    /**Returns the closest stop to the airport
     *
     * @return closest transit stop
     */
    TransitStop getClosestTransitStop();

    /**Returns the closest stop of a given type to the airport
     *
     * @param type transit stop type
     * @return closest transit stop of the given type
     */
    TransitStop getClosestTransitStopOfType(std::string type);

    /**Returns all the transit stops near an airport
     *
     * @param v vector which will have the returned stops
     */
    void getAllTransitStops(std::vector<TransitStop>& v);

    /**Returns all the stops within the given range
     *
     * @param range range
     * @param v vector which will have the returned stops
     */
    void getAllTransitStopsInRange(double range, std::vector<TransitStop>& v);

    /**Returns all the stops within the given range of a given type
     *
     * @param range range
     * @param type type
     * @param v vector which will have the returned stops
     */
    void getTransitStopsOfTypeInRange(double range, std::string type, std::vector<TransitStop>& v);

    /**Clears the iterator
     *
     */
    void clearIterator();

    /**Go to the next transit stop in the tree of a given type
     *
     * @param type type
     * @return next transit stop in the tree
     */
    TransitStop getNextOfType(std::string type);

    /**Go to the next transit stop in the tree
     *
     * @return next transit stop in the tree
     */
    TransitStop getNext();

    /**Returns the current transit stop in the iterator
     *
     * @return transit stop in the iterator
     */
    TransitStop getCurrent();

    /**Inserts a transit stop in the tree
     *
     * @param transitStop transit stop
     */
    void addTransitStop(TransitStop transitStop);

    /**Clears the tree
     *
     */
    void clearTransitStop();

    class InvalidAirportRequest {
    private:
        std::string msg;
    public:
        InvalidAirportRequest(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};


#endif
