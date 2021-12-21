#include "Airport.h"

using namespace std;

Airport::Airport(string name,  Location* location) : TransitStop(name, "Airport", location), transitStops(BST<TransitStop>(TransitStop())) {
    iterator = transitStops.begin();
}


void Airport::getAllTransitStops(vector<TransitStop> &v) {
    for (auto it = transitStops.begin(); it != transitStops.end(); it++) {
        v.push_back((*it));
    }
}

void Airport::getAllTransitStopsInRange(double range, vector<TransitStop> &v) {
    for (auto it = transitStops.begin(); it != transitStops.end(); it++) {
        if ((*it).getLocation()->getDistanceToLoc(*location) <= range)
            v.push_back((*it));
    }
}

void Airport::clearTransitStop() {
    transitStops.makeEmpty();
}

void Airport::addTransitStop(TransitStop transitStop) {
    transitStop.setAirport(this);
    transitStops.insert(transitStop);
    clearIterator();
}

void Airport::getTransitStopsOfTypeInRange(double range, string type, vector<TransitStop> &v) {
    for (auto it = transitStops.begin(); it != transitStops.end(); it++) {
        if ((*it).getLocation()->getDistanceToLoc(*location) <= range && (*it).getTransportType() == type)
            v.push_back((*it));
    }
}

TransitStop Airport::getClosestTransitStop() {
    if( transitStops.isEmpty() )
        throw (InvalidAirportRequest("Empty BST"));
    return transitStops.findMin();
}

TransitStop Airport::getClosestTransitStopOfType(string type) {
    if( transitStops.isEmpty() )
        throw (InvalidAirportRequest("Empty BST"));

    for (auto it = transitStops.begin(); it != transitStops.end(); it++) {
        if ((*it).getTransportType() == type) {
            return (*it);
        }
    }

    throw InvalidAirportRequest("Not found element of type");
}

void Airport::clearIterator() {
    iterator = transitStops.begin();
}

TransitStop Airport::getNextOfType(std::string type) {
    while ((*iterator).getTransportType() != type) {
        iterator++;
    }
    return (*iterator);
}

TransitStop Airport::getNext() {
    iterator++;
    return (*iterator);
}

TransitStop Airport::getCurrent() {
    return (*iterator);
}
