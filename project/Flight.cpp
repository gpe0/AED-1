#include "Flight.h"

Flight::Flight(int num, Date date, float duration, std::string origin, std::string destination) {
    this->num = num;
    this->date = date;
    this->duration = duration;
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

float Flight::getDuration() {
    return duration;
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

void Flight::setDate(Date date) {
    this->date = date;
}

void Flight::setDuration(float duration) {
    this->duration = duration;
}

void Flight::setOrigin(std::string origin) {
    this->origin = origin;
}

void Flight::setDestination(std::string destination) {
    this->destination = destination;
}