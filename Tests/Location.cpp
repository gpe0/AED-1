//
// Created by guilh on 12/15/2021.
//

#include "Location.h"

using namespace std;
Location::Location(float latitude, float longitude) {
    if ( !(-180 <= latitude and latitude <= 180 and -180 <= longitude and longitude <= 180) ){
        throw (Location::InvalidLocation("Invalid Location"));
    }
    this->latitude = latitude;
    this->longitude = longitude;
}
