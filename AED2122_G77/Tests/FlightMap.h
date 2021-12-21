#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H

#include "Airport.h"
#include "Location.h"

#include <iostream>
#include <fstream>
#include <string>

class FlightMap {
private:
    std::string html;
public:
    FlightMap();
    void addMainAirport(Airport& airport);
    void addRoute(Location& location1, Location& location2);
    void addTransitStop(TransitStop& transitStop);
    std::string getHTML();
    class InvalidMap {
    private:
        std::string msg;
    public:
        InvalidMap(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};
#endif
