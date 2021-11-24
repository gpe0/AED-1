#ifndef PROJECT_FLIGHT_H
#define PROJECT_FLIGHT_H

#include <string>
#include "Date.h"

class Flight {
private:
    int num;
    Date date;
    float duration;
    std::string origin;
    std::string destination;
};


#endif
