#include <chrono>
#include <iostream>
#include "Date.h"

using namespace std;

Date::Date() : DAY(getCurrentDate()[0]), MONTH(getCurrentDate()[1]), YEAR(getCurrentDate()[2]) {
    validDate = true;
}

Date::Date(int day, int month, int year) : DAY(day), MONTH(month), YEAR(year) {
    validDate = true;
    if (day > 31 or day < 1 or month < 1 or month > 12){
        validDate = false;
    }
    else if (month == 2){
        if (isLeapYear(year))
            validDate = (day <= 29);
        else
            validDate = (day <= 28);
    }
    else if (month == 4 or month == 6 or month == 9 or month == 11)
        validDate = (day <= 30);
    else
        validDate = (day <= 31);
}

std::ostream& operator<<(std::ostream& os, Date& date) {
    os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return os;
}

bool Date::isValid() {
    return validDate;
}

int Date::getDay() {
    if (not validDate)
        throw (runtime_error("Invalid Date"));
    return DAY;
}

int Date::getMonth() {
    if (not validDate)
        throw (runtime_error("Invalid Date"));
    return MONTH;
}

int Date::getYear() {
    if (not validDate)
        throw (runtime_error("Invalid Date"));
    return YEAR;
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

