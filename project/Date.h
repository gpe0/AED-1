#ifndef PROJECT_DATE_H
#define PROJECT_DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:

    /** Initializes the current date (testing not implemented yet)
     *
     */
    Date();

    /** Initializes a specified date (validation and testing not implemented yet)
     * There is a possibility of building another construction with strings for months for convenience
     *
     * @param day specified day (must be 1 or higher and 31/30/29/28 or lower, depending on month and year)
     * @param month specified month (between 1 and 12)
     * @param year specified year (no restrictions applied)
     */
    Date(int day, int month, int year);

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};


#endif
