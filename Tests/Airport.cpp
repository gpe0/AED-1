//
// Created by guilh on 12/17/2021.
//

#include "Airport.h"

Airport::Airport(std::string name,  Location* location) : TransitStop(name, "Airport", location), transitStops(BST<TransitStop>(TransitStop())) {
}

bool Airport::transitStopIncluded(TransitStop transitStop) {
    //if(transitStops.find(transitStop) != NULL and transitStops.find(transitStop) != NULL){
    //    return true;
    //}
    //return false;
}

void Airport::clearTransitStop() {
    transitStops.makeEmpty();
}

TransitStop &Airport::getClosestTransitStop() {
    //if(transitStops.isEmpty())
    //    throw (InvalidAirportRequest("Empty BST"));
    //return (*transitStops.findMin());
}


