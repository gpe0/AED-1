#ifndef AED_1_LOCATION_H
#define AED_1_LOCATION_H

#include <string>
#include <bits/stdc++.h>

class Location {
private:
    double latitude, longitude;
public:
    Location(double latitude, double longitude);
    float getDistanceToInKM(Location& location2);
    double getLatitude();
    double getLongitude();

    class InvalidLocation {
    private:
        std::string msg;
    public:
        InvalidLocation(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};


#endif //AED_1_LOCATION_H
