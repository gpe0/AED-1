#include "Flight.h"

Flight::Flight(int num, Date date, Duration duration, std::string origin, std::string destination) : date(date), DURATION(duration) {
    this->num = num;
    this->origin = origin;
    this->destination = destination;
    availableSeats = -1;
}

int Flight::getNum() {
    return num;
}

int Flight::getAvailableSeats() {
    return availableSeats;
}

Date Flight::getDate() {
    return date;
}

Duration Flight::getDuration() {
    return DURATION;
}

std::string Flight::getOrigin() {
    return origin;
}

std::string Flight::getDestination() {
    return destination;
}

void Flight::setNum(int num) {
    this->num = num;
}

void Flight::setAvailableSeats(int availableSeat) {
    this->availableSeats = availableSeat;
}

void Flight::setOrigin(std::string origin) {
    this->origin = origin;
}

void Flight::setDestination(std::string destination) {
    this->destination = destination;
}
