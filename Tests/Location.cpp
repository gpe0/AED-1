//
// Created by guilh on 12/15/2021.
//

#include "Location.h"

using namespace std;
Location::Location(double latitude, double longitude) {
    if ( !(-180 <= latitude and latitude <= 180 and -180 <= longitude and longitude <= 180) ){
        throw (Location::InvalidLocation("Invalid Location"));
    }
    this->latitude = latitude;
    this->longitude = longitude;
}

float Location::getDistanceToInKM(Location &location2) {
    double lat1Rad = latitude * 6371;
    double long1Rad = longitude * 6371;
    double lat2Rad = location2.latitude * 6371;
    double long2Rad = location2.longitude * 6371;
    double result = pow(sin((lat2Rad - lat1Rad) / 2), 2) +
                      cos(lat1Rad) * cos(lat2Rad) *
                      pow(sin((long2Rad - long1Rad) / 2), 2);
    return 2*asin(sqrt(result));

}

double Location::getLatitude() {
    return latitude;
}

double Location::getLongitude() {
    return longitude;
}
