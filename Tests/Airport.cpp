#include "Airport.h"

Airport::Airport(std::string name,  Location* location) : TransitStop(name, "Airport", location), transitStops(BST<TransitStop>(TransitStop())) {
}

bool Airport::transitStopIncluded(TransitStop transitStop) {


    if(transitStops.find(transitStop) < TransitStop() and TransitStop() < transitStops.find(transitStop)){
        return false;
    }
    return true;
}

void Airport::clearTransitStop() {
    transitStops.makeEmpty();
}

TransitStop Airport::getClosestTransitStop() {
    if( transitStops.isEmpty() )
        throw (InvalidAirportRequest("Empty BST"));
    return transitStops.findMin();
}


