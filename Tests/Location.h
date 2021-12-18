#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <bits/stdc++.h>

class Location {
private:
    double latitude, longitude;
public:

    /**Initializes a location with a latitude and a longitude
     *
     * @param latitude latitude
     * @param longitude longitude
     */
    Location(double latitude, double longitude);

    /**Returns the distance to another location in kilometers
     *
     * @param location2 location to be compared with
     * @return distance (Km)
     */
    float getDistanceToLoc(Location& location2);

    /**Returns the location's latitude
     *
     * @return latitude
     */
    double getLatitude();

    /**Returns the location's longitude
     *
     * @return longitude
     */
    double getLongitude();

    class InvalidLocation {
    private:
        std::string msg;
    public:
        InvalidLocation(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};


#endif
