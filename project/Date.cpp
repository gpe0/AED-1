#include <chrono>
#include <iostream>
#include "Date.h"

using namespace std;

Date::Date() {
    auto now = std::chrono::system_clock::now();
    time_t nowC = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&nowC);

    year = 1900 + parts->tm_year;
    month = 1 + parts->tm_mon;
    day = parts->tm_mday;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}
