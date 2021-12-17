//
// Created by guilh on 12/17/2021.
//

#ifndef AED_1_AIRPORT_H
#define AED_1_AIRPORT_H

#include "TransitStop.h"
#include "Bst.h"

#include <string>
#include <vector>

class Airport : public TransitStop{
private:
    BST<TransitStop*> transitStops;
public:
    Airport(std::string name, Location &location);

    TransitStop& getClosestTransitStop();
    TransitStop& getClosestTransitStopOfType(std::string type);

    //Iteration through whole tree
    std::vector<TransitStop*> getAllTransitStops();
    std::vector<TransitStop*> getAllTransitStopsInRange(double range);
    std::vector<TransitStop*> getTransitStopsOfTypeInRange(double range);
    void clearIterator();
    TransitStop& getNextOfType(std::string type);
    TransitStop& getNext();

    bool transitStopIncluded(TransitStop& transitStop);
    void addTransitStop();
    void clearTransitStop();

    class InvalidAirportRequest {
    private:
        std::string msg;
    public:
        InvalidAirportRequest(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};


#endif //AED_1_AIRPORT_H
