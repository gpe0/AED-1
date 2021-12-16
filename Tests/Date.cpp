#include <chrono>
#include <iostream>
#include "Date.h"

using namespace std;

Date::Date() : ConstTimeGen(getCurrentDate()[0], getCurrentDate()[1], getCurrentDate()[2]) {
    validTime = true;
}

Date::Date(int day, int month, int year) : ConstTimeGen(day, month, year) {
    if (day > 31 or day < 1 or month < 1 or month > 12){
        validTime = false;
    }
    else if (month == 2){
        if (isLeapYear(year))
            validTime = (day <= 29);
        else
            validTime = (day <= 28);
    }
    else if (month == 4 or month == 6 or month == 9 or month == 11)
        validTime = (day <= 30);
    else
        validTime = (day <= 31);
}

std::ostream& operator<<(std::ostream& os, Date& date) {
    os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return os;
}

bool Date::isValid() const {
    return validTime;
}

int Date::getDay() const {
    if (not validTime)
        throw (InvalidTime("Invalid Date"));
    return LEFT;
}

int Date::getMonth() const {
    if (not validTime)
        throw (InvalidTime("Invalid Date"));
    return MID;
}

int Date::getYear() const {
    if (not validTime)
        throw (InvalidTime("Invalid Date"));
    return RIGHT;
}

std::vector<int> Date::getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    time_t nowC = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&nowC);
    vector<int> result;
    result.push_back(parts->tm_mday);
    result.push_back(1 + parts->tm_mon);
    result.push_back(1900 + parts->tm_year);
    return result;
}

bool Date::isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            return false;
        }
        return true;
    }
    return false;
}

