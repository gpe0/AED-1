#include <cmath>
#include "Location.h"


using namespace std;
Location::Location(double latitude, double longitude) {
    if ( !(-180 <= latitude and latitude <= 180 and -180 <= longitude and longitude <= 180) ){
        throw (Location::InvalidLocation("Invalid Location"));
    }
    this->latitude = latitude;
    this->longitude = longitude;
}

float Location::getDistanceToLoc(Location &location2) {
    double earthR = 6371;
    double lat1 = latitude * M_PI / 180;
    double lat2 = location2.latitude * M_PI / 180;
    double difLat = (latitude - location2.latitude) * M_PI / 180;
    double difLon = (longitude - location2.longitude) * M_PI / 180;
    double a = sin(difLat / 2) * sin(difLat / 2) + cos(lat1) * cos(lat2) * sin(difLon / 2) * sin(difLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = earthR * c;
    return d;
}

double Location::getLatitude() {
    return latitude;
}

double Location::getLongitude() {
    return longitude;
}
