#include "Flight.h"

Flight::Flight(int num, Date* date, Duration* duration, std::string origin, std::string destination) : date(date), duration(duration) {
    this->num = num;
    this->origin = origin;
    this->destination = destination;
    availableSeats = -1;
}

int Flight::getNum() const{
    return num;
}

int Flight::getAvailableSeats() const{
    return availableSeats;
}

Date Flight::getDate() const{
    return *date;
}

Duration Flight::getDuration() const{
    return *duration;
}

std::string Flight::getOrigin() const{
    return origin;
}

std::string Flight::getDestination() const{
    return destination;
}

void Flight::setNum(int num) {
    this->num = num;
}

void Flight::setAvailableSeats(int availableSeat) {
    this->availableSeats = availableSeat;
}

void Flight::setDate(Date date) {
    this->date = &date;
}

void Flight::setDuration(Duration duration) {
    this->duration = &duration;
}

void Flight::setOrigin(std::string origin) {
    this->origin = origin;
}

void Flight::setDestination(std::string destination) {
    this->destination = destination;
}
