#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}
