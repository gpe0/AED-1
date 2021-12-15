#ifndef AED_1_LOCATION_H
#define AED_1_LOCATION_H

#include <string>

class Location {
private:
    float latitude, longitude;
public:
    Location(float latitude, float longitude);

    class InvalidLocation {
    private:
        std::string msg;
    public:
        InvalidLocation(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};


#endif //AED_1_LOCATION_H
